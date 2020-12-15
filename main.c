#include <stdio.h>
#include "parse.h"

int main(){
  char line[] = " ls -l ; echo hello ;  ls -a ";
  char delim = ';';
  // char *trimmed = trim(line);
  //while (*trimmed) {
  //   printf("%c", *trimmed);
  //  trimmed++;
  // }
  //char ** args = parse_args(line);
  //printf("number of tokens: %d\n", count_tokens(line,delim));
  //print_args(args);
  return 0;
}
