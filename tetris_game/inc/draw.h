#include <stdio.h>
#include <sys/time.h>
#include "terminal.h"

#define BOARD_WIDTH 24
#define BOARD_HEIGHT 21

#define BOARD_LEFT_WALL 52
#define BOARD_RIGHT_WALL 70
#define BOARD_TOP_WALL 5
#define BOARD_BOTTOM_WALL 25

#define SHAPE_SPAWN_X ((BOARD_WIDTH / 2) + BOARD_LEFT_WALL)
#define SHAPE_SPAWN_Y 5

#pragma once

#define SHAPE "[]"

/**
 * Structure to represent the coordinates of a piece on the board.
 */
typedef struct
{
    int c; // X position of the piece on the board
    int l; // Y position of the piece on the board
} coords_t;

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

typedef struct
{
    Shape_t type;
    coords_t coords;
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

/**
 * Draws the O-shaped tetromino at the specified origin coordinates.
 *
 * @param origin The coordinates of the top-left corner of the O shape.
 */
void drawO(coords_t origin);

/**
 * Draws the I-shaped tetromino at the specified origin coordinates.
 *
 * @param origin The coordinates of the top of the I shape.
 */
void drawI(coords_t origin);

/**
 * 
 */
void drawS(coords_t origin);

void drawZ(coords_t origin);

void drawL(coords_t origin);

void drawJ(coords_t origin);

void drawT(coords_t origin);

void clear_old_position(Tetromino_t piece, Move_t move);

void drawShapesTest();

long long get_current_time_ms();