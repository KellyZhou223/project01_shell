#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "parse.h"
#include "shell.h"

int main(){
  //while (1){
    char input[100]="";
    printf("skssh$");
    fgets(input, sizeof(input)-1,stdin);

    //char line[] = "ls -l;ls -a";

    int i;
    char space[] = " ";
    char semicolon[] = ";";
    char ** command;

    char ** args = parse_args(input, semicolon);
    for (i=0; args[i]; i++){
      command = parse_args(args[i], space);
      run_command(command);
      sleep(1);
    }

    free(args);
    free(command);
  //}

  return 0;
}
