#include <stdio.h>
#include <unistd.h> // Add compiler flag to use freertos vTaskDelay when compiled on pico
#include <termios.h>
#include "tetris.h"

/** printf ANSI Escape Codes:
Clear Screen: printf("\033[2J");
Move Cursor Home (0,0): printf("\033[H");
Move Cursor to Position (L,C): printf("\033[%d;%dH", line, column);
Clear Screen & Home Cursor: printf("\033[2J\033[H");
Save Cursor Position: printf("\033[s");
Restore Cursor Position: printf("\033[u");
 */

#define BOARD_WIDTH 24
#define BOARD_HEIGHT 21

#define BOARD_LEFT_WALL 50
#define BOARD_RIGHT_WALL 74
#define BOARD_TOP_WALL 5
#define BOARD_BOTTOM_WALL 25

#define SHAPE_SPAWN_X ((BOARD_WIDTH / 2) + BOARD_LEFT_WALL)
#define SHAPE_SPAWN_Y 5

#define CLEAR "\033[2J"
#define CURSOR_HOME "\033[H"

// #define GAME_TITLE " _____    _        _     \n\
// |_   _|  | |      (_)    \n\
//   | | ___| |_ _ __ _ ___ \n\
//   | |/ _ \\ __| '__| / __|\n\
//   | |  __/ |_| |  | \\__ \\ \n\
//   \\_/\\___|\\__|_|  |_|___/\n\
//                          \n\
//                          "

#define SHAPE "[]"

/**
 * Structure to represent the coordinates of a piece on the board.
 */
typedef struct
{
    int x; // X position of the piece on the board
    int y; // Y position of the piece on the board
} coords_t;

/**
 * Reads a single character from the terminal without waiting for the Enter key.
 *
 * @return The character read from the terminal.
 */
int getch(void)
{
    struct termios oldt, newt;
    int ch;

    // Get current terminal settings
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;

    // Disable canonical mode (ICANON) and local echo (ECHO)
    newt.c_lflag &= ~(ICANON | ECHO);

    // Apply new settings immediately
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    // Read a single character
    ch = getchar();

    // Restore original terminal settings
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return ch;
}

/**
 * Clears the terminal screen and moves the cursor to the home position (0,0).
 */
void clear_screen()
{
    printf(CLEAR);
    printf(CURSOR_HOME);
}

/**
 * Moves the cursor to the home position (0,0) without clearing the screen.
 */
void cursor_home()
{
    printf(CURSOR_HOME);
}

/**
 * Moves the cursor to the specified line and column.
 *
 * @param line The line number (starting from 1).
 * @param column The column number (starting from 1).
 */
void set_cursor(int line, int column)
{
    printf("\033[%d;%dH", line, column);
}

/**
 * Hides the cursor in the terminal.
 */
void hide_cursor()
{
    printf("\033[?25l");
}

/**
 * Shows the cursor in the terminal.
 */
void show_cursor()
{
    printf("\033[?25h");
}

/** TETROMINO DRAWING FUNCTIONS */

/**
 * Draws the O-shaped tetromino at the specified origin coordinates.
 *
 * @param origin The coordinates of the top-left corner of the O shape.
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
    set_cursor(origin.y, origin.x);
    printf(SHAPE);
    set_cursor(origin.y + 1, origin.x);
    printf(SHAPE);
    set_cursor(origin.y + 2, origin.x);
    printf(SHAPE);
    set_cursor(origin.y + 2, origin.x - 2);
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

/**
 * The main function initializes the Tetris game, clears the screen, and sets up the initial state.
 * It then enters an infinite loop to handle user input and render the game visuals.
 */
int main(int argc, char *argv[])
{
    int curr_curser_line = 5;
    int curr_cursor_column = 25;

    clear_screen();
    cursor_home();
    show_cursor();

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
    for (int i = 0; i < BOARD_HEIGHT; i++)
    {
        printf("<! . . . . . . . . . .!>\n");
        set_cursor(curr_curser_line += 1, curr_cursor_column);
    }
    set_cursor(BOARD_HEIGHT + 5, curr_cursor_column);
    printf("<!********************!>\n");
    set_cursor(BOARD_HEIGHT + 6, curr_cursor_column);
    printf("  \\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\n");

    hide_cursor();
    // drawShapesTest();

    coords_t active_piece_coords = (coords_t){.x = SHAPE_SPAWN_X, .y = SHAPE_SPAWN_Y};
    while (1) // Main game loop, press 'q' to quit
    {
        // int ch = getch();
        // if (ch == 'q')
        // {
        //     break; // Exit the game loop if 'q' is pressed
        // }

        // Select shape to start with (randomizer will be implemented later)
        drawI(active_piece_coords);

        active_piece_coords.y++; // Move piece down by incrementing the y coordinate

        // Move piece down every iteration of the loop
        // need to redraw old position of piece with blank spaces to "erase" it
        set_cursor(active_piece_coords.y-1, active_piece_coords.x);
        if (active_piece_coords.x % 2 == 0)
        {
            printf(" .");
        }
        else
        {
            printf("  ");
        }

        // listen for inputs (from keybaord or gamepad)
        // if (ch == 'a')
        // {
        //     // move piece leftc
        //     // active_piece_coords.x--;
        // }
        // else if (ch == 'd')
        // {
        //     // move piece right
        //     // active_piece_coords.x++;
        // }
        // else if (ch == 's')
        // {
        //     // move piece down faster
        // }
        // else if (ch == 'w')
        // {
        //     // rotate piece
        // }

        // Render visuals

        sleep(1); // Loop sleep to control game speed (adjust as needed)
    }

    return 0;
}