#include "terminal.h"

void reset_terminal(struct termios *original)
{
    tcsetattr(STDIN_FILENO, TCSANOW, original);
}

struct termios set_raw_mode()
{
    struct termios original, raw;
    tcgetattr(STDIN_FILENO, &original);

    raw = original;
    raw.c_lflag &= ~(ICANON | ECHO); // Non-canonical, no echo
    raw.c_cc[VMIN] = 0;              // Non-blocking read
    raw.c_cc[VTIME] = 0;

    tcsetattr(STDIN_FILENO, TCSANOW, &raw);
    return original;
}

void clear_screen()
{
    printf(CLEAR);
    printf(CURSOR_HOME);
}

void cursor_home()
{
    printf(CURSOR_HOME);
}

void set_cursor(int line, int column)
{
    printf("\033[%d;%dH", line, column);
}

void hide_cursor()
{
    printf("\033[?25l");
}

void show_cursor()
{
    printf("\033[?25h");
}