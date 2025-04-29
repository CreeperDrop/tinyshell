#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#define MAX_CMD_CHAR_COUNT 200
#define MAX_CMD_WORD_COUNT 200
#define MAX_CMD_WORD_LENGTH 200

void read_line(char* line);
void print_line(char* line);
void get_first_word(char* str, char* first_word);
int split_str (char* str, char** split);
void execute_command(char* argc, char** argv);
int str_comp(char* str1, char* str2);

extern char **environ;
