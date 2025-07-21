#include "shell.h"

builtin_t is_builtin(char* cmd)
{

	if (str_comp(cmd, "cd") == 0)
		return BUILTIN_CD;

	if (str_comp(cmd, "exit") == 0)
		return BUILTIN_EXIT;
	
	if (str_comp(cmd, "help") == 0)
		return BUILTIN_HELP;

	if (str_comp(cmd, "hist") == 0)
		return BUILTIN_HISTORY;
	
	return BUILTIN_NONE;

}

void builtin_execute(builtin_t builtin_id, char** args)
{
	switch (builtin_id){
		case BUILTIN_CD:
			builtin_cd(args[1]);
			break;

		case BUILTIN_EXIT:
			builtin_exit(0);
			break;

		case BUILTIN_HELP:
			builtin_help();
			break;
		
		case BUILTIN_HISTORY:
			builtin_history();
			break;

		default:
			print_line("Not a built-in command\n");
			break;

	return;
	}
}


void builtin_exit(int exit_code)
{
	exit(exit_code);
	return;
}

int builtin_cd (char* dir_path)
{
	if (dir_path == NULL || !str_comp(dir_path, "~")){
		char* home = getenv("HOME");

		if (home == NULL){
			print_line("cd: HOME not set\n");
			return 1;
		}
		chdir(home);
		print_line("Moved to ");
		print_line(home);
		print_line("\n");
		return 0;
	}
	
	if (chdir(dir_path) == 0) {
		print_line("Moved to ");
		print_line(dir_path);
		print_line("\n");
		return 0;
	} else {
		perror("chdir");
		return 1;
	}
}

void builtin_help()
{
	print_line("Help...\n");
	return;
}

void builtin_history()
{
	int i;
	// char *history[10];
	//  int hist_ptr;
	printf("hist_ptr = %d\n", hist_ptr);
	if (hist_ptr == 0){
		print_line("No history... \n");
		return;
	}

	for (i = 0; i <= hist_ptr; ++i)
		printf("%s\n", history[i]);

	return;
}
