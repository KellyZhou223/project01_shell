#include <stdio.h>
#include <string.h>
#include "parse.h"

char *args[5];

int count_tokens(char * line, char delim){
  int num_tokens=0;
  while (*line){
    if (*line==delim) num_tokens++;
    line++;
  }
  return num_tokens;
}

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

/*
char * trim(char * line){
  char * p;
  int i;


  return p;
}
 */

