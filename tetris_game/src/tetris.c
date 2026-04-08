#include "draw.h"
#include "terminal.h"
#include "input.h"

//TODO: Add collisions of pieces together
//TODO: Fix the right wall boundary with piece width
//TODO: 

/**
 * The main function initializes the Tetris game, clears the screen, and sets up the initial state.
 * It then enters an infinite loop to handle user input and render the game visuals.
 */
int main(int argc, char *argv[])
{
    int curr_curser_line = 5;
    int curr_cursor_column = 25;
    long long start_time = get_current_time_ms();
    long long fall_time = 100;
    struct termios orig_t = set_raw_mode();

    clear_screen();
    cursor_home();
    show_cursor();

    set_cursor(curr_curser_line, curr_cursor_column);
    printf("FULL LINES: 0\n");
    set_cursor(curr_curser_line += 1, curr_cursor_column);
    printf("LEVEL: 0\n");
    set_cursor(curr_curser_line += 1, curr_cursor_column);
    printf("SCORE: 0\n");
    set_cursor(curr_curser_line += 1, curr_cursor_column);
    printf("TIME: 0:00\n");

    curr_curser_line = 5;
    curr_cursor_column = 50;
    set_cursor(curr_curser_line, curr_cursor_column);
    for (int i = 0; i < BOARD_HEIGHT; i++)
    {
        printf("<! . . . . . . . . . .!>\n");
        set_cursor(curr_curser_line += 1, curr_cursor_column);
    }
    set_cursor(BOARD_HEIGHT + 5, curr_cursor_column);
    printf("<!********************!>\n");
    set_cursor(BOARD_HEIGHT + 6, curr_cursor_column);
    printf("  \\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\n");

    hide_cursor();
    // drawShapesTest();

    Tetromino_t active_piece = {.type = L_SHAPE, .coords = (coords_t){.x = SHAPE_SPAWN_X, .y = SHAPE_SPAWN_Y}, .height = 2, .width = 2};
    char input = 0;
    int frameCount = 0;
    while (1) // Main game loop, press 'q' to quit
    {
        if (keyboard_input())
        {
            if (read(STDIN_FILENO, &input, 1) > 0)
            {
                // listen for inputs (from keyboard or gamepad)pe
                if (input == 'q')
                {
                    // quit game
                    break;
                }
                else if (input == 'a' && (active_piece.coords.x - active_piece.width) > BOARD_LEFT_WALL)
                {
                    // need to redraw old position of piece with blank spaces to "erase" it
                    clear_old_position(active_piece, HORIZONTAL);
                    // move piece left
                    active_piece.coords.x -= 2;
                }
                else if (input == 'd' && (active_piece.coords.x) <= (BOARD_RIGHT_WALL + active_piece.width))
                {
                    // move piece right
                    clear_old_position(active_piece, HORIZONTAL);
                    active_piece.coords.x += 2;
                }
                else if (input == 's' && active_piece.coords.y + (active_piece.height + 1) < BOARD_BOTTOM_WALL)
                {
                    // move piece down faster
                    clear_old_position(active_piece, HORIZONTAL);
                    active_piece.coords.y += 1;
                }
                else if (input == 'w')
                {
                    // rotate piece
                }
            }
        }
        else
        {
            input = 0; // No input
        }

        // Select shape to start with (randomizer will be implemented later)
        // drawT(active_piece.coords);
        if (active_piece.type == O_SHAPE)
            drawO(active_piece.coords);
        else if (active_piece.type == I_SHAPE)
            drawI(active_piece.coords);
        else if (active_piece.type == S_SHAPE)
            drawS(active_piece.coords);
        else if (active_piece.type == Z_SHAPE)
            drawZ(active_piece.coords);
        else if (active_piece.type == L_SHAPE)
            drawL(active_piece.coords);
        else if (active_piece.type == J_SHAPE)
            drawJ(active_piece.coords);
        else if (active_piece.type == T_SHAPE)
            drawT(active_piece.coords);

        printf("%d, %d\n", active_piece.coords.x, BOARD_RIGHT_WALL);

        if (active_piece.coords.y >= (BOARD_BOTTOM_WALL - active_piece.height)) // Piece has reached the bottom, generate new piece
        {
            active_piece.coords = (coords_t){.x = SHAPE_SPAWN_X, .y = SHAPE_SPAWN_Y};
            active_piece.type = rand() % 7;
            if (active_piece.type == I_SHAPE)
            {
                active_piece.height = 3;
                active_piece.width = 1;
            }
            else if (active_piece.type == O_SHAPE || active_piece.type == S_SHAPE || active_piece.type == Z_SHAPE || active_piece.type == T_SHAPE)
            {
                active_piece.height = 1;
                active_piece.width = 1;
            }
            else if (active_piece.type == J_SHAPE)
            {
                active_piece.height = 2;
                active_piece.width = 2;
            }
            else if (active_piece.type == L_SHAPE)
            {
                active_piece.height = 2;
                active_piece.width = 2;
            }
        }
        else if (get_current_time_ms() - start_time >= fall_time)
        {
            start_time = get_current_time_ms();
            active_piece.coords.y++; // Move piece down by incrementing the y coordinate
            // printf("%d, %d\n", active_piece.coords.y, BOARD_BOTTOM_WALL);

            // Move piece down every iteration of the loop
            // need to redraw old position of piece with blank spaces to "erase" it
            clear_old_position(active_piece, VERTICAL);
        }

        if (frameCount >= 100)
        {
            frameCount = 0;
        }
        usleep(10000); // Sleep for 10ms to control frame rate (100 FPS)
        frameCount++;
    }

    show_cursor();
    clear_screen();
    reset_terminal(&orig_t);

    return 0;
}