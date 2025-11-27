#ifndef DISPLAY_H //Preprocessor Directives; checks if Display_H is not defined or not
#define DISPLAY_H //if its not defined then this defines it and processes the following code

#include <stdio.h> //include standard input output headerfile for printf and scanf
#include <stdlib.h>//include various standard library functions

void color(int c) {//function declaration and definition
    printf("\033[1;%dm", c);// \033 -> ANSI escape sequence; [1 -> makes the text bolder ; %d is just there to get input from c
}                           //for color

void reset_color() {
    printf("\033[0m");//resets the color to system defaults
}

void clear_screen() {
    system("cls");//clears screen
}

#define COLOR_RED 31 // Macros; Line 19-22 color constants
#define COLOR_GREEN 32
#define COLOR_YELLOW 33
#define COLOR_BLUE 34
/*defines a macro which takes 2 parameters it uses do while with braces to ignore indentation and then assigns color -> prints color
->resets color*/
#define PRINT_COLORED(c, ch) do { color(c); printf("%c", ch); reset_color(); } while(0)
#define CLEAR_SCREEN() clear_screen()//defines a macro which clears screen by calling on clear screen function with no parameters

#endif //ends ifndef its just like if - fi thing in linux