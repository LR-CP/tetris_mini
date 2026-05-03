#include <stdlib.h>
#include <termios.h>
#include <sys/select.h>
#include <unistd.h>

#pragma once

/**
 * Checks if there is keyboard input available without blocking.
 *
 * @return 1 if there is input available, 0 otherwise.
 */
int keyboard_input();