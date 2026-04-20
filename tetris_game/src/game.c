#include "game.h"

// Converts coordinate on board to bit position and flip the bit in the gamestate
void toggle_bit(GameState_t *state, coord_t bit_coord)
{
    // int norm_line = line - BOARD_TOP_WALL_COORD;
    // int norm_col = (col - BOARD_LEFT_WALL_COORD) / 2;
    state->bitboard[bit_coord.y].value ^= (1 << bit_coord.x);
    return;
}

int extract_bit(GameState_t *state, coord_t bit_coord)
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

void increase_gravity(GameState_t *state)
{
    state->active_piece.coords.p1.y++; // Move piece down by incrementing the y coordinate
    state->active_piece.coords.p2.y++; // Move piece down by incrementing the y coordinate
    state->active_piece.coords.p3.y++; // Move piece down by incrementing the y coordinate
    state->active_piece.coords.p4.y++; // Move piece down by incrementing the y coordinate
}

void redraw_shape(GameState_t *state)
{
    // For redraws I only need to redraw first and last row
    // Clear old shape
    toggle_bit(state, state->active_piece.prev_coords.p1);
    toggle_bit(state, state->active_piece.prev_coords.p2);
    toggle_bit(state, state->active_piece.prev_coords.p3);
    toggle_bit(state, state->active_piece.prev_coords.p4);

    // Draw new shape
    toggle_bit(state, state->active_piece.coords.p1);
    toggle_bit(state, state->active_piece.coords.p2);
    toggle_bit(state, state->active_piece.coords.p3);
    toggle_bit(state, state->active_piece.coords.p4);
}

void move_piece_right(GameState_t *state)
{
    if (state->active_piece.coords.p1.x < GAME_BOARD_WIDTH - 1 &&
        state->active_piece.coords.p2.x < GAME_BOARD_WIDTH - 1 &&
        state->active_piece.coords.p3.x < GAME_BOARD_WIDTH - 1 &&
        state->active_piece.coords.p4.x < GAME_BOARD_WIDTH - 1)
    {
        state->active_piece.coords.p1.x++;
        state->active_piece.coords.p2.x++;
        state->active_piece.coords.p3.x++;
        state->active_piece.coords.p4.x++;
    }
}

void move_piece_left(coords_t *coords)
{
    if (coords->p1.x >= 0 &&
        coords->p2.x >= 0 &&
        coords->p3.x >= 0 &&
        coords->p4.x >= 0)
    {
        coords->p1.x--;
        coords->p2.x--;
        coords->p3.x--;
        coords->p4.x--;
    }
}

void move_piece_down(GameState_t *state)
{
    if (state->active_piece.coords.p1.y < GAME_BOARD_HEIGHT - 1 &&
        state->active_piece.coords.p2.y < GAME_BOARD_HEIGHT - 1 &&
        state->active_piece.coords.p3.y < GAME_BOARD_HEIGHT - 1 &&
        state->active_piece.coords.p4.y < GAME_BOARD_HEIGHT - 1)
    {
        state->active_piece.coords.p1.y++;
        state->active_piece.coords.p2.y++;
        state->active_piece.coords.p3.y++;
        state->active_piece.coords.p4.y++;
    }
}

void _rotate_I_piece(Tetromino_t *piece)
{
    switch (piece->rotation_state)
    {
    case NORMAL: // Rotate to RIGHT state
        // P1 rotation
        piece->coords.p1.x++;
        piece->coords.p1.y++;

        // No change for P2 as it is focal point

        // P3 rotation
        piece->coords.p3.x--;
        piece->coords.p3.y--;

        // P4 rotation
        piece->coords.p4.x -= 2;
        piece->coords.p4.y -= 2;
        piece->rotation_state = RIGHT;
        break;
    case RIGHT: // Rotate to UPSIDE_DOWN state
        // P1 rotation
        piece->coords.p1.x--;
        piece->coords.p1.y++;

        // No change for P2 as it is focal point

        // P3 rotation
        piece->coords.p3.x++;
        piece->coords.p3.y--;

        // P4 rotation
        piece->coords.p4.x += 2;
        piece->coords.p4.y -= 2;
        piece->rotation_state = UPSIDE_DOWN;
        break;
    case UPSIDE_DOWN: // Rotate to LEFT state
        // P1 rotation
        piece->coords.p1.x--;
        piece->coords.p1.y--;

        // No change for P2 as it is focal point

        // P3 rotation
        piece->coords.p3.x++;
        piece->coords.p3.y++;

        // P4 rotation
        piece->coords.p4.x += 2;
        piece->coords.p4.y += 2;
        piece->rotation_state = LEFT;
        break;
    case LEFT: // Rotate to NORMAL state
        // P1 rotation
        piece->coords.p1.x++;
        piece->coords.p1.y--;

        // No change for P2 as it is focal point

        // P3 rotation
        piece->coords.p3.x--;
        piece->coords.p3.y++;

        // P4 rotation
        piece->coords.p4.x -= 2;
        piece->coords.p4.y += 2;
        piece->rotation_state = NORMAL;
        break;
    };
}

void rotate_piece(Tetromino_t *piece)
{
    piece->prev_coords = piece->coords;
    switch (piece->type)
    {
    case O_SHAPE:
        // No rotation needed for now.
        break;
    case I_SHAPE:
        _rotate_I_piece(piece);
    case S_SHAPE:

        break;
    default:
        break;
    };
}