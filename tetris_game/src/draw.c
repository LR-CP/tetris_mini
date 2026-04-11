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
//     set_cursor(origin.l, origin.c);
//     printf(SHAPE);
//     toggle_bit(state, origin.l, origin.c);
//     set_cursor(origin.l, origin.c + 2);
//     printf(SHAPE);
//     toggle_bit(state, origin.l, origin.c + 2);
//     set_cursor(origin.l + 1, origin.c);
//     printf(SHAPE);
//     toggle_bit(state, origin.l + 1, origin.c);
//     set_cursor(origin.l + 1, origin.c + 2);
//     printf(SHAPE);
//     toggle_bit(state, origin.l + 1, origin.c + 2);

//     printf("\n");
// }

// void renderI(GameState_t *state, coords_t origin)
// {
//     set_cursor(origin.l, origin.c);
//     printf(SHAPE);
//     toggle_bit(state, origin.l, origin.c);
//     set_cursor(origin.l + 1, origin.c);
//     printf(SHAPE);
//     toggle_bit(state, origin.l + 1, origin.c);
//     set_cursor(origin.l + 2, origin.c);
//     printf(SHAPE);
//     toggle_bit(state, origin.l + 2, origin.c);
//     set_cursor(origin.l + 3, origin.c);
//     printf(SHAPE);
//     toggle_bit(state, origin.l + 3, origin.c);

//     printf("\n");
// }

void drawS(coords_t origin)
{
    set_cursor(origin.l, origin.c + 2);
    printf(SHAPE);
    set_cursor(origin.l, origin.c + 4);
    printf(SHAPE);
    set_cursor(origin.l + 1, origin.c);
    printf(SHAPE);
    set_cursor(origin.l + 1, origin.c + 2);
    printf(SHAPE);

    printf("\n");
}

void drawZ(coords_t origin)
{
    set_cursor(origin.l, origin.c);
    printf(SHAPE);
    set_cursor(origin.l, origin.c + 2);
    printf(SHAPE);
    set_cursor(origin.l + 1, origin.c + 2);
    printf(SHAPE);
    set_cursor(origin.l + 1, origin.c + 4);
    printf(SHAPE);

    printf("\n");
}

void drawL(coords_t origin)
{
    set_cursor(origin.l, origin.c);
    printf(SHAPE);
    set_cursor(origin.l + 1, origin.c);
    printf(SHAPE);
    set_cursor(origin.l + 2, origin.c);
    printf(SHAPE);
    set_cursor(origin.l + 2, origin.c + 2);
    printf(SHAPE);

    printf("\n");
}

void drawJ(coords_t origin)
{
    set_cursor(origin.l, origin.c + 2);
    printf(SHAPE);
    set_cursor(origin.l + 1, origin.c + 2);
    printf(SHAPE);
    set_cursor(origin.l + 2, origin.c + 2);
    printf(SHAPE);
    set_cursor(origin.l + 2, origin.c);
    printf(SHAPE);

    printf("\n");
}

void drawT(coords_t origin)
{
    set_cursor(origin.l, origin.c);
    printf(SHAPE);
    set_cursor(origin.l, origin.c + 2);
    printf(SHAPE);
    set_cursor(origin.l, origin.c + 4);
    printf(SHAPE);
    set_cursor(origin.l + 1, origin.c + 2);
    printf(SHAPE);

    printf("\n");
}

// void clear_old_position(GameState_t *state, Tetromino_t piece, Move_t move)
// {
//     if (piece.type == O_SHAPE)
//     {
//         // Clear top
//         if (move == VERTICAL)
//         {
//             set_cursor(piece.coords.l - 1, piece.coords.c);
//             piece.coords.c % 2 == 0 ? printf(" .") : printf("  ");
//             // flip bit to be not of current bit
//             // toggle_bit(state, piece.coords.l - 1, piece.coords.c);
//             set_cursor(piece.coords.l - 1, piece.coords.c + 2);
//             piece.coords.c % 2 == 0 ? printf(" .") : printf("  ");
//             // toggle_bit(state, piece.coords.l - 1, piece.coords.c);
//         }

//         // Clear old shape position
//         if (move == HORIZONTAL)
//         {
//             set_cursor(piece.coords.l, piece.coords.c);
//             piece.coords.c % 2 == 0 ? printf(" .") : printf("  ");
//             // toggle_bit(state, piece.coords.l, piece.coords.c);
//             set_cursor(piece.coords.l, piece.coords.c + 2);
//             piece.coords.c % 2 == 0 ? printf(" .") : printf("  ");
//             // toggle_bit(state, piece.coords.l, piece.coords.c);
//             set_cursor(piece.coords.l + 1, piece.coords.c);
//             piece.coords.c % 2 == 0 ? printf(" .") : printf("  ");
//             // toggle_bit(state, piece.coords.l + 1, piece.coords.c);
//             set_cursor(piece.coords.l + 1, piece.coords.c + 2);
//             piece.coords.c % 2 == 0 ? printf(" .") : printf("  ");
//             // toggle_bit(state, piece.coords.l + 1, piece.coords.c);
//         }

//         printf("\n");
//     }
//     else if (piece.type == I_SHAPE)
//     {
//         // Clear top
//         if (move == VERTICAL)
//         {
//             set_cursor(piece.coords.l - 1, piece.coords.c);
//             piece.coords.c % 2 == 0 ? printf(" .") : printf("  ");
//             toggle_bit(state, piece.coords.l - 1, piece.coords.c);
//         }

//         // Clear old shape position
//         if (move == HORIZONTAL)
//         {
//             set_cursor(piece.coords.l, piece.coords.c);
//             piece.coords.c % 2 == 0 ? printf(" .") : printf("  ");
//             toggle_bit(state, piece.coords.l, piece.coords.c);

//             set_cursor(piece.coords.l + 1, piece.coords.c);
//             piece.coords.c % 2 == 0 ? printf(" .") : printf("  ");
//             toggle_bit(state, piece.coords.l + 1, piece.coords.c);

//             set_cursor(piece.coords.l + 2, piece.coords.c);
//             piece.coords.c % 2 == 0 ? printf(" .") : printf("  ");
//             toggle_bit(state, piece.coords.l + 2, piece.coords.c);

//             set_cursor(piece.coords.l + 3, piece.coords.c);
//             piece.coords.c % 2 == 0 ? printf(" .") : printf("  ");
//             toggle_bit(state, piece.coords.l + 3, piece.coords.c);
//         }

//         printf("\n");
//     }
//     else if (piece.type == S_SHAPE)
//     {
//         // Clear top
//         if (move == VERTICAL)
//         {
//             set_cursor(piece.coords.l - 1, piece.coords.c + 2);
//             piece.coords.c % 2 == 0 ? printf(" .") : printf("  ");
//             set_cursor(piece.coords.l - 1, piece.coords.c + 4);
//             piece.coords.c % 2 == 0 ? printf(" .") : printf("  ");
//             set_cursor(piece.coords.l, piece.coords.c);
//             piece.coords.c % 2 == 0 ? printf(" .") : printf("  ");
//         }

//         // Clear old shape position
//         if (move == HORIZONTAL)
//         {
//             set_cursor(piece.coords.l, piece.coords.c + 2);
//             piece.coords.c % 2 == 0 ? printf(" .") : printf("  ");
//             set_cursor(piece.coords.l, piece.coords.c + 4);
//             piece.coords.c % 2 == 0 ? printf(" .") : printf("  ");
//             set_cursor(piece.coords.l + 1, piece.coords.c);
//             piece.coords.c % 2 == 0 ? printf(" .") : printf("  ");
//             set_cursor(piece.coords.l + 1, piece.coords.c + 2);
//             piece.coords.c % 2 == 0 ? printf(" .") : printf("  ");
//         }

//         printf("\n");
//     }
//     else if (piece.type == Z_SHAPE)
//     {
//         // Clear top
//         if (move == VERTICAL)
//         {
//             set_cursor(piece.coords.l, piece.coords.c + 4);
//             piece.coords.c % 2 == 0 ? printf(" .") : printf("  ");
//             set_cursor(piece.coords.l - 1, piece.coords.c);
//             piece.coords.c % 2 == 0 ? printf(" .") : printf("  ");
//             set_cursor(piece.coords.l - 1, piece.coords.c + 2);
//             piece.coords.c % 2 == 0 ? printf(" .") : printf("  ");
//         }

//         // Clear old shape position
//         if (move == HORIZONTAL)
//         {
//             set_cursor(piece.coords.l, piece.coords.c);
//             piece.coords.c % 2 == 0 ? printf(" .") : printf("  ");
//             set_cursor(piece.coords.l, piece.coords.c + 2);
//             piece.coords.c % 2 == 0 ? printf(" .") : printf("  ");
//             set_cursor(piece.coords.l + 1, piece.coords.c + 2);
//             piece.coords.c % 2 == 0 ? printf(" .") : printf("  ");
//             set_cursor(piece.coords.l + 1, piece.coords.c + 4);
//             piece.coords.c % 2 == 0 ? printf(" .") : printf("  ");
//         }

//         printf("\n");
//     }
//     else if (piece.type == L_SHAPE)
//     {
//         // Clear top
//         if (move == VERTICAL)
//         {
//             set_cursor(piece.coords.l, piece.coords.c + 2);
//             piece.coords.c % 2 == 0 ? printf(" .") : printf("  ");
//             set_cursor(piece.coords.l + 1, piece.coords.c + 2);
//             piece.coords.c % 2 == 0 ? printf(" .") : printf("  ");
//             set_cursor(piece.coords.l - 1, piece.coords.c);
//             piece.coords.c % 2 == 0 ? printf(" .") : printf("  ");
//             set_cursor(piece.coords.l - 1, piece.coords.c + 2);
//             piece.coords.c % 2 == 0 ? printf(" .") : printf("  ");
//         }

//         // Clear old shape position
//         if (move == HORIZONTAL)
//         {
//             set_cursor(piece.coords.l, piece.coords.c);
//             piece.coords.c % 2 == 0 ? printf(" .") : printf("  ");
//             set_cursor(piece.coords.l + 1, piece.coords.c);
//             piece.coords.c % 2 == 0 ? printf(" .") : printf("  ");
//             set_cursor(piece.coords.l + 2, piece.coords.c);
//             piece.coords.c % 2 == 0 ? printf(" .") : printf("  ");
//             set_cursor(piece.coords.l + 2, piece.coords.c + 2);
//             piece.coords.c % 2 == 0 ? printf(" .") : printf("  ");
//         }

//         printf("\n");
//     }
//     else if (piece.type == J_SHAPE)
//     {
//         // Clear top
//         if (move == VERTICAL)
//         {
//             set_cursor(piece.coords.l, piece.coords.c);
//             piece.coords.c % 2 == 0 ? printf(" .") : printf("  ");
//             set_cursor(piece.coords.l + 1, piece.coords.c);
//             piece.coords.c % 2 == 0 ? printf(" .") : printf("  ");
//             set_cursor(piece.coords.l - 1, piece.coords.c);
//             piece.coords.c % 2 == 0 ? printf(" .") : printf("  ");
//             set_cursor(piece.coords.l - 1, piece.coords.c + 2);
//             piece.coords.c % 2 == 0 ? printf(" .") : printf("  ");
//         }

//         // Clear old shape position
//         if (move == HORIZONTAL)
//         {
//             set_cursor(piece.coords.l, piece.coords.c + 2);
//             piece.coords.c % 2 == 0 ? printf(" .") : printf("  ");
//             set_cursor(piece.coords.l + 1, piece.coords.c + 2);
//             piece.coords.c % 2 == 0 ? printf(" .") : printf("  ");
//             set_cursor(piece.coords.l + 2, piece.coords.c + 2);
//             piece.coords.c % 2 == 0 ? printf(" .") : printf("  ");
//             set_cursor(piece.coords.l + 2, piece.coords.c);
//             piece.coords.c % 2 == 0 ? printf(" .") : printf("  ");
//         }
//         printf("\n");
//     }
//     else if (piece.type == T_SHAPE)
//     {
//         // Clear top
//         if (move == VERTICAL)
//         {
//             set_cursor(piece.coords.l - 1, piece.coords.c + 4);
//             piece.coords.c % 2 == 0 ? printf(" .") : printf("  ");
//             set_cursor(piece.coords.l - 1, piece.coords.c);
//             piece.coords.c % 2 == 0 ? printf(" .") : printf("  ");
//             set_cursor(piece.coords.l - 1, piece.coords.c + 2);
//             piece.coords.c % 2 == 0 ? printf(" .") : printf("  ");
//         }

//         // Clear old shape position
//         if (move == HORIZONTAL)
//         {
//             set_cursor(piece.coords.l, piece.coords.c);
//             piece.coords.c % 2 == 0 ? printf(" .") : printf("  ");
//             set_cursor(piece.coords.l, piece.coords.c + 2);
//             piece.coords.c % 2 == 0 ? printf(" .") : printf("  ");
//             set_cursor(piece.coords.l, piece.coords.c + 4);
//             piece.coords.c % 2 == 0 ? printf(" .") : printf("  ");
//             set_cursor(piece.coords.l + 1, piece.coords.c + 2);
//             piece.coords.c % 2 == 0 ? printf(" .") : printf("  ");
//         }

//         printf("\n");
//     }
// }

// void drawShapesTest()
// {
//     coords_t coords = {.c = 52, .l = 6};
//     renderO(coords);

//     coords = (coords_t){.c = 58, .l = 6};
//     renderI(coords);

//     coords = (coords_t){.c = 64, .l = 6};
//     drawS(coords);

//     coords = (coords_t){.c = 52, .l = 10};
//     drawZ(coords);

//     coords = (coords_t){.c = 62, .l = 15};
//     drawL(coords);

//     coords = (coords_t){.c = 64, .l = 20};
//     drawJ(coords);

//     coords = (coords_t){.c = 52, .l = 14};
//     drawT(coords);
// }

long long get_current_time_ms()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (long long)(tv.tv_sec) * 1000 + (tv.tv_usec / 1000);
}
