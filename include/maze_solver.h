#ifndef MAZE_SOLVER_H//Preprocessor Directives; checks if Maze_Solver_H is defined or not
#define MAZE_SOLVER_H//if its not defined then this defines it and processes the following code

#include <limits.h>//for INT_MAX CONSTANT
#include "maze_generator.h"

char solution[H][W];//decalring a char array which stores solution
int show_solution = 0;//flag to show solution just like isprime

typedef struct Node {//Dijkstra's Node
    int x;//x coord in maze
    int y;// y coord in maze
    int dist;//shortest distance
    int visited;//visited(1)or not(0)
    int parentx;//x coord of parent node
    int parenty;//y coord of parent node
} node;

void findminnode(node graph[H][W], int *minx, int *miny) {//to find unvisited node with the smallest distance
    int mindist = INT_MAX;
    *minx = -1;
    *miny = -1;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (!graph[i][j].visited && graph[i][j].dist < mindist) {
                mindist = graph[i][j].dist;
                *minx = i;
                *miny = j;
            }
        }
    }
}

void markpath(node graph[H][W], int startx, int starty, int endx, int endy) {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            solution[i][j] = 0;//intializing solution array to 0
        }
    }

    int cx = endx;
    int cy = endy;

    while (cx != startx || cy != starty) {//backtracking
        solution[cx][cy] = 1;
        int tempx = graph[cx][cy].parentx;
        int tempy = graph[cx][cy].parenty;//goes to parent node
        cx = tempx;
        cy = tempy;

        if (cx == -1 || cy == -1) {//error handling if parent node is invalid
            break;
        }
    }
}

int solvemaze(int startx, int starty, int endx, int endy) {//Dijkstra's shortest path algorithm
    node graph[H][W];

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            graph[i][j].x = i;
            graph[i][j].y = j;
            graph[i][j].dist = INT_MAX;
            graph[i][j].visited = 0;
            graph[i][j].parentx = -1;
            graph[i][j].parenty = -1;
        }
    }

    graph[startx][starty].dist = 0;

    for (int count = 0; count < H * W; count++) {
        int cx = 0;
        int cy = 0;
        findminnode(graph, &cx, &cy);

        if (cx == -1 || graph[cx][cy].dist == INT_MAX) {
            break;
        }

        graph[cx][cy].visited = 1;

        if (cx == endx && cy == endy) {
            markpath(graph, startx, starty, endx, endy);
            return 1;
        }

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx >= 0 && nx < H && ny >= 0 && ny < W) {
                if (maze[nx][ny] != WALL && !graph[nx][ny].visited) {
                    int newdist = graph[cx][cy].dist + 1;

                    if (newdist < graph[nx][ny].dist) {
                        graph[nx][ny].dist = newdist;
                        graph[nx][ny].parentx = cx;
                        graph[nx][ny].parenty = cy;
                    }
                }
            }
        }
    }

    return 0;
}

#define SOLVE_MAZE(sx, sy, ex, ey) solvemaze(sx, sy, ex, ey)//Macro with 4 arguments which calls on solvemaze function block

#endif//ends ifndef