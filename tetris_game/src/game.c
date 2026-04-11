#include "game.h"

// Flip the bit in the gamestate represented by the coords of a shape
void toggle_bit(GameState_t *state, int line, int col)
{
    int norm_line = line - 5;      // 5 is BOARD_TOP_WALL_COORD
    int norm_col = (col - 52) / 2; // 52 is BOARD_LEFT_WALL_COORD
    state->bitboard[norm_line].value ^= (1 << norm_col);
    return;
}

void printb(int line, int n)
{
    // Iterate through all 32 bits of a standard integer
    for (int i = GAME_BOARD_WIDTH - 1; i >= 0; i--)
    {
        int k = n >> i;
        set_cursor(line + DEBUG_GAME_BOARD_Y_COORD, i + DEBUG_GAME_BOARD_X_COORD);
        if (k & 1)
            printf("1");
        else
            printf("0");
    }
    printf("\n");
}

void print_state_board(GameState_t *state)
{
    set_cursor(DEBUG_GAME_BOARD_Y_COORD, DEBUG_GAME_BOARD_X_COORD);
    for (int i = 0; i < GAME_BOARD_HEIGHT; i++)
    {
        printb(i, state->bitboard[i].value);
    }
}

void updateBoard(GameState_t *state)
{
    if (state->active_piece.type == O_SHAPE)
    {
        toggle_bit(state, state->active_piece.coords.l, state->active_piece.coords.c);
        toggle_bit(state, state->active_piece.coords.l, state->active_piece.coords.c + 2);
        toggle_bit(state, state->active_piece.coords.l + 1, state->active_piece.coords.c);
        toggle_bit(state, state->active_piece.coords.l + 1, state->active_piece.coords.c + 2);
    }
    else if (state->active_piece.type == I_SHAPE)
    {
        toggle_bit(state, state->active_piece.coords.l, state->active_piece.coords.c);
        toggle_bit(state, state->active_piece.coords.l + 1, state->active_piece.coords.c);
        toggle_bit(state, state->active_piece.coords.l + 2, state->active_piece.coords.c);
        toggle_bit(state, state->active_piece.coords.l + 3, state->active_piece.coords.c);
    }
    else if (state->active_piece.type == S_SHAPE)
    {
        toggle_bit(state, state->active_piece.coords.l, state->active_piece.coords.c + 2);
        toggle_bit(state, state->active_piece.coords.l, state->active_piece.coords.c + 4);
        toggle_bit(state, state->active_piece.coords.l + 1, state->active_piece.coords.c);
        toggle_bit(state, state->active_piece.coords.l + 1, state->active_piece.coords.c + 2);
    }
    else if (state->active_piece.type == Z_SHAPE)
    {
        toggle_bit(state, state->active_piece.coords.l, state->active_piece.coords.c);
        toggle_bit(state, state->active_piece.coords.l, state->active_piece.coords.c + 2);
        toggle_bit(state, state->active_piece.coords.l + 1, state->active_piece.coords.c + 2);
        toggle_bit(state, state->active_piece.coords.l + 1, state->active_piece.coords.c + 4);
    }
    else if (state->active_piece.type == L_SHAPE)
    {
        toggle_bit(state, state->active_piece.coords.l, state->active_piece.coords.c);
        toggle_bit(state, state->active_piece.coords.l + 1, state->active_piece.coords.c);
        toggle_bit(state, state->active_piece.coords.l + 2, state->active_piece.coords.c);
        toggle_bit(state, state->active_piece.coords.l + 2, state->active_piece.coords.c + 2);
    }
    else if (state->active_piece.type == J_SHAPE)
    {
        toggle_bit(state, state->active_piece.coords.l, state->active_piece.coords.c + 2);
        toggle_bit(state, state->active_piece.coords.l + 1, state->active_piece.coords.c + 2);
        toggle_bit(state, state->active_piece.coords.l + 2, state->active_piece.coords.c + 2);
        toggle_bit(state, state->active_piece.coords.l + 2, state->active_piece.coords.c);
    }
    else if (state->active_piece.type == T_SHAPE)
    {
        toggle_bit(state, state->active_piece.coords.l, state->active_piece.coords.c);
        toggle_bit(state, state->active_piece.coords.l, state->active_piece.coords.c + 2);
        toggle_bit(state, state->active_piece.coords.l, state->active_piece.coords.c + 4);
        toggle_bit(state, state->active_piece.coords.l + 1, state->active_piece.coords.c + 2);
    }
}