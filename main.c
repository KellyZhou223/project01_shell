#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include "parse.h"
#include "shell.h"

int main(){
  int i;
  char space[] = " ";
  char semicolon[] = ";";

  while (1){
    char input[100];
    char ** command;

    printf("skssh$ ");
    fgets(input, sizeof(input)-1,stdin);

    trim_input(input);

    char ** args = parse_args(input, semicolon);
    for (i=0; args[i]; i++){
      command = parse_args(args[i], space);
      run_command(command);
      //sleep(1);
    }

    free(args);
    free(command);
  }

  return 0;
}
