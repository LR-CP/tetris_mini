#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <stdint.h>

#pragma once

#define CLEAR "\033[2J"
#define CURSOR_HOME "\033[H"

void reset_terminal(struct termios *original);

/**
 * Sets the terminal to raw mode for non-blocking input and no echo.
 *
 * @return The original terminal settings to be restored later.
 */
struct termios set_raw_mode();

/**
 * Clears the terminal screen and moves the cursor to the home position (0,0).
 */
void clear_screen();

/**
 * Moves the cursor to the home position (0,0) without clearing the screen.
 */
void cursor_home();

/**
 * Moves the cursor to the specified line and column.
 *
 * @param line The line number (starting from 1).
 * @param column The column number (starting from 1).
 */
void set_cursor(int line, int column);

/**
 * Hides the cursor in the terminal.
 */
void hide_cursor();

/**
 * Shows the cursor in the terminal.
 */
void show_cursor();