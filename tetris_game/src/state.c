#include "state.h"

// Converts coordinate on board to bit position and flip the bit in the gamestate
void toggle_bit(GameState_t *state, coord_t bit_coord)
{
    // int norm_line = line - BOARD_TOP_WALL_COORD;
    // int norm_col = (col - BOARD_LEFT_WALL_COORD) / 2;
    state->bitboard[bit_coord.y].value ^= (1 << bit_coord.x);
    return;
}

BOOL_t extract_bit(GameState_t *state, coord_t bit_coord)
{
    return (state->bitboard[bit_coord.y].value >> bit_coord.x) & 1;
}

void _printb(int line, int n)
{
    // Iterate through all 32 bits of a standard integer
    for (int i = 0; i <= GAME_BOARD_WIDTH - 1; i++)
    {
        int k = n >> i;
        // set_cursor(line + DEBUG_GAME_BOARD_Y_COORD, i + DEBUG_GAME_BOARD_X_COORD);
        if (k & 1)
            printf("1");
        else
            printf("0");
    }
    printf("\n");
}

void print_state_board(GameState_t *state)
{
    // set_cursor(DEBUG_GAME_BOARD_Y_COORD, DEBUG_GAME_BOARD_X_COORD);
    for (int i = 1; i <= GAME_BOARD_HEIGHT; i++)
    {
        _printb(i, state->bitboard[i - 1].value);
    }
}

/**
 * Should be helper function called in other move functions since it needs
 * to be called after each change is made to a tetromino's coords.
 */
void _update_bitboard_bits(GameState_t *state)
{
    // For redraws I only need to redraw first and last row
    // Clear old shape
    toggle_bit(state, state->active_piece.prev_coords.p1);
    set_cursor(state->active_piece.prev_coords.p1.y + RENDER_BOARD_ORIGIN_Y, (state->active_piece.prev_coords.p1.x * 2) + RENDER_BOARD_ORIGIN_X);
    state->active_piece.prev_coords.p1.x %2 == 0 ? printf("  \n") : printf(" .\n");
    toggle_bit(state, state->active_piece.prev_coords.p2);
    set_cursor(state->active_piece.prev_coords.p2.y + RENDER_BOARD_ORIGIN_Y, (state->active_piece.prev_coords.p2.x * 2) + RENDER_BOARD_ORIGIN_X);
    state->active_piece.prev_coords.p1.x %2 == 0 ? printf("  \n") : printf(" .\n");
    toggle_bit(state, state->active_piece.prev_coords.p3);
    set_cursor(state->active_piece.prev_coords.p3.y + RENDER_BOARD_ORIGIN_Y, (state->active_piece.prev_coords.p3.x * 2) + RENDER_BOARD_ORIGIN_X);
    state->active_piece.prev_coords.p1.x %2 == 0 ? printf("  \n") : printf(" .\n");
    toggle_bit(state, state->active_piece.prev_coords.p4);
    set_cursor(state->active_piece.prev_coords.p4.y + RENDER_BOARD_ORIGIN_Y, (state->active_piece.prev_coords.p4.x * 2) + RENDER_BOARD_ORIGIN_X);
    state->active_piece.prev_coords.p1.x %2 == 0 ? printf("  \n") : printf(" .\n");

    // Draw new shape
    toggle_bit(state, state->active_piece.coords.p1);
    set_cursor(state->active_piece.coords.p1.y + RENDER_BOARD_ORIGIN_Y, (state->active_piece.coords.p1.x * 2) + RENDER_BOARD_ORIGIN_X);
    printf(SHAPE);
    toggle_bit(state, state->active_piece.coords.p2);
    set_cursor(state->active_piece.coords.p2.y + RENDER_BOARD_ORIGIN_Y, (state->active_piece.coords.p2.x * 2) + RENDER_BOARD_ORIGIN_X);
    printf(SHAPE);
    toggle_bit(state, state->active_piece.coords.p3);
    set_cursor(state->active_piece.coords.p3.y + RENDER_BOARD_ORIGIN_Y, (state->active_piece.coords.p3.x * 2) + RENDER_BOARD_ORIGIN_X);
    printf(SHAPE);
    toggle_bit(state, state->active_piece.coords.p4);
    set_cursor(state->active_piece.coords.p4.y + RENDER_BOARD_ORIGIN_Y, (state->active_piece.coords.p4.x * 2) + RENDER_BOARD_ORIGIN_X);
    printf(SHAPE);
}