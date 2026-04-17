#include <stdio.h>
#include <sys/time.h>
#include "terminal.h"

#define FULL_BOARD_WIDTH 24
#define FULL_BOARD_HEIGHT 21

#define BOARD_LEFT_WALL_COORD 52
#define BOARD_RIGHT_WALL_COORD 70
#define BOARD_TOP_WALL_COORD 5
#define BOARD_BOTTOM_WALL_COORD 25

#define SHAPE_SPAWN_X ((FULL_BOARD_WIDTH / 2) + BOARD_LEFT_WALL_COORD) // As of now its 64
#define SHAPE_SPAWN_Y BOARD_TOP_WALL_COORD

#pragma once

#define SHAPE "[]"

typedef enum Shape
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

typedef enum Move
{
    VERTICAL,
    HORIZONTAL
} Move_t;

/**
 * Draw the board and the main UI
 * 
 * @param start_row The row to start drawing on
 * @param start_column The column to start drawing on
 */
void drawBoard(int start_row, int start_column);

// /**
//  * Draws the O-shaped tetromino at the specified origin coordinates.
//  *
//  * @param state Pointer to the gameState to be updated when rendering
//  * @param origin The coordinates of the top-left corner of the O shape.
//  */
// void renderO(GameState_t *state, coords_t origin);

// /**
//  * Draws the I-shaped tetromino at the specified origin coordinates.
//  *
//  * @param origin The coordinates of the top of the I shape.
//  */
// void renderI(GameState_t *state, coords_t origin);

// /**
//  * 
//  */
// void drawS(coords_t origin);

// void drawZ(coords_t origin);

// void drawL(coords_t origin);

// void drawJ(coords_t origin);

// void drawT(coords_t origin);

// void clear_old_position(GameState_t *state, Tetromino_t piece, Move_t move);

// void drawShapesTest();

long long get_current_time_ms();