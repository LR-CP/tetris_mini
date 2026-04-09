#include "draw.h"

/**
 * All pieces are drawn from the top-left most square of the shape no matter if it is filled in or not.
 *   [][]
 * [][]
 * Starts from the top left empty square and it built out with indexing
 */

void drawO(coords_t origin)
{
    set_cursor(origin.y, origin.x);
    printf(SHAPE);
    set_cursor(origin.y, origin.x + 2);
    printf(SHAPE);
    set_cursor(origin.y + 1, origin.x);
    printf(SHAPE);
    set_cursor(origin.y + 1, origin.x + 2);
    printf(SHAPE);

    printf("\n");
}

void drawI(coords_t origin)
{
    set_cursor(origin.y, origin.x);
    printf(SHAPE);
    set_cursor(origin.y + 1, origin.x);
    printf(SHAPE);
    set_cursor(origin.y + 2, origin.x);
    printf(SHAPE);
    set_cursor(origin.y + 3, origin.x);
    printf(SHAPE);

    printf("\n");
}

void drawS(coords_t origin)
{
    set_cursor(origin.y, origin.x + 2);
    printf(SHAPE);
    set_cursor(origin.y, origin.x + 4);
    printf(SHAPE);
    set_cursor(origin.y + 1, origin.x);
    printf(SHAPE);
    set_cursor(origin.y + 1, origin.x + 2);
    printf(SHAPE);

    printf("\n");
}

void drawZ(coords_t origin)
{
    set_cursor(origin.y, origin.x);
    printf(SHAPE);
    set_cursor(origin.y, origin.x + 2);
    printf(SHAPE);
    set_cursor(origin.y + 1, origin.x + 2);
    printf(SHAPE);
    set_cursor(origin.y + 1, origin.x + 4);
    printf(SHAPE);

    printf("\n");
}

void drawL(coords_t origin)
{
    set_cursor(origin.y, origin.x);
    printf(SHAPE);
    set_cursor(origin.y + 1, origin.x);
    printf(SHAPE);
    set_cursor(origin.y + 2, origin.x);
    printf(SHAPE);
    set_cursor(origin.y + 2, origin.x + 2);
    printf(SHAPE);

    printf("\n");
}

void drawJ(coords_t origin)
{
    set_cursor(origin.y, origin.x + 2);
    printf(SHAPE);
    set_cursor(origin.y + 1, origin.x + 2);
    printf(SHAPE);
    set_cursor(origin.y + 2, origin.x + 2);
    printf(SHAPE);
    set_cursor(origin.y + 2, origin.x);
    printf(SHAPE);

    printf("\n");
}

void drawT(coords_t origin)
{
    set_cursor(origin.y, origin.x);
    printf(SHAPE);
    set_cursor(origin.y, origin.x + 2);
    printf(SHAPE);
    set_cursor(origin.y, origin.x + 4);
    printf(SHAPE);
    set_cursor(origin.y + 1, origin.x + 2);
    printf(SHAPE);

    printf("\n");
}

void clear_old_position(Tetromino_t piece, Move_t move)
{
    if (piece.type == O_SHAPE)
    {
        // Clear top
        if (move == VERTICAL)
        {
            set_cursor(piece.coords.y - 1, piece.coords.x);
            piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
            set_cursor(piece.coords.y - 1, piece.coords.x + 2);
            piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
        }

        // Clear old shape position
        if (move == HORIZONTAL)
        {
            set_cursor(piece.coords.y, piece.coords.x);
            piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
            set_cursor(piece.coords.y, piece.coords.x + 2);
            piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
            set_cursor(piece.coords.y + 1, piece.coords.x);
            piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
            set_cursor(piece.coords.y + 1, piece.coords.x + 2);
            piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
        }

        printf("\n");
    }
    else if (piece.type == I_SHAPE)
    {
        // Clear top
        if (move == VERTICAL)
        {
            set_cursor(piece.coords.y - 1, piece.coords.x);
            piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
        }

        // Clear old shape position
        if (move == HORIZONTAL)
        {
            set_cursor(piece.coords.y, piece.coords.x);
            piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
            set_cursor(piece.coords.y + 1, piece.coords.x);
            piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
            set_cursor(piece.coords.y + 2, piece.coords.x);
            piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
            set_cursor(piece.coords.y + 3, piece.coords.x);
            piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
        }

        printf("\n");
    }
    else if (piece.type == S_SHAPE)
    {
        // Clear top
        if (move == VERTICAL)
        {
            set_cursor(piece.coords.y - 1, piece.coords.x + 2);
            piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
            set_cursor(piece.coords.y - 1, piece.coords.x + 4);
            piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
            set_cursor(piece.coords.y, piece.coords.x);
            piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
        }

        // Clear old shape position
        if (move == HORIZONTAL)
        {
            set_cursor(piece.coords.y, piece.coords.x + 2);
            piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
            set_cursor(piece.coords.y, piece.coords.x + 4);
            piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
            set_cursor(piece.coords.y + 1, piece.coords.x);
            piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
            set_cursor(piece.coords.y + 1, piece.coords.x + 2);
            piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
        }

        printf("\n");
    }
    else if (piece.type == Z_SHAPE)
    {
        // Clear top
        if (move == VERTICAL)
        {
            set_cursor(piece.coords.y, piece.coords.x + 4);
            piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
            set_cursor(piece.coords.y - 1, piece.coords.x);
            piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
            set_cursor(piece.coords.y - 1, piece.coords.x + 2);
            piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
        }

        // Clear old shape position
        if (move == HORIZONTAL)
        {
            set_cursor(piece.coords.y, piece.coords.x);
            piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
            set_cursor(piece.coords.y, piece.coords.x + 2);
            piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
            set_cursor(piece.coords.y + 1, piece.coords.x + 2);
            piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
            set_cursor(piece.coords.y + 1, piece.coords.x + 4);
            piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
        }

        printf("\n");
    }
    else if (piece.type == L_SHAPE)
    {
        // Clear top
        if (move == VERTICAL)
        {
            set_cursor(piece.coords.y, piece.coords.x + 2);
            piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
            set_cursor(piece.coords.y + 1, piece.coords.x + 2);
            piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
            set_cursor(piece.coords.y - 1, piece.coords.x);
            piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
            set_cursor(piece.coords.y - 1, piece.coords.x + 2);
            piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
        }

        // Clear old shape position
        if (move == HORIZONTAL)
        {
            set_cursor(piece.coords.y, piece.coords.x);
            piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
            set_cursor(piece.coords.y + 1, piece.coords.x);
            piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
            set_cursor(piece.coords.y + 2, piece.coords.x);
            piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
            set_cursor(piece.coords.y + 2, piece.coords.x + 2);
            piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
        }

        printf("\n");
    }
    else if (piece.type == J_SHAPE)
    {
        // Clear top
        if (move == VERTICAL)
        {
            set_cursor(piece.coords.y, piece.coords.x);
            piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
            set_cursor(piece.coords.y + 1, piece.coords.x);
            piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
            set_cursor(piece.coords.y - 1, piece.coords.x);
            piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
            set_cursor(piece.coords.y - 1, piece.coords.x + 2);
            piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
        }

        // Clear old shape position
        if (move == HORIZONTAL)
        {
            set_cursor(piece.coords.y, piece.coords.x + 2);
            piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
            set_cursor(piece.coords.y + 1, piece.coords.x + 2);
            piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
            set_cursor(piece.coords.y + 2, piece.coords.x + 2);
            piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
            set_cursor(piece.coords.y + 2, piece.coords.x);
            piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
        }
        printf("\n");
    }
    else if (piece.type == T_SHAPE)
    {
        // Clear top
        if (move == VERTICAL)
        {
            set_cursor(piece.coords.y - 1, piece.coords.x + 4);
            piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
            set_cursor(piece.coords.y - 1, piece.coords.x);
            piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
            set_cursor(piece.coords.y - 1, piece.coords.x + 2);
            piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
        }

        // Clear old shape position
        if (move == HORIZONTAL)
        {
            set_cursor(piece.coords.y, piece.coords.x);
            piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
            set_cursor(piece.coords.y, piece.coords.x + 2);
            piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
            set_cursor(piece.coords.y, piece.coords.x + 4);
            piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
            set_cursor(piece.coords.y + 1, piece.coords.x + 2);
            piece.coords.x % 2 == 0 ? printf(" .") : printf("  ");
        }

        printf("\n");
    }
}

void drawShapesTest()
{
    coords_t coords = {.x = 52, .y = 6};
    drawO(coords);

    coords = (coords_t){.x = 58, .y = 6};
    drawI(coords);

    coords = (coords_t){.x = 64, .y = 6};
    drawS(coords);

    coords = (coords_t){.x = 52, .y = 10};
    drawZ(coords);

    coords = (coords_t){.x = 62, .y = 15};
    drawL(coords);

    coords = (coords_t){.x = 64, .y = 20};
    drawJ(coords);

    coords = (coords_t){.x = 52, .y = 14};
    drawT(coords);
}

long long get_current_time_ms()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (long long)(tv.tv_sec) * 1000 + (tv.tv_usec / 1000);
}
