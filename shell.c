#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <string.h>
#include <signal.h>
#include "parse.h"
#include "shell.h"

void run_command(char** command){
  int f, status, i=0;

  while (command[i]){
    command[i] = trim(command[i]);
    i++;
  }

  if (strcmp(command[0],"exit")==0){
    exit(0);
  }

  f = fork();

  if (f){
    wait(&status);
  }

  else{
    if (strcmp(command[0],"cd")==0){
      int cd = chdir(command[1]);
    }
    else {
      execvp(command[0], command);
    }
  }
}

int length_input(char* input){
  int i;
  for (i=0;input[i];i++);
  return i;
}

void trim_input(char * input){
  int i;

  for (i=0;input[i];i++){
    if (input[i]=='\n'){
      input[i]='\0';
    }
  }
}
