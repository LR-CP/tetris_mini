#include "state.h"

void increase_gravity(GameState_t *state)
{
    state->active_piece.prev_coords = state->active_piece.coords;
    state->active_piece.coords.p1.y++; // Move piece down by incrementing the y coordinate
    state->active_piece.coords.p2.y++; // Move piece down by incrementing the y coordinate
    state->active_piece.coords.p3.y++; // Move piece down by incrementing the y coordinate
    state->active_piece.coords.p4.y++; // Move piece down by incrementing the y coordinate

    _update_bitboard_bits(state);
}

void move_piece_right(GameState_t *state)
{
    state->active_piece.prev_coords = state->active_piece.coords;
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
    _update_bitboard_bits(state);
}

void move_piece_left(GameState_t *state)
{
    state->active_piece.prev_coords = state->active_piece.coords;
    if (state->active_piece.coords.p1.x >= 0 &&
        state->active_piece.coords.p2.x >= 0 &&
        state->active_piece.coords.p3.x >= 0 &&
        state->active_piece.coords.p4.x >= 0)
    {
        state->active_piece.coords.p1.x--;
        state->active_piece.coords.p2.x--;
        state->active_piece.coords.p3.x--;
        state->active_piece.coords.p4.x--;
    }
    _update_bitboard_bits(state);
}

void move_piece_down(GameState_t *state)
{
    state->active_piece.prev_coords = state->active_piece.coords;
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
    _update_bitboard_bits(state);
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

void _rotate_S_piece(Tetromino_t *piece)
{
    switch (piece->rotation_state)
    {
    case NORMAL: // Rotate to RIGHT state
        // P1 rotation
        piece->coords.p1.x--;
        piece->coords.p1.y++;

        // No change for P2 as it is focal point

        // P3 rotation
        piece->coords.p3.x--;
        piece->coords.p3.y--;

        // P4 rotation
        piece->coords.p4.y -= 2;
        piece->rotation_state = RIGHT;
        break;
    case RIGHT: // Rotate to UPSIDE_DOWN state
        // P1 rotation
        piece->coords.p1.x--;
        piece->coords.p1.y--;

        // No change for P2 as it is focal point

        // P3 rotation
        piece->coords.p3.x++;
        piece->coords.p3.y--;

        // P4 rotation
        piece->coords.p4.x += 2;
        piece->rotation_state = UPSIDE_DOWN;
        break;
    case UPSIDE_DOWN: // Rotate to LEFT state
        // P1 rotation
        piece->coords.p1.x++;
        piece->coords.p1.y--;

        // No change for P2 as it is focal point

        // P3 rotation
        piece->coords.p3.x++;
        piece->coords.p3.y++;

        // P4 rotation
        piece->coords.p4.y += 2;
        piece->rotation_state = LEFT;
        break;
    case LEFT: // Rotate to NORMAL state
        // P1 rotation
        piece->coords.p1.x++;
        piece->coords.p1.y++;

        // No change for P2 as it is focal point

        // P3 rotation
        piece->coords.p3.x--;
        piece->coords.p3.y++;

        // P4 rotation
        piece->coords.p4.x -= 2;
        piece->rotation_state = NORMAL;
        break;
    };
}

void _rotate_Z_piece(Tetromino_t *piece)
{
    switch (piece->rotation_state)
    {
    case NORMAL: // Rotate to RIGHT state
        piece->coords.p1.x++;
        piece->coords.p1.y--;

        piece->coords.p3.x--;
        piece->coords.p3.y--;

        piece->coords.p4.x -= 2;
        piece->rotation_state = RIGHT;
        break;
    case RIGHT: // Rotate to UPSIDE_DOWN state
        piece->coords.p1.x++;
        piece->coords.p1.y++;

        piece->coords.p3.x++;
        piece->coords.p3.y--;

        piece->coords.p4.y -= 2;
        piece->rotation_state = UPSIDE_DOWN;
        break;
    case UPSIDE_DOWN: // Rotate to LEFT state
        piece->coords.p1.x--;
        piece->coords.p1.y++;

        piece->coords.p3.x++;
        piece->coords.p3.y++;

        piece->coords.p4.x += 2;
        piece->rotation_state = LEFT;
        break;
    case LEFT: // Rotate to NORMAL state
        piece->coords.p1.x--;
        piece->coords.p1.y--;

        piece->coords.p3.x--;
        piece->coords.p3.y++;

        piece->coords.p4.y += 2;
        piece->rotation_state = NORMAL;
        break;
    };
}

void _rotate_L_piece(Tetromino_t *piece)
{
    switch (piece->rotation_state)
    {
    case NORMAL: // Rotate to RIGHT state
        piece->coords.p1.x++;
        piece->coords.p1.y++;

        piece->coords.p3.x--;
        piece->coords.p3.y--;

        piece->coords.p4.x -= 2;
        piece->rotation_state = RIGHT;
        break;
    case RIGHT: // Rotate to UPSIDE_DOWN state
        piece->coords.p1.x--;
        piece->coords.p1.y++;

        piece->coords.p3.x++;
        piece->coords.p3.y--;

        piece->coords.p4.y -= 2;
        piece->rotation_state = UPSIDE_DOWN;
        break;
    case UPSIDE_DOWN: // Rotate to LEFT state
        piece->coords.p1.x--;
        piece->coords.p1.y--;

        piece->coords.p3.x++;
        piece->coords.p3.y++;

        piece->coords.p4.x += 2;
        piece->rotation_state = LEFT;
        break;
    case LEFT: // Rotate to NORMAL state
        piece->coords.p1.x++;
        piece->coords.p1.y--;

        piece->coords.p3.x--;
        piece->coords.p3.y++;

        piece->coords.p4.y += 2;
        piece->rotation_state = NORMAL;
        break;
    };
}

void _rotate_J_piece(Tetromino_t *piece)
{
    switch (piece->rotation_state)
    {
    case NORMAL: // Rotate to RIGHT state
        piece->coords.p1.x++;
        piece->coords.p1.y++;

        piece->coords.p3.x--;
        piece->coords.p3.y--;

        piece->coords.p4.y -= 2;
        piece->rotation_state = RIGHT;
        break;
    case RIGHT: // Rotate to UPSIDE_DOWN state
        piece->coords.p1.x--;
        piece->coords.p1.y++;

        piece->coords.p3.x++;
        piece->coords.p3.y--;

        piece->coords.p4.x += 2;
        piece->rotation_state = UPSIDE_DOWN;
        break;
    case UPSIDE_DOWN: // Rotate to LEFT state
        piece->coords.p1.x--;
        piece->coords.p1.y--;

        piece->coords.p3.x++;
        piece->coords.p3.y++;

        piece->coords.p4.y += 2;
        piece->rotation_state = LEFT;
        break;
    case LEFT: // Rotate to NORMAL state
        piece->coords.p1.x++;
        piece->coords.p1.y--;

        piece->coords.p3.x--;
        piece->coords.p3.y++;

        piece->coords.p4.x -= 2;
        piece->rotation_state = NORMAL;
        break;
    };
}

void _rotate_T_piece(Tetromino_t *piece)
{
    switch (piece->rotation_state)
    {
    case NORMAL: // Rotate to RIGHT state
        piece->coords.p1.x++;
        piece->coords.p1.y--;

        piece->coords.p3.x--;
        piece->coords.p3.y++;

        piece->coords.p4.x--;
        piece->coords.p4.y--;
        piece->rotation_state = RIGHT;
        break;
    case RIGHT: // Rotate to UPSIDE_DOWN state
        piece->coords.p1.x++;
        piece->coords.p1.y++;

        piece->coords.p3.x--;
        piece->coords.p3.y--;

        piece->coords.p4.x++;
        piece->coords.p4.y--;
        piece->rotation_state = UPSIDE_DOWN;
        break;
    case UPSIDE_DOWN: // Rotate to LEFT state
        piece->coords.p1.x--;
        piece->coords.p1.y++;

        piece->coords.p3.x++;
        piece->coords.p3.y--;

        piece->coords.p4.x++;
        piece->coords.p4.y++;
        piece->rotation_state = LEFT;
        break;
    case LEFT: // Rotate to NORMAL state
        piece->coords.p1.x--;
        piece->coords.p1.y--;

        piece->coords.p3.x++;
        piece->coords.p3.y++;

        piece->coords.p4.x--;
        piece->coords.p4.y++;
        piece->rotation_state = NORMAL;
        break;
    };
}

void rotate_piece(GameState_t *state)
{
    state->active_piece.prev_coords = state->active_piece.coords;
    switch (state->active_piece.type)
    {
    case O_SHAPE:
        // No rotation needed for now.
        break;
    case I_SHAPE:
        _rotate_I_piece(&state->active_piece);
        break;
    case S_SHAPE:
        _rotate_S_piece(&state->active_piece);
        break;
    case Z_SHAPE:
        _rotate_Z_piece(&state->active_piece);
        break;
    case L_SHAPE:
        _rotate_L_piece(&state->active_piece);
        break;
    case J_SHAPE:
        _rotate_J_piece(&state->active_piece);
        break;
    case T_SHAPE:
        _rotate_T_piece(&state->active_piece);
        break;
    default:
        break;
    };

    _update_bitboard_bits(state);
}
