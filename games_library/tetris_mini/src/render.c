#include "render.h"

void setup_ui()
{
    set_cursor(0, 0);
    printf("FULL LINES: 0\n");
    set_cursor(2, 0);
    printf("LEVEL: 0\n");
    set_cursor(3, 0);
    printf("SCORE: 0\n");
    set_cursor(4, 0);
    printf("TIME: 0:00\n");

    // Move out to new draw board func (no)
    int line = 0, col = 25;
    set_cursor(line, col);
    for (int i = 1; i <= FULL_BOARD_HEIGHT; i++)
    {
        printf("<! . . . . . . . . . .!>\n");
        set_cursor(line += 1, col);
    }
    set_cursor(FULL_BOARD_HEIGHT, col);
    printf("<!********************!>\n");
    set_cursor(FULL_BOARD_HEIGHT + 1, col);
    printf("  \\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\n");
}

long long get_current_time_ms()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (long long)(tv.tv_sec) * 1000 + (tv.tv_usec / 1000);
}
