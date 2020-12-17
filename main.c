#include <stdio.h>
#include <string.h>
#include "parse.h"
#include "shell.h"

int main(int argc, char **argv){
  char line[] = "ls -l;ls -a";
  char line2[] = "cd ..";
  int i=0;
  char space[] = " ";
  char ** args = parse_args(line2, space);
  while (args[i]){
    printf("%s\n",args[i]);
    i++;
  }
  //print_args(args);
  run_command(args);
  /*while (argv[i]){
    printf("%s\n", argv[i]);
    i++;
  }*/
  char delim = ';';
  //printf("if u see this ur cool\n");
  //char *cut = trim(line);

  //printf("number of tokens: %d\n", count_tokens(line,delim));
  //print_args(args);
  return 0;
}
