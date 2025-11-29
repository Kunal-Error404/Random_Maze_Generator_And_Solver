#ifndef GAME_DISPLAY_H//Preprocessor Directives; checks if Game_Display_H is defined or not
#define GAME_DISPLAY_H//if its not defined then this defines it and processes the following code


#include "display.h"//including my deifned headerfiles
#include "maze_generator.h"
#include "timer.h"//for time fuctions

void draw_maze(int px, int py) {
    CLEAR_SCREEN();//calling on the system("cls") to clear screen

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {

            if (i == px && j == py) {//if current position matches the calculated pos replaces the current cell with player symbol
                PRINT_COLORED(COLOR_GREEN, PLAYER);
            }
            else if (maze[i][j] == WALL) {//similarly if position has a wall then prints # in blue color
                PRINT_COLORED(COLOR_BLUE, WALL);
            }
            else if (maze[i][j] == EXIT) {// if the cell is exit then prints X in red color
                PRINT_COLORED(COLOR_RED, EXIT);
            }
            else if (show_solution && solution[i][j]) {//if show soln is true and other condn it true then prints * in yellow color
                PRINT_COLORED(COLOR_YELLOW, SOLUTION);
            }
            else {
                printf("%c", PATH);// for all other paths prints space
            }
        }
        printf("\n");
    }

    printf("\nW A S D to move | H to show/hide solution | Q to quit\n");
    
    time_t current_time = time(NULL);//storing current system time
    double elapsed = difftime(current_time, start_time);//calc elapsed times
    int mins = (int)elapsed / 60;//type conversion to int after div by 60 to calc number of mins
    int secs = (int)elapsed % 60;//type conversion to int after taking remainder as it gives remainig seconds
    
    printf("Time elapsed: %02d:%02d\n", mins, secs);
}

#define DRAW_MAZE(px, py) draw_maze(px, py)//Macro which takes two arguments and calls on draw maxe function

#endif//ends ifndef 