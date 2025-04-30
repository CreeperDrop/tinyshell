#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#define MAX_CMD_CHAR_COUNT 200
#define MAX_CMD_WORD_COUNT 200
#define MAX_CMD_WORD_LENGTH 200
#define MAX_DIRS 100

void read_line(char* line);
void print_line(char* line);
void get_first_word(char* str, char* first_word);
// int split_str (char* str, char** split);
int split_str (char* str, char** split, char delimit);
void execute_command(char* argc, char** argv);
int str_comp(char* str1, char* str2);
void str_concat(char* str1, char* str2, char* concat);
// int search_path(char* argc);
int search_path(char* argc, char* resolved_path);
void str_copy(char* src, char* dest);

extern char **environ;
extern char *path_env;
extern char *PATH;
//extern char *dirs[MAX_DIRS];
