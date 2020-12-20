## SKSSH
By: Kelly Zhou, Sunny Li, and Serena Chan\
TNPG: Forked Child

### Features:
- Forks and executes commands
- Parses commands
- Unfinished: Redirection, Piping

---

### Attempted:
- Some issues with trimming whitespace (?)

---

### Bugs:
- Entering an empty line or an invalid command causes shell to require multiple "exit" to exit

---

### Files and Function Headers:
#### parse.c
  * Parses argument
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
