# Snake Game in C

## Description
This project is a simple Snake game implemented in C using the `ncurses` library. The player controls the snake using arrow keys, guiding it to eat food, grow longer, and avoid collisions with itself. The game ends if the snake collides with its own body.

## Features
- Snake movement controlled by arrow keys.
- Random food generation.
- Snake growth after eating food.
- Game over condition when the snake collides with itself.
- Continuous snake movement with screen edge wrapping.

## How to Run
1. Clone the repository:
   git clone https://github.com/Raj-IITBBS/Snake_Game.git

2. Compile the code using gcc:
gcc -o snake_game snake_game.c -lncurses

3. Run the executable:
./snake_game

## Controls
- Arrow keys: Control the movement of the snake.
- Q: Quit the game.

## Requirements
- C compiler (e.g., gcc).
- ncurses library installed.
- You can install it using:
sudo apt-get install libncurses5-dev libncursesw5-dev
