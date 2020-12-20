#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "parse.h"
#include "shell.h"

int count_tokens(char * line, char delim){
  int num_tokens=0;
  while (*line){
    if (*line==delim) num_tokens++;
    line++;
  }
  return num_tokens;
}

char ** parse_args(char * line, char * delim){
  char *p = line;
  int i=0;
  char **args = malloc (sizeof (char**) * 100 );

  while (p){
    args[i]= strsep(&p, delim);
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


char * trim(char * line){
  char *p=line;
  int start, i;
  char space = ' ';

  for (start=0;p[start]==space;start++);

  for (i=0; p[i+1]; i++){
    p[i]=p[i+start];
  }

  for (i=0;p[i];i++){
    if (p[i]==space) p[i]='\0';
  }

  return p;
}
