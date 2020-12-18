#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <string.h>
#include "parse.h"
#include "shell.h"

void run_command(char** command){
  int f, status, i=0;

  //print_args(command);
  while (command[i]){
    command[i] = trim(command[i]);
    //printf("i: %d, command: %s\n",i, command[i]);
    i++;
  }
  //printf("%s\n", command[0]);
  f = fork();

  if (f){
    //printf("this is parent\n");
    wait(&status);
    printf("done\n");
  }
  else{
    //printf("this is child\n");
    if (strcmp(command[0],"cd")==0){
      int cd = chdir(command[1]);
    }
    else if (strcmp(command[0],"exit")==0){
      exit(0);
    }
    else {
      execvp(command[0], command);
    }

  }
}

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
    //free(run);
}*/
