#include <stdio.h>
#include <stdint.h>
#include <sys/time.h>
#include "terminal.h"
// #include "draw.h"

#pragma once

#define GAME_BOARD_WIDTH 10 // Width of board measured in pieces '[]' since they are 2 chars long
#define GAME_BOARD_HEIGHT 21 // Playable height of the board
#define DEBUG_GAME_BOARD_X_COORD 80 // X coord start of the debug board print
#define DEBUG_GAME_BOARD_Y_COORD 5 // Y cood start of the debug board print

typedef enum {
    FALSE,
    TRUE
} BOOL_t;

typedef struct {
    uint32_t value : GAME_BOARD_WIDTH;

} row_t;

typedef struct
{
    row_t bitboard[GAME_BOARD_HEIGHT]; // Can use array of these to store board to be more efficient retrievals
    int lines_completed; // Tracker of lines completed
    time_t game_time; // Game time tracker
    int level; // Current player level
    int score; // Current player score
} GameState_t;

void print_state_board(GameState_t *state);

void printb(int line, int n);

void toggle_bit(GameState_t *state, int line, int col);