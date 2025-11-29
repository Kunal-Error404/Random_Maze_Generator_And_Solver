#include <stdio.h>
#include <conio.h>//for _getch and kbhit(checks if the key has been pressed)
#include <ctype.h>//for tolower
#include "../include/timer.h"//including my defined headerfiles had to include the path as otherwise the compiler was not recognizing them
#include "../include/display.h"
#include "../include/maze_generator.h"
#include "../include/maze_solver.h"
#include "../include/game_display.h"
#include "../include/player_movement.h"

void game_loop() {
    int px = 1, py = 1;//intiialzing player starting pos top left
    int ex = H - 2, ey = W - 2;//exit position bottom right

    maze[ex][ey] = EXIT;//marks exit positon

    SOLVE_MAZE(px, py, ex, ey);//pre solves the maze using dijkshtra's algorithm
    
    START_TIMER();//starts timer to calc elapsed time

    DRAW_MAZE(px, py);//displays the enitre maze

    while (1) {
        if (!_kbhit()) continue;//if no key is pressed the infinite loop continues and maze keeps on running;kbhit returns true if a key is pressed

        char key = _getch();//reads the key press and stores it; _getch reads the key input
        if (tolower(key) == 'q'){
            return;//if read key is q then exit
        }

        if (tolower(key) == 'h') {
            show_solution = !show_solution;//reverses the flag, its like an on and off switch for the solution
            DRAW_MAZE(px, py);//redraws the entire maze with solution
            continue;
        }

        MOVE_PLAYER(key, &px, &py);//moves player
        DRAW_MAZE(px, py);//redraws the entire maze i

        if (px == ex && py == ey) {//checks if the player coords match the exit coords
            END_TIMER();//ends timer
            double time_taken = GET_ELAPSED_TIME();//gets elapsed time using difftime(end,start)
            printf("\nYou reached the exit!\n");//on completion prints this
            calculatetime();//prints elapsed time
            savetimetofile(time_taken);//saves time in file
            return;
        }
    }
}

int main() {
    INIT_RANDOM();//random number generate to shuffle new numbers everytime
    GENERATE_MAZE();//generates maze
    game_loop();//starts game
    return 0;
}