#include <stdio.h>
#include <string.h>
#include "parse.h"

int main(){
  char line[] = " ls ";
  char delim = ';';
  printf("if u see this ur cool\n");
  char *cut = trim(line);
  printf("hello %p\n", cut);
  while (*cut) {
    printf("%c", *cut);
    cut++;
   }
  //char ** args = parse_args(line);
  //printf("number of tokens: %d\n", count_tokens(line,delim));
  //print_args(args);
  return 0;
}
