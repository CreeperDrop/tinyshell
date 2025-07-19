#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <fcntl.h>
#define PROMPT "tinyshell># "
#define MAX_CMD_CHAR_COUNT 200
#define MAX_CMD_WORD_COUNT 200
#define MAX_CMD_WORD_LENGTH 200
#define MAX_DIRS 100

typedef enum {
	BUILTIN_NONE = -1,
	BUILTIN_CD,
	BUILTIN_EXIT,
	BUILTIN_HELP,
	BUILTIN_COUNT
} builtin_t;

void read_line(char* line);
void print_line(char* line);
void get_first_word(char* str, char* first_word);
// int split_str (char* str, char** split);
int split_str (char* str, char** split, char delimit);
int execute_command(char* argc, char** argv);
int str_comp(char* str1, char* str2);
void str_concat(char* str1, char* str2, char* concat);
// int search_path(char* argc);
int search_path(char* argc, char* resolved_path);
void str_copy(char* src, char* dest);
builtin_t is_builtin(char* cmd);
void builtin_execute(builtin_t builtin_id, char** args);
void builtin_exit(int exit_code);
int builtin_cd (char* dir_path);
void builtin_help();
void sigint_handler();

extern char **environ;
extern int is_child_running;
