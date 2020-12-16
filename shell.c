#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include "parse.h"
#include "shell.h"

/*
// fork off the child process
void forking(char *command){
    srand(time(NULL));
    char ** run = parse_args(command);

    if (strcmp(run[0], "cd") != 0){
        chdir(args[1]); // checks first command for changing directory
    }
    else{
        int f1, f2, status;
        f1 = fork();
        if (f1){
            wait(&status);
        }
        else{
            f2 = fork();
            // i'm not really sure where (and how) to use execvp?
        }
    }
    free(run);
}
*/
