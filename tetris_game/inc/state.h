#include <stdio.h>
#include <stdint.h>
#include <time.h>

#pragma once

#define GAME_BOARD_WIDTH 10         // Width of board measured in pieces '[]' since they are 2 chars long
#define GAME_BOARD_HEIGHT 20        // Playable height of the board
#define DEBUG_GAME_BOARD_X_COORD 80 // X coord start of the debug board print
#define DEBUG_GAME_BOARD_Y_COORD 5  // Y cood start of the debug board print

typedef enum
{
    FALSE,
    TRUE
} BOOL_t;

typedef enum
{
    O_SHAPE,
    I_SHAPE,
    S_SHAPE,
    Z_SHAPE,
    L_SHAPE,
    J_SHAPE,
    T_SHAPE
} Shape_t;

/**
 * Structure to represent coordinates.
 */
typedef struct
{
    int x; // X position of the piece on the board
    int y; // Y position of the piece on the board
} coord_t;

/**
 * Structure to represent the location of a piece
 * on the board
 */
typedef struct
{
    coord_t p1;
    coord_t p2;
    coord_t p3;
    coord_t p4;
} coords_t;

typedef enum 
{
    NORMAL,
    LEFT,
    RIGHT,
    UPSIDE_DOWN
} Rotations_t;

typedef struct
{
    Shape_t type;
    coords_t coords;
    coords_t prev_coords;
    Rotations_t rotation_state;
    int height;
    int width;
} Tetromino_t;

typedef struct
{
    unsigned int value : GAME_BOARD_WIDTH;
} row_t;

typedef struct
{
    row_t bitboard[GAME_BOARD_HEIGHT]; // Can use array of these to store board to be more efficient retrievals
    Tetromino_t active_piece;          // Currently active piece
    int lines_completed;               // Tracker of lines completed
    time_t game_time;                  // Game time tracker
    int level;                         // Current player level
    int score;                         // Current player score
} GameState_t;

void print_state_board(GameState_t *state);

void _printb(int line, int n);

void _update_bitboard_bits(GameState_t *state);

void toggle_bit(GameState_t *state, coord_t bit_coord);

BOOL_t extract_bit(GameState_t *state, coord_t bit_coord);

/**
 * Shape State Functions
 */
void increase_gravity(GameState_t *state);

void move_piece_right(GameState_t *state);

void move_piece_left(GameState_t *state);

void move_piece_down(GameState_t *state);

void rotate_piece(GameState_t *state);

void _rotate_I_piece(Tetromino_t *piece);
void _rotate_S_piece(Tetromino_t *piece);
void _rotate_Z_piece(Tetromino_t *piece);
void _rotate_L_piece(Tetromino_t *piece);
void _rotate_J_piece(Tetromino_t *piece);
void _rotate_T_piece(Tetromino_t *piece);