#ifndef SHELL_H
#define SHELL_H
void run_command(char** command);
void trim_input(char * input);
void redirect(char** cmd, int index);
int pipe_func(char** cmd, int index);
#endif
