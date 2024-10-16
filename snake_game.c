/* 
gcc -o project project.c -lncurses
./project
*/

#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#define DELAY 10000

// Function to generate random positions for food
void generate_food(int *food_x, int *food_y, int max_x, int max_y) {
    *food_x = rand() % max_x;
    *food_y = rand() % max_y;
}

int main() {
    int max_x, max_y;
    int snake_x = 10, snake_y = 10;
    int food_x = 0, food_y = 0;
    int ch;
    int length = 1;
    int snake_body[100][2] = {{10, 10}}; // Storing snake's position
    int direction_x = 1, direction_y = 0; // Initial direction to the right

    srand(time(0)); // Seed for random food generation

    // Initialize ncurses
    initscr();
    curs_set(FALSE);
    timeout(100); // Non-blocking input
    keypad(stdscr, TRUE);
    noecho();
    getmaxyx(stdscr, max_y, max_x);

    // Generate initial food position
    generate_food(&food_x, &food_y, max_x, max_y);

    while (1) {
        clear();

        // Draw food
        mvprintw(food_y, food_x, "O");

        // Draw snake body
        for (int i = 0; i < length; i++) {
            mvprintw(snake_body[i][1], snake_body[i][0], "X");
        }

        // Input handling
        ch = getch();
        switch (ch) {
            case KEY_UP:
                direction_x = 0;
                direction_y = -1;
                break;
            case KEY_DOWN:
                direction_x = 0;
                direction_y = 1;
                break;
            case KEY_LEFT:
                direction_x = -1;
                direction_y = 0;
                break;
            case KEY_RIGHT:
                direction_x = 1;
                direction_y = 0;
                break;
            case 'q': // Quit the game
                endwin();
                return 0;
        }

        // Update snake's position
        snake_x += direction_x;
        snake_y += direction_y;

        // Check for boundary collision
        if (snake_x >= max_x) snake_x = 0;
        if (snake_x < 0) snake_x = max_x - 1;
        if (snake_y >= max_y) snake_y = 0;
        if (snake_y < 0) snake_y = max_y - 1;

        // Update snake's body positions
        for (int i = length - 1; i > 0; i--) {
            snake_body[i][0] = snake_body[i - 1][0];
            snake_body[i][1] = snake_body[i - 1][1];
        }
        snake_body[0][0] = snake_x;
        snake_body[0][1] = snake_y;

        // Check if the snake eats the food
        if (snake_x == food_x && snake_y == food_y) {
            length++;
            generate_food(&food_x, &food_y, max_x, max_y);
        }

        // Check if the snake hits itself
        for (int i = 1; i < length; i++) {
            if (snake_x == snake_body[i][0] && snake_y == snake_body[i][1]) {
                mvprintw(max_y / 2, max_x / 2 - 5, "Game Over!");
                refresh();
                sleep(2);
                endwin();
                return 0;
            }
        }

        refresh();
        usleep(DELAY);
    }

    endwin();
    return 0;
}