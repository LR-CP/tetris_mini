#include "draw.h"
#include "terminal.h"
#include "input.h"

// TODO: Add collisions of pieces together (might need some sort of game/board state manager)
// TODO: Implement score tracking, timer, lines completed, and other game logic

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

    GameState_t gameState = {0}; // Clear out struct to all 0's (for array mainly)

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
    for (int i = 1; i <= BOARD_HEIGHT; i++)
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

    // Make array of pieces to randomly choose from for spawn.
    // Width needed to be adjusted by factor of 2 since piece is 2 chars long, thats why borders weren't working before
    Tetromino_t pieces[] = {{.type = O_SHAPE, .coords = (coords_t){.x = SHAPE_SPAWN_X, .y = SHAPE_SPAWN_Y}, .height = 2, .width = 3},
                            {.type = I_SHAPE, .coords = (coords_t){.x = SHAPE_SPAWN_X, .y = SHAPE_SPAWN_Y}, .height = 4, .width = 1},
                            {.type = S_SHAPE, .coords = (coords_t){.x = SHAPE_SPAWN_X, .y = SHAPE_SPAWN_Y}, .height = 2, .width = 6},
                            {.type = Z_SHAPE, .coords = (coords_t){.x = SHAPE_SPAWN_X, .y = SHAPE_SPAWN_Y}, .height = 2, .width = 6},
                            {.type = L_SHAPE, .coords = (coords_t){.x = SHAPE_SPAWN_X, .y = SHAPE_SPAWN_Y}, .height = 3, .width = 4},
                            {.type = J_SHAPE, .coords = (coords_t){.x = SHAPE_SPAWN_X, .y = SHAPE_SPAWN_Y}, .height = 3, .width = 4},
                            {.type = T_SHAPE, .coords = (coords_t){.x = SHAPE_SPAWN_X, .y = SHAPE_SPAWN_Y}, .height = 2, .width = 6}};
    Tetromino_t active_piece = pieces[rand() % 7]; // Choose random piece to start.

    char input = 0;
    int frameCount = 0;
    while (1) // Main game loop, press 'q' to quit
    {
        // Render active piece
        switch (active_piece.type)
        {
        case O_SHAPE:
            drawO(active_piece.coords);
            break;
        case I_SHAPE:
            drawI(active_piece.coords);
            break;
        case S_SHAPE:
            drawS(active_piece.coords);
            break;
        case Z_SHAPE:
            drawZ(active_piece.coords);
            break;
        case L_SHAPE:
            drawL(active_piece.coords);
            break;
        case J_SHAPE:
            drawJ(active_piece.coords);
            break;
        case T_SHAPE:
            drawT(active_piece.coords);
            break;
        default:
            break;
        }

        // set_cursor(1,1);
        // printf("l = %d, c = %d\n", active_piece.coords.y, active_piece.coords.x);
        // set_cursor(2,1);
        // printf("BOARD_LEFT_WALL = %d, BOARD_RIGHT_WALL = %d\n", BOARD_LEFT_WALL, BOARD_RIGHT_WALL);

        // Check collisions
        if (active_piece.coords.y + active_piece.height > BOARD_BOTTOM_WALL)
        {
            // Update GameState
            gameState.board[active_piece.coords.y][active_piece.coords.x] = 1;
            active_piece = pieces[rand() % 7]; // Spawn new piece
        }
        else if (active_piece.coords.y + 1 == '[' || active_piece.coords.y + 1 == ']')
        {
            printf("coollision\n");
        }
        // else if (active_piece.coords.x - active_piece.width >= BOARD_RIGHT_WALL)
        // {
        //     // active_piece = pieces[rand() % 7]; // Spawn new piece
        //     active_piece.coords.x-=2;
        // }

        // Listen for keypress
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
                else if (input == 'a' && active_piece.coords.x > BOARD_LEFT_WALL) // Since all shapes builf from origin, no width needed to be added here
                {
                    // need to redraw old position of piece with blank spaces to "erase" it
                    clear_old_position(active_piece, HORIZONTAL);
                    // move piece left
                    active_piece.coords.x -= 2;
                }
                else if (input == 'd' && (active_piece.coords.x) <= (BOARD_RIGHT_WALL - active_piece.width))
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

        // Move the piece down 1 block per second (gravity)
        if (get_current_time_ms() - start_time >= fall_time)
        {
            start_time = get_current_time_ms();
            active_piece.coords.y++; // Move piece down by incrementing the y coordinate

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

        // Print gamestate
        set_cursor(5, 80);
        for (int i = 0; i < BOARD_WIDTH; i++)
        {
            for (int j = 0; j < BOARD_HEIGHT; j++)
            {
                set_cursor(5+j, 80+i);
                printf("%d", gameState.board[j][i]);
            }
            printf("\n");
        }
        printf("\n");
    }

    show_cursor();
    clear_screen();
    reset_terminal(&orig_t);

    return 0;
}