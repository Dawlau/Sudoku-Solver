# Sudoku-Solver

This is a classic Sudoku game, which allows the player to make moves, but also has the option to view a solution in case the player gets stuck. Moreover, the player will never be solving the same puzzle twice since whenever the game is restarted, a new puzzle is generated.

This app has been made with [C++](https://en.wikipedia.org/wiki/C%2B%2B) and for the GUI and event handling I used [SFML](https://www.sfml-dev.org/). It has been compiled with [g++](https://gcc.gnu.org/) and the SFML dependencies have been linked dynamically.

## Features

This app has 3 main features:

1. A very intuitive GUI which allows the player to solve the given Sudoku puzzle.
2. A way to generate a new Sudoku puzzle every time the player presses the R key.
3. A way to see a solution for the puzzle every time the player presses the S key. This feature also allows the player to see how the algorithm for finding the solution actually works by showing every step it makes.


## Requirements

In order to play this game you have got to first install the [SFML](https://www.sfml-dev.org/tutorials/2.5/start-linux.php#:~:text=Installing%20SFML,and%20manually%20copy%20the%20files)
 dependencies.

 ## How to run


If you wish to re-compile the app just run the "app.sh" script which will take care of all the compiling and linking for you and it will also run the app automatically. (for this you will have to also install [g++](https://gcc.gnu.org/))

If you just want to run the app, open the terminal in the root directory of the project and run the command "./app".


## Final notes

If you ever want to use this code in Windows, you will have to go to the file "Solver.cpp" at line 64 and change the usleep function call to its Windows equivalent since usleep is Linux specific.

Have fun!
