#include "render.h"
#include "terminal.h"
#include "input.h"
#include "state.h"

/**
 * Spawns a random tetromino template from the provided piece pool and draws it
 * as the new active piece.
 *
 * @param state Pointer to the game state receiving the new active piece.
 * @param pieces Array of piece templates used for spawning.
 * @param piece_count Number of entries available in `pieces`.
 */
static void spawn_random_piece(GameState_t *state, Tetromino_t pieces[], int piece_count)
{
    state->active_piece = pieces[rand() % piece_count];
    state->active_piece.prev_coords = state->active_piece.coords;
    draw_active_piece(state);
}

// TODO: Add collisions of pieces together (might need some sort of game/board state manager)
// TODO: Implement score tracking, timer, lines completed, and other game logic
// TODO: Implement next shape render on the left side of the game board
// TODO: I don't need to pass whole game state into each func, should pass sub struct in
/**
 * The main function initializes the Tetris game, clears the screen, and sets up the initial state.
 * It then enters an infinite loop to handle user input and render the game visuals.
 */
int main(int argc, char *argv[])
{
    int start_row = 5;
    int start_column = 25;
    long long start_time = get_current_time_ms();
    long long fall_time = 500;
    struct termios orig_t = set_raw_mode();
    srand(time(NULL));

    GameState_t gameState = {0}; // Clear out struct to all 0's (for array mainly)

    clear_screen();
    cursor_home();
    hide_cursor();

    setup_ui();

    // Make array of pieces to randomly choose from for spawn.
    Tetromino_t pieces[] = {{.type = O_SHAPE, .coords = {.p1 = {0, 0}, .p2 = {1, 0}, .p3 = {0, 1}, .p4 = {1, 1}}, .rotation_state = NORMAL, .prev_coords = {0}, .height = 2, .width = 1},
                            {.type = I_SHAPE, .coords = {.p1 = {GAME_BOARD_WIDTH / 2, 0}, .p2 = {GAME_BOARD_WIDTH / 2, 1}, .p3 = {GAME_BOARD_WIDTH / 2, 2}, .p4 = {GAME_BOARD_WIDTH / 2, 3}}, .rotation_state = NORMAL, .prev_coords = {0}, .height = 4, .width = 1},
                            {.type = S_SHAPE, .coords = {.p1 = {2, 0}, .p2 = {1, 0}, .p3 = {1, 1}, .p4 = {0, 1}}, .rotation_state = NORMAL, .prev_coords = {0}, .height = 2, .width = 3},
                            {.type = Z_SHAPE, .coords = {.p1 = {0, 0}, .p2 = {1, 0}, .p3 = {1, 1}, .p4 = {2, 1}}, .rotation_state = NORMAL, .prev_coords = {0}, .height = 2, .width = 3},
                            {.type = L_SHAPE, .coords = {.p1 = {0, 0}, .p2 = {0, 1}, .p3 = {0, 2}, .p4 = {1, 2}}, .rotation_state = NORMAL, .prev_coords = {0}, .height = 3, .width = 2},
                            {.type = J_SHAPE, .coords = {.p1 = {1, 0}, .p2 = {1, 1}, .p3 = {1, 2}, .p4 = {0, 2}}, .rotation_state = NORMAL, .prev_coords = {0}, .height = 3, .width = 2},
                            {.type = T_SHAPE, .coords = {.p1 = {0, 0}, .p2 = {1, 0}, .p3 = {2, 0}, .p4 = {1, 1}}, .rotation_state = NORMAL, .prev_coords = {0}, .height = 2, .width = 3}};
    gameState.active_piece = pieces[2]; // Choose random piece to start.
    gameState.active_piece.prev_coords = gameState.active_piece.coords;

    char input = 0;
    draw_active_piece(&gameState); // Initial update of state for adding shape to bitboard

    while (1) // Main game loop, press 'q' to quit
    {
        // clear_screen();
        // print_state_board(&gameState);

        // Listen for keypress
        if (keyboard_input())
        {
            if (read(STDIN_FILENO, &input, 1) > 0)
            {
                // listen for inputs (from keyboard or gamepad)
                if (input == 'q')
                {
                    // quit game
                    break;
                }
                else if (input == 'a')
                {
                    // move piece left
                    // printf("Left\n");
                    move_piece_left(&gameState);
                }
                else if (input == 'd')
                {
                    // move piece right
                    // printf("Right\n");
                    move_piece_right(&gameState);
                }
                else if (input == 's')
                {
                    // move piece down faster
                    // printf("Down\n");
                    if (move_piece_down(&gameState) == TRUE)
                    {
                        spawn_random_piece(&gameState, pieces, 7);
                    }
                }
                else if (input == 'w')
                {
                    // rotate piece
                    // printf("Rotate\n");
                    rotate_piece(&gameState);
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
            if (increase_gravity(&gameState) == TRUE)
            {
                spawn_random_piece(&gameState, pieces, 7);
            }
        }
    }

    show_cursor();
    clear_screen();
    reset_terminal(&orig_t);

    return 0;
}
