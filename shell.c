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

  int pipe = 0;       // pipe is false
  int pipe_index = 0; // index of pipe symbol

  while (command[i]) {
    command[i] = trim(command[i]);
    
    if (!strcmp(command[i], ">") || !strcmp(command[i], ">>") || !strcmp(command[i], "<")) {
      redir = 1;          // detects redirection and set redirection to true
      redir_index = i;    // index of redirection symbol
    }

    if (!strcmp(command[i], "|")) {
      pipe = 1;          // detects piping and set pipe to true
      pipe_index = i;    // index of pipe symbol
    }

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
    else if (pipe) {                    // if pipe is true, run pipe function
      pipe_func(command, pipe_index);
    }
    else {
      execvp(command[0], command);
    }
  }
}

int length_input(char* input){
    int i;
    int len = 0;
    for (i=0;input[i];i++){
      len++;
    }
    return len;
}

void trim_input(char * input){
  int i;

  for (i=0;input[i];i++){
    if (input[i]=='\n'){
      input[i]='\0';
    }
  }
}
 
void redirect(char ** cmd, int index){
    int i;
    for (i = 0; cmd[i]; i++){
        if (strcmp(cmd[index], ">") == 0) {
            // redirects stdout to a file
            int fd1 = open(cmd[index+1], O_WRONLY);
            if (fd1 < 0){ // do we need this?
                printf("Error opening the file\n");
            }
            dup2(fd1, STDOUT_FILENO);
        }
        else if (strcmp(cmd[index], ">>") == 0){
            // redirects stdout to a file by appending
            int fd1 = open(cmd[i+1], O_CREAT | O_RDWR | O_APPEND, 0644);
            if (fd1 < 0){
                printf("Error opening the file\n");
            }
            dup2(fd1, STDOUT_FILENO);
        }
        else if (strcmp(cmd[index], "<") == 0){
            // redirects stdin from a file
            int fd2 = open(cmd[i + 1], O_RDONLY);
            dup2(fd2, STDIN_FILENO);
        }
    }
}

int pipe_func(char ** cmd, int index) {
  printf("Piping...\n");




  return 0; // successfully ran
}