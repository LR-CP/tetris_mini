#include <stdio.h>
#include <sys/time.h>
#include <string.h>
#include "terminal.h"

#define FULL_BOARD_WIDTH 24
#define FULL_BOARD_HEIGHT 21

#define BOARD_LEFT_WALL_COORD 52
#define BOARD_RIGHT_WALL_COORD 70
#define BOARD_TOP_WALL_COORD 5
#define BOARD_BOTTOM_WALL_COORD 25

#define SHAPE_SPAWN_X ((FULL_BOARD_WIDTH / 2) + BOARD_LEFT_WALL_COORD) // As of now its 64
#define SHAPE_SPAWN_Y BOARD_TOP_WALL_COORD

#define RENDER_BOARD_ORIGIN_X 27 // X Coordinate of the rendered board
#define RENDER_BOARD_ORIGIN_Y 0 // Y Coordinate of the rendered board

#pragma once

#define SHAPE "[]\n"

/**
 * Draw the board and the main UI
 */
void setup_ui();

/**
 * Returns the current wall-clock time in milliseconds.
 *
 * @return The current time in milliseconds.
 */
long long get_current_time_ms();
