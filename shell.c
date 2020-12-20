#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <string.h>
#include <signal.h>
#include "parse.h"
#include "shell.h"

void run_command(char** command){
  int f, status, i=0;
  
  int redir = 0;        // redirection is false
  int redir_index = 0;  // index of redirection symbol

  while (command[i]) {
    command[i] = trim(command[i]);
    
    if (!strcmp(command[i], ">") || !strcmp(command[i], ">>") || !strcmp(command[i], "<")) {
      redir = 1;          // detects redirection and set redirection to true
      redir_index = i;    // index of redirection symbol

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
    else if (redir) {                   // if redirection is true, run redirection function
      redirect(command, redir_index);
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

void redirect(char** cmd, int index) {
  if (strcmp(cmd[index], ">") == 0) {
    printf("Redirects stdout to a file.\n");

    int fd1 = open(cmd[index+1], O_WRONLY);

    if (fd1 < 0)
      printf("Error opening the file\n");
  }

  else if (strcmp(cmd[index], ">>") == 0) {
    printf("Redirects stdout to a file by appending.\n");
  }

  else if (strcmp(cmd[index], "<") == 0) {
    printf("Redirect stdin from a file.\n");
  }
}
