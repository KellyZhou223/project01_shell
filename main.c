#include <stdio.h>
#include "parse.h"

int main(){
  char line[] = "ls -l";
  char ** args = parse_args(line);
  //print_args(args);
  return 0;
}
