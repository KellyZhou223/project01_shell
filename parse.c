#include <stdio.h>
#include <string.h>
#include "parse.h"

char *args[5];

char ** parse_args(char * line){
  char *p = line;
  int i=0;

  while (p){
    args[i]= strsep(&p, " ");
    i++;
  }

  args[i]=NULL;
  return args;
}

void print_args(char ** a){
  int i;
  for (i=0; a[i]; i++){
    printf("%s\n", a[i]);
  }
}
