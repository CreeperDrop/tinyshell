#include "shell.h"

void execute_command(char* argc, char** argv)
{
	char resolved_path[MAX_CMD_WORD_LENGTH] = {0};

	printf("argc: %s\n", argc);
	if (!((argc[0] == '/') || (argc[0] == '.' && argc[1] == '/'))){

		if(search_path(argc, resolved_path) != 0){
			printf("Cannot Resolve Path\n");
			return;
		}

	} else {
		printf("Using abs path.. \n");
		str_copy(argc, resolved_path);
	}

	
	pid_t pid = fork();

	switch (pid){
		case -1:
			perror("fork");
			break;
		case 0:
			printf("resolved_path: %s\n", resolved_path);
			printf("PATH before execve: %s\n", getenv("PATH"));
			execve(resolved_path, argv, environ);
			printf("PATH after execve: %s\n", getenv("PATH"));
			perror("execve");
			exit(EXIT_FAILURE);
			break;
		default:
			printf("Child PID is %d\n", (int) pid);
			// puts("Parent exiting!");
			siginfo_t info;
			waitid(P_ALL, 0, &info, WEXITED);
			printf("PATH in parent execve: %s\n", getenv("PATH"));
			resolved_path[0] = '\0';
			// exit(EXIT_SUCCESS);
			break;
	}


	return;
}

int search_path(char* argc, char* resolved_path)
{
		
//	char *path_env = getenv("PATH");
	char *dirs[200] = {0};
	char argc_mod[20];
	char full_path[200];
	int i;
	
	printf("PATH: %s\n", PATH);
	split_str(PATH, dirs, ':');
	for(i = 0; i < 5; ++i)
		printf("dirs[%d]: %s\n", i, dirs[i]);
	
	str_concat("/", argc, argc_mod);
	// printf("argc_mod: %s\n", argc_mod);
	

	for (i = 0; dirs[i] != NULL; ++i){

		str_concat(dirs[i], argc_mod, full_path);
		printf("i:%d\tdirs[i]:%s\targc_mod:%s\tfull_path:%s\n", i, dirs[i], argc_mod, full_path);
		
		if(access(full_path, X_OK) == 0){
	//		printf("full_path: %s\n", full_path);
			str_copy(full_path, resolved_path);
			return 0;
		} else {
			printf("Cannot find the path specified\n");	
		}	
	}
	return 1;
}

