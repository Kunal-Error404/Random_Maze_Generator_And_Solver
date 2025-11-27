#ifndef TIMER_H //Preprocessor Directives; checks if timer_h is defined or not
#define TIMER_H // if not then defines it and processes the following code

#include <time.h>//time.h header file includes various time functions
#include <stdio.h>//stdio.h header file includes printf and scanf 
#include <string.h>// string.h header file includes various string functions

time_t start_time; //time_t data type stores time here start_time and end_time are global variables
time_t end_time;   

void calculatetime() {//function declaration and definition to show time elapsed
    double time_taken = difftime(end_time, start_time);//difftime calculates difference in end time and start time then returns the result as a double
    int minutes = (int)time_taken / 60;//type-casting to int; here div by 60 gives number of mins
    int seconds = (int)time_taken % 60;//type-casting to int; here rem after div by 60 remaining sec
    
    printf("\n========== STATS ==========\n");//just some formatting
    printf("Time taken: ");
    
    if (minutes > 0) {// if time is less than 1 minute then just shows secs else shows time in format mins:secs
        printf("%d minute(s) and %d second(s)\n", minutes, seconds);
    } else {
        printf("%d second(s)\n", seconds);
    }
    
    printf("===========================\n");//closeing the formatting
}

void savetimetofile(double time_taken) {//function declaration and definition to save the results of the elapsed time in a txt file
    FILE *file = NULL;//file is file ptr which is initialized with NULL;
    file = fopen("maze_times.txt", "a");//creates file if it already doesnt exist and adds new text at last if the file already exists
    
    if (file == NULL) {//just some error handling in case file creation fails.
        printf("Error: Could not save time!\n");
        return;// as return type void cant do return 0
    }
    
    int minutes = (int)time_taken / 60;//type-casting to int; here div by 60 gives number of mins
    int seconds = (int)time_taken % 60;//type-casting to int; here rem after div by 60 remaining sec
    
    time_t current = time(0);//time(0) gets current time and saves it in current var of data type time_t
    char *date_time = ctime(&current);//converts current time into human readable format from a bit number
    date_time[strcspn(date_time, "\n")] = 0;//strcspn finds the index of newline in date_time string 
    //then that index is passed and /n is accessed and replaced by null

    fprintf(file, "Date: %s | Time taken: %02d:%02d (%d seconds)\n",  date_time, minutes, seconds, (int)time_taken);//file input
           
    fclose(file);//closes file
    
    printf("Time saved to maze_times.txt\n");//prints in terminal
}

#define START_TIMER() start_time = time(0)//Macro which takes no arguments and defines start_time as the current time of system before beginning the game
#define END_TIMER() end_time = time(0)//Macro which takes no arguments and defines end_time as the current time of system after completing the game
#define GET_ELAPSED_TIME() difftime(end_time, start_time)//Macro which just tells uselapsed time

#endif//ends ifndef