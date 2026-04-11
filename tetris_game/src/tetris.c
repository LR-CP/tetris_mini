#include "draw.h"
#include "terminal.h"
#include "input.h"
#include "game.h"

// TODO: Add collisions of pieces together (might need some sort of game/board state manager)
// TODO: Implement score tracking, timer, lines completed, and other game logic
// TODO: Implement next shape render on the left side of the game board

// BUG: Fix the vertical rendering of the shape in the bitboard and add lock for when to render or not

/**
 * The main function initializes the Tetris game, clears the screen, and sets up the initial state.
 * It then enters an infinite loop to handle user input and render the game visuals.
 */
int main(int argc, char *argv[])
{
    int start_row = 5;
    int start_column = 25;
    long long start_time = get_current_time_ms();
    long long fall_time = 100;
    struct termios orig_t = set_raw_mode();

    GameState_t gameState = {0}; // Clear out struct to all 0's (for array mainly)

    clear_screen();
    cursor_home();
    show_cursor();

    drawBoard(start_row, start_column);

    hide_cursor();
    // drawShapesTest();

    // Make array of pieces to randomly choose from for spawn.
    // Width needed to be adjusted by factor of 2 since piece is 2 chars long, thats why borders weren't working before
    Tetromino_t pieces[] = {{.type = O_SHAPE, .coords = (coords_t){.c = SHAPE_SPAWN_X, .l = SHAPE_SPAWN_Y}, .height = 2, .width = 3},
                            {.type = I_SHAPE, .coords = (coords_t){.c = SHAPE_SPAWN_X, .l = SHAPE_SPAWN_Y}, .height = 4, .width = 1},
                            {.type = S_SHAPE, .coords = (coords_t){.c = SHAPE_SPAWN_X, .l = SHAPE_SPAWN_Y}, .height = 2, .width = 6},
                            {.type = Z_SHAPE, .coords = (coords_t){.c = SHAPE_SPAWN_X, .l = SHAPE_SPAWN_Y}, .height = 2, .width = 6},
                            {.type = L_SHAPE, .coords = (coords_t){.c = SHAPE_SPAWN_X, .l = SHAPE_SPAWN_Y}, .height = 3, .width = 4},
                            {.type = J_SHAPE, .coords = (coords_t){.c = SHAPE_SPAWN_X, .l = SHAPE_SPAWN_Y}, .height = 3, .width = 4},
                            {.type = T_SHAPE, .coords = (coords_t){.c = SHAPE_SPAWN_X, .l = SHAPE_SPAWN_Y}, .height = 2, .width = 6}};
    Tetromino_t active_piece = pieces[1]; // Choose random piece to start.

    char input = 0;
    int frameCount = 0;
    BOOL_t rendered = FALSE;

    while (1) // Main game loop, press 'q' to quit
    {
        // Render active piece
        if (rendered == FALSE)
        {
            switch (active_piece.type)
            {
            case O_SHAPE:
                renderO(&gameState, active_piece.coords);
                break;
            case I_SHAPE:
                renderI(&gameState, active_piece.coords);
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
            rendered = TRUE;
        }

        print_state_board(&gameState);

        // Check collisions
        if (active_piece.coords.l + active_piece.height > BOARD_BOTTOM_WALL_COORD)
        {
            active_piece = pieces[1]; // Spawn new piece
            rendered = FALSE; // new piece to be rendered
        }
        
        // Listen for keypress
        if (keyboard_input())
        {
            if (read(STDIN_FILENO, &input, 1) > 0)
            {
                rendered = 0;
                // listen for inputs (from keyboard or gamepad)pe
                if (input == 'q')
                {
                    // quit game
                    break;
                }
                else if (input == 'a' && active_piece.coords.c > BOARD_LEFT_WALL_COORD) // Since all shapes builf from origin, no width needed to be added here
                {
                    // need to redraw old position of piece with blank spaces to "erase" it
                    clear_old_position(&gameState, active_piece, HORIZONTAL);
                    // move piece left
                    active_piece.coords.c -= 2;
                    rendered = FALSE;
                }
                else if (input == 'd' && (active_piece.coords.c) <= (BOARD_RIGHT_WALL_COORD - active_piece.width))
                {
                    // move piece right
                    clear_old_position(&gameState, active_piece, HORIZONTAL);
                    active_piece.coords.c += 2;
                    rendered = FALSE;
                }
                else if (input == 's' && active_piece.coords.l + (active_piece.height + 1) < BOARD_BOTTOM_WALL_COORD)
                {
                    // move piece down faster
                    clear_old_position(&gameState, active_piece, VERTICAL);
                    active_piece.coords.l += 1;
                    rendered = FALSE;
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
            // active_piece.coords.l++; // Move piece down by incrementing the l coordinate

            // Move piece down every iteration of the loop
            // need to redraw old position of piece with blank spaces to "erase" it
            // rendered = 0;
            clear_old_position(&gameState, active_piece, VERTICAL);
            // rendered = FALSE;
            // rendered = 1;
        }
    }

    show_cursor();
    clear_screen();
    reset_terminal(&orig_t);

    return 0;
}