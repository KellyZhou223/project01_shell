# SKSSH
By: Kelly Zhou, Sunny Li, and Serena Chan\
TNPG: Forked Child

## Features:
- Forks and executes commands
- Handles multiple commands on one line using ";" as a delimiter (no spaces before or after ";")
- Parses commands

---

## Attempted:
- Some issues with trimming whitespace (?)
- Redirection may not work (?)
- An outline for pipes

---

## Bugs:
- Entering an empty line or an invalid command causes shell to require more "exit" to exit
- Calling redirection/pipe functions causes shell to require more "exit" to exit (?)
- When running multiple commands on one line, including a space before and after ; will not work
  (ex. ls -l ; echo hello does not work, but ls -l;echo hello does)

---

## Files and Function Headers:
### parse.c
  * Parses both singular and multiple commands in one line
  ```
  /*======== int count_tokens() ==========
  Inputs:  char *line
           char delim
  Returns: Number of commands in line separated by delim

  Keeps track of the number of times delim (";") appears in the line
  *?* If delim is not found, there are no multiple commands, therefore, 1 is returned
  *?* The number of commands (tokens) is one more than the number of appearances of delim
  ====================*/

  /*======== char ** parse_args() ==========
  Inputs:  char *line
           char delim
  Returns: An array of strings where each index is a separate command
  
  Goes through the line, takes each command (differenciated by delim) and enters into an array
  Makes sure the last value in the array is a terminating null character
  ====================*/
  
  /*======== void ** print_args() ==========
  Inputs:  char **a
  Output: Prints every argument contained in line

  Takes in array from parse_args, prints the arguments
  ====================*/

  /*======== char * trim() ==========
  Inputs:  char *line
  Returns: Pointer to the beginning of line

  Removes leading and trailing whitespace in the line by replacing the first and last term
  Terminating '\0' is placed at the end of the string if the last term is whitespace
  ====================*/  
  ```

### parse.h
  * Header file for parse.c

### shell.c
  * Forks and executes the command, also does redirecting and piping 
  ```
  /*======== void run_command() ==========
  Inputs:  char **command
  Output: Runs the command supplied by user
  
  Checks for redirection and pipe symbols and directs the command call to the necessary functions
  Takes care of forking
  Detects cd and exit in the command, uses chdir and exit respectively 
  ====================*/
  
  /*======== int length_input() ==========
  Inputs:  char *input
  Returns: Length of the inputted string 
  
  ====================*/
  
  /*======== void trim_input() ==========
  Inputs:  char *input

  Replaces all occurrences of spaces in string with whitespace (to allow for run function to work properly)  
  ====================*/ 
  
  /*======== void redirect(char ** cmd, int index) ==========
  Inputs:  char **cmd, int index
  
  Redirects input by detecting redirection symbols ("<", ">", ">>").
  ====================*/
  
  /*======== int pipe_func(char ** cmd, int index) ==========
  Inputs:  char **cmd, int index
  
  Pipes commands; the output of the first command is used as the input for the second
  ====================*/
  ```

### shell.h
  * Header file for shell.c
