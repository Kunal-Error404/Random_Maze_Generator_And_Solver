#ifndef PLAYER_MOVEMENT_H//Preprocessor Directives; checks if PLAYER_MOVEMENT_H is defined or not
#define PLAYER_MOVEMENT_H//if its not defined then this defines it and processes the following code

#include <ctype.h>//including ctype headerfile to use tolower function
#include "maze_generator.h"//including another headerfile made by me

void move_player(char key, int *px, int *py) {//function declaration and definition
    int nx = *px;//here nx is new x position
    int ny = *py;//here ny is new y position; using pointers to make changes to the current position of player

    key = tolower(key);//error handling in case user has caps lock on 

    if (key == 'w') nx--; //moves up
    if (key == 's') nx++;//moves down
    if (key == 'a') ny--;//moves left
    if (key == 'd') ny++;//moves right

    if (maze[nx][ny] != WALL) {
        *px = nx;
        *py = ny;
    }
}

#define MOVE_PLAYER(key, px, py) move_player(key, px, py)//defining a macro which calls on move player function

#endif//ends ifndef