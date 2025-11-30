#ifndef MAZE_GENERATOR_H//Preprocessor Directives; checks if Display_H is defined or not
#define MAZE_GENERATOR_H//if its not defined then this defines it and processes the following code

#include <stdlib.h>//including standard library functions
#include <time.h>//include time functions

#define H 21                
#define W 41                
#define WALL '#'               
#define PATH ' '             //defining constants
#define PLAYER '@'               
#define EXIT 'X'               
#define SOLUTION '*'             

char maze[H][W];//declaring a char array which stores maze


int dx[4] = {0, 0, -1, 1};// movement vectors
int dy[4] = {1, -1, 0, 0};//adding and subtracting these pairs to current position to traverse the 2D matrix array like adding 0(x) and 1(y)moves right like (2,5)->(2,6)

void shuffle(int *arr, int n) {//using Fisher-Yates algorithm to shuffle and generate a fresh maze everytime
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }
}

int valid(int x, int y) {//checks if the user stays inside the bounds of the maze
    return x > 0 && y > 0 && x < H - 1 && y < W - 1;
}

void carve(int x, int y) {
    int dirs[4] = {0, 1, 2, 3};//4 direction NESW
    shuffle(dirs, 4);//shuffles these directions to generate a fresh maze

    for (int i = 0; i < 4; i++) {//loops through the directions
        int nx = x + dx[dirs[i]] * 2;
        int ny = y + dy[dirs[i]] * 2;

        if (valid(nx, ny) && maze[nx][ny] == WALL) {//if condn true carves a path
            maze[x + dx[dirs[i]]][y + dy[dirs[i]]] = PATH;
            maze[nx][ny] = PATH;
            carve(nx, ny);
        }
    }
}

void generate_maze() {//uses recursive backtracking to generate the maze
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            maze[i][j] = WALL;

    maze[1][1] = PATH;
    carve(1, 1);
}

#define GENERATE_MAZE() generate_maze()//macro which calls on generate maze function
#define INIT_RANDOM() srand(time(NULL))//seeds random number by using system current time

#endif//ends ifndef block