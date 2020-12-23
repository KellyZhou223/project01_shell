#ifndef SHELL_H
#define SHELL_H
void run_command(char** command);
void trim_input(char * input);
void redirect(char** cmd, int index);
void pipe_func(char * input, int index);
#endif
