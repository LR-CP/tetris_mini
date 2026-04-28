#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include "render.h"

#pragma once

#define GAME_BOARD_WIDTH 10         // Width of board measured in pieces '[]' since they are 2 chars long
#define GAME_BOARD_HEIGHT 20        // Playable height of the board
#define DEBUG_GAME_BOARD_X_COORD 80 // X coord start of the debug board print
#define DEBUG_GAME_BOARD_Y_COORD 5  // Y cood start of the debug board print

/**
 * Boolean-style values used throughout the game state.
 */
typedef enum
{
    FALSE,
    TRUE
} BOOL_t;

/**
 * Identifiers for each supported tetromino shape.
 */
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
 * Represents a single board coordinate.
 */
typedef struct
{
    int x; /**< X position of the piece on the board. */
    int y; /**< Y position of the piece on the board. */
} coord_t;

/**
 * Represents the four block coordinates that make up a tetromino.
 */
typedef struct
{
    coord_t p1; /**< Coordinate of the first block. */
    coord_t p2; /**< Coordinate of the second block. */
    coord_t p3; /**< Coordinate of the third block. */
    coord_t p4; /**< Coordinate of the fourth block. */
} coords_t;

/**
 * Rotation states used to track tetromino orientation.
 */
typedef enum 
{
    NORMAL,
    LEFT,
    RIGHT,
    UPSIDE_DOWN
} Rotations_t;

/**
 * Represents a tetromino and its current placement data.
 */
typedef struct
{
    Shape_t type;               /**< Shape identifier for the tetromino. */
    coords_t coords;            /**< Current block coordinates. */
    coords_t prev_coords;       /**< Previous block coordinates used for redraws. */
    Rotations_t rotation_state; /**< Current orientation of the tetromino. */
    int height;                 /**< Height of the tetromino footprint. */
    int width;                  /**< Width of the tetromino footprint. */
} Tetromino_t;

/**
 * Represents a single bit-packed row of the game board.
 */
typedef struct
{
    unsigned int value : GAME_BOARD_WIDTH; /**< Bitfield storing occupied cells in the row. */
} row_t;

/**
 * Stores the complete mutable state of a Tetris game session.
 */
typedef struct
{
    row_t bitboard[GAME_BOARD_HEIGHT]; /**< Bit-packed board rows for occupied cells. */
    Tetromino_t active_piece;          /**< Currently active falling piece. */
    int lines_completed;               /**< Number of completed lines cleared. */
    time_t game_time;                  /**< Elapsed or tracked game time value. */
    int level;                         /**< Current player level. */
    int score;                         /**< Current player score. */
} GameState_t;

/**
 * Prints the game state's bitboard to stdout for debugging.
 *
 * @param state Pointer to the game state to print.
 */
void print_state_board(GameState_t *state);

/**
 * Prints a single board row as a binary value for debugging.
 *
 * @param line The row index associated with the printed value.
 * @param n The bit-packed row value to print.
 */
void _printb(int line, int n);

/**
 * Synchronizes the bitboard with the active piece's previous and current coordinates.
 *
 * @param state Pointer to the game state to update.
 */
void _update_bitboard_bits(GameState_t *state);

/**
 * Toggles the bit at the provided board coordinate.
 *
 * @param state Pointer to the game state containing the bitboard.
 * @param bit_coord The board coordinate to toggle.
 */
void toggle_bit(GameState_t *state, coord_t bit_coord);

/**
 * Extracts the bit value at the provided board coordinate.
 *
 * @param state Pointer to the game state containing the bitboard.
 * @param bit_coord The board coordinate to read.
 * @return TRUE if the bit is set; otherwise FALSE.
 */
BOOL_t extract_bit(GameState_t *state, coord_t bit_coord);

/**
 * Shape State Functions
 */
/**
 * Advances the active piece downward by one row.
 *
 * @param state Pointer to the game state to update.
 */
void increase_gravity(GameState_t *state);

/**
 * Moves the active piece one column to the right when possible.
 *
 * @param state Pointer to the game state to update.
 */
void move_piece_right(GameState_t *state);

/**
 * Moves the active piece one column to the left when possible.
 *
 * @param state Pointer to the game state to update.
 */
void move_piece_left(GameState_t *state);

/**
 * Moves the active piece one row downward when possible.
 *
 * @param state Pointer to the game state to update.
 */
void move_piece_down(GameState_t *state);

/**
 * Rotates the active piece according to its shape-specific rotation rules.
 *
 * @param state Pointer to the game state to update.
 */
void rotate_piece(GameState_t *state);

/**
 * Rotates an I-shaped tetromino to its next rotation state.
 *
 * @param piece Pointer to the tetromino to rotate.
 */
void _rotate_I_piece(Tetromino_t *piece);

/**
 * Rotates an S-shaped tetromino to its next rotation state.
 *
 * @param piece Pointer to the tetromino to rotate.
 */
void _rotate_S_piece(Tetromino_t *piece);

/**
 * Rotates a Z-shaped tetromino to its next rotation state.
 *
 * @param piece Pointer to the tetromino to rotate.
 */
void _rotate_Z_piece(Tetromino_t *piece);

/**
 * Rotates an L-shaped tetromino to its next rotation state.
 *
 * @param piece Pointer to the tetromino to rotate.
 */
void _rotate_L_piece(Tetromino_t *piece);

/**
 * Rotates a J-shaped tetromino to its next rotation state.
 *
 * @param piece Pointer to the tetromino to rotate.
 */
void _rotate_J_piece(Tetromino_t *piece);

/**
 * Rotates a T-shaped tetromino to its next rotation state.
 *
 * @param piece Pointer to the tetromino to rotate.
 */
void _rotate_T_piece(Tetromino_t *piece);
