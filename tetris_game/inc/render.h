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

/**
 * Draw the board and the main UI
 * 
 * @param start_row The row to start drawing on
 * @param start_column The column to start drawing on
 */
void drawBoard(int start_row, int start_column);

long long get_current_time_ms();