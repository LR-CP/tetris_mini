#include "draw.h"

/**
 * All pieces are drawn from the top-left most square of the shape no matter if it is filled in or not.
 *   [][]
 * [][]
 * Starts from the top left empty square and it built out with indexing
 */

void drawBoard(int curr_curser_line, int curr_cursor_column)
{
    set_cursor(curr_curser_line, curr_cursor_column);
    printf("FULL LINES: 0\n");
    set_cursor(curr_curser_line += 1, curr_cursor_column);
    printf("LEVEL: 0\n");
    set_cursor(curr_curser_line += 1, curr_cursor_column);
    printf("SCORE: 0\n");
    set_cursor(curr_curser_line += 1, curr_cursor_column);
    printf("TIME: 0:00\n");

    curr_curser_line = 5;
    curr_cursor_column = 50;
    set_cursor(curr_curser_line, curr_cursor_column);
    for (int i = 1; i <= FULL_BOARD_HEIGHT; i++)
    {
        printf("<! . . . . . . . . . .!>\n");
        set_cursor(curr_curser_line += 1, curr_cursor_column);
    }
    set_cursor(FULL_BOARD_HEIGHT + 5, curr_cursor_column);
    printf("<!********************!>\n");
    set_cursor(FULL_BOARD_HEIGHT + 6, curr_cursor_column);
    printf("  \\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\n");
}

// void renderO(GameState_t *state, coords_t origin)
// {
//     set_cursor(origin.y, origin.x);
//     printf(SHAPE);
//     toggle_bit(state, origin.y, origin.x);
//     set_cursor(origin.y, origin.x + 2);
//     printf(SHAPE);
//     toggle_bit(state, origin.y, origin.x + 2);
//     set_cursor(origin.y + 1, origin.x);
//     printf(SHAPE);
//     toggle_bit(state, origin.y + 1, origin.x);
//     set_cursor(origin.y + 1, origin.x + 2);
//     printf(SHAPE);
//     toggle_bit(state, origin.y + 1, origin.x + 2);

//     printf("\n");
// }

// void renderI(GameState_t *state, coords_t origin)
// {
//     set_cursor(origin.y, origin.x);
//     printf(SHAPE);
//     toggle_bit(state, origin.y, origin.x);
//     set_cursor(origin.y + 1, origin.x);
//     printf(SHAPE);
//     toggle_bit(state, origin.y + 1, origin.x);
//     set_cursor(origin.y + 2, origin.x);
//     printf(SHAPE);
//     toggle_bit(state, origin.y + 2, origin.x);
//     set_cursor(origin.y + 3, origin.x);
//     printf(SHAPE);
//     toggle_bit(state, origin.y + 3, origin.x);

//     printf("\n");
// }

// void drawS(coords_t origin)
// {
//     set_cursor(origin.y, origin.x + 2);
//     printf(SHAPE);
//     set_cursor(origin.y, origin.x + 4);
//     printf(SHAPE);
//     set_cursor(origin.y + 1, origin.x);
//     printf(SHAPE);
//     set_cursor(origin.y + 1, origin.x + 2);
//     printf(SHAPE);

//     printf("\n");
// }

// void drawZ(coords_t origin)
// {
//     set_cursor(origin.y, origin.x);
//     printf(SHAPE);
//     set_cursor(origin.y, origin.x + 2);
//     printf(SHAPE);
//     set_cursor(origin.y + 1, origin.x + 2);
//     printf(SHAPE);
//     set_cursor(origin.y + 1, origin.x + 4);
//     printf(SHAPE);

//     printf("\n");
// }

// void drawL(coords_t origin)
// {
//     set_cursor(origin.y, origin.x);
//     printf(SHAPE);
//     set_cursor(origin.y + 1, origin.x);
//     printf(SHAPE);
//     set_cursor(origin.y + 2, origin.x);
//     printf(SHAPE);
//     set_cursor(origin.y + 2, origin.x + 2);
//     printf(SHAPE);

//     printf("\n");
// }

// void drawJ(coords_t origin)
// {
//     set_cursor(origin.y, origin.x + 2);
//     printf(SHAPE);
//     set_cursor(origin.y + 1, origin.x + 2);
//     printf(SHAPE);
//     set_cursor(origin.y + 2, origin.x + 2);
//     printf(SHAPE);
//     set_cursor(origin.y + 2, origin.x);
//     printf(SHAPE);

//     printf("\n");
// }

// void drawT(coords_t origin)
// {
//     set_cursor(origin.y, origin.x);
//     printf(SHAPE);
//     set_cursor(origin.y, origin.x + 2);
//     printf(SHAPE);
//     set_cursor(origin.y, origin.x + 4);
//     printf(SHAPE);
//     set_cursor(origin.y + 1, origin.x + 2);
//     printf(SHAPE);

//     printf("\n");
// }

// void clear_old_position(GameState_t *state, Tetromino_t piece, Move_t move)
// {
//     if (piece.type == O_SHAPE)
//     {
//         // Clear top
//         if (move == VERTICAL)
//         {
//             set_cursor(piece.coords.y - 1, piece.coords.x);
//             piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
//             // flip bit to be not of current bit
//             // toggle_bit(state, piece.coords.y - 1, piece.coords.x);
//             set_cursor(piece.coords.y - 1, piece.coords.x + 2);
//             piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
//             // toggle_bit(state, piece.coords.y - 1, piece.coords.x);
//         }

//         // Clear old shape position
//         if (move == HORIZONTAL)
//         {
//             set_cursor(piece.coords.y, piece.coords.x);
//             piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
//             // toggle_bit(state, piece.coords.y, piece.coords.x);
//             set_cursor(piece.coords.y, piece.coords.x + 2);
//             piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
//             // toggle_bit(state, piece.coords.y, piece.coords.x);
//             set_cursor(piece.coords.y + 1, piece.coords.x);
//             piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
//             // toggle_bit(state, piece.coords.y + 1, piece.coords.x);
//             set_cursor(piece.coords.y + 1, piece.coords.x + 2);
//             piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
//             // toggle_bit(state, piece.coords.y + 1, piece.coords.x);
//         }

//         printf("\n");
//     }
//     else if (piece.type == I_SHAPE)
//     {
//         // Clear top
//         if (move == VERTICAL)
//         {
//             set_cursor(piece.coords.y - 1, piece.coords.x);
//             piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
//             toggle_bit(state, piece.coords.y - 1, piece.coords.x);
//         }

//         // Clear old shape position
//         if (move == HORIZONTAL)
//         {
//             set_cursor(piece.coords.y, piece.coords.x);
//             piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
//             toggle_bit(state, piece.coords.y, piece.coords.x);

//             set_cursor(piece.coords.y + 1, piece.coords.x);
//             piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
//             toggle_bit(state, piece.coords.y + 1, piece.coords.x);

//             set_cursor(piece.coords.y + 2, piece.coords.x);
//             piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
//             toggle_bit(state, piece.coords.y + 2, piece.coords.x);

//             set_cursor(piece.coords.y + 3, piece.coords.x);
//             piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
//             toggle_bit(state, piece.coords.y + 3, piece.coords.x);
//         }

//         printf("\n");
//     }
//     else if (piece.type == S_SHAPE)
//     {
//         // Clear top
//         if (move == VERTICAL)
//         {
//             set_cursor(piece.coords.y - 1, piece.coords.x + 2);
//             piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
//             set_cursor(piece.coords.y - 1, piece.coords.x + 4);
//             piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
//             set_cursor(piece.coords.y, piece.coords.x);
//             piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
//         }

//         // Clear old shape position
//         if (move == HORIZONTAL)
//         {
//             set_cursor(piece.coords.y, piece.coords.x + 2);
//             piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
//             set_cursor(piece.coords.y, piece.coords.x + 4);
//             piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
//             set_cursor(piece.coords.y + 1, piece.coords.x);
//             piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
//             set_cursor(piece.coords.y + 1, piece.coords.x + 2);
//             piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
//         }

//         printf("\n");
//     }
//     else if (piece.type == Z_SHAPE)
//     {
//         // Clear top
//         if (move == VERTICAL)
//         {
//             set_cursor(piece.coords.y, piece.coords.x + 4);
//             piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
//             set_cursor(piece.coords.y - 1, piece.coords.x);
//             piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
//             set_cursor(piece.coords.y - 1, piece.coords.x + 2);
//             piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
//         }

//         // Clear old shape position
//         if (move == HORIZONTAL)
//         {
//             set_cursor(piece.coords.y, piece.coords.x);
//             piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
//             set_cursor(piece.coords.y, piece.coords.x + 2);
//             piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
//             set_cursor(piece.coords.y + 1, piece.coords.x + 2);
//             piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
//             set_cursor(piece.coords.y + 1, piece.coords.x + 4);
//             piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
//         }

//         printf("\n");
//     }
//     else if (piece.type == L_SHAPE)
//     {
//         // Clear top
//         if (move == VERTICAL)
//         {
//             set_cursor(piece.coords.y, piece.coords.x + 2);
//             piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
//             set_cursor(piece.coords.y + 1, piece.coords.x + 2);
//             piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
//             set_cursor(piece.coords.y - 1, piece.coords.x);
//             piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
//             set_cursor(piece.coords.y - 1, piece.coords.x + 2);
//             piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
//         }

//         // Clear old shape position
//         if (move == HORIZONTAL)
//         {
//             set_cursor(piece.coords.y, piece.coords.x);
//             piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
//             set_cursor(piece.coords.y + 1, piece.coords.x);
//             piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
//             set_cursor(piece.coords.y + 2, piece.coords.x);
//             piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
//             set_cursor(piece.coords.y + 2, piece.coords.x + 2);
//             piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
//         }

//         printf("\n");
//     }
//     else if (piece.type == J_SHAPE)
//     {
//         // Clear top
//         if (move == VERTICAL)
//         {
//             set_cursor(piece.coords.y, piece.coords.x);
//             piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
//             set_cursor(piece.coords.y + 1, piece.coords.x);
//             piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
//             set_cursor(piece.coords.y - 1, piece.coords.x);
//             piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
//             set_cursor(piece.coords.y - 1, piece.coords.x + 2);
//             piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
//         }

//         // Clear old shape position
//         if (move == HORIZONTAL)
//         {
//             set_cursor(piece.coords.y, piece.coords.x + 2);
//             piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
//             set_cursor(piece.coords.y + 1, piece.coords.x + 2);
//             piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
//             set_cursor(piece.coords.y + 2, piece.coords.x + 2);
//             piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
//             set_cursor(piece.coords.y + 2, piece.coords.x);
//             piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
//         }
//         printf("\n");
//     }
//     else if (piece.type == T_SHAPE)
//     {
//         // Clear top
//         if (move == VERTICAL)
//         {
//             set_cursor(piece.coords.y - 1, piece.coords.x + 4);
//             piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
//             set_cursor(piece.coords.y - 1, piece.coords.x);
//             piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
//             set_cursor(piece.coords.y - 1, piece.coords.x + 2);
//             piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
//         }

//         // Clear old shape position
//         if (move == HORIZONTAL)
//         {
//             set_cursor(piece.coords.y, piece.coords.x);
//             piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
//             set_cursor(piece.coords.y, piece.coords.x + 2);
//             piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
//             set_cursor(piece.coords.y, piece.coords.x + 4);
//             piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
//             set_cursor(piece.coords.y + 1, piece.coords.x + 2);
//             piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
//         }

//         printf("\n");
//     }
// }

// void drawShapesTest()
// {
//     coords_t coords = {.x = 52, .y = 6};
//     renderO(coords);

//     coords = (coords_t){.x = 58, .y = 6};
//     renderI(coords);

//     coords = (coords_t){.x = 64, .y = 6};
//     drawS(coords);

//     coords = (coords_t){.x = 52, .y = 10};
//     drawZ(coords);

//     coords = (coords_t){.x = 62, .y = 15};
//     drawL(coords);

//     coords = (coords_t){.x = 64, .y = 20};
//     drawJ(coords);

//     coords = (coords_t){.x = 52, .y = 14};
//     drawT(coords);
// }

long long get_current_time_ms()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (long long)(tv.tv_sec) * 1000 + (tv.tv_usec / 1000);
}
