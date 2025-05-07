#include "shell.h"

void execute_command(char* argc, char** argv)
{
	/*
	char resolved_path[MAX_CMD_WORD_LENGTH];

	if (!((argc[0] == '/') || (argc[0] == '.' && argc[1] == '/'))){

		if(search_path(argc, resolved_path) != 0){
			printf("Cannot Resolve Path\n");
			return;
		}

	} else {
		printf("Using abs path.. \n");
		str_copy(argc, resolved_path);
	}
	*/
	
	pid_t pid = fork();
	siginfo_t info;

	switch (pid){
		case -1:
			perror("fork");
			break;
		case 0:
		//	execve(resolved_path, argv, environ); // --> This creates problem because str_split
		 	execvp(argc, argv); // --> This uses internal PATH search
			perror("execve");
			_exit(EXIT_FAILURE);
			break;
		default:
			waitid(P_ALL, 0, &info, WEXITED);
			break;
	}


	return;
}

int search_path(char* argc, char* resolved_path)
{
		
	char *dirs[200] = {0};
	char argc_mod[20];
	char full_path[200];
	int i;
	
	printf("PATH: %s\n", getenv("PATH"));
	split_str(getenv("PATH"), dirs, ':');
	for(i = 0; i < 5; ++i)
		printf("dirs[%d]: %s\n", i, dirs[i]);
	
	str_concat("/", argc, argc_mod);

	for (i = 0; dirs[i] != NULL; ++i){

		str_concat(dirs[i], argc_mod, full_path);
	//	printf("i:%d\tdirs[i]:%s\targc_mod:%s\tfull_path:%s\n", i, dirs[i], argc_mod, full_path);
		
		if(access(full_path, X_OK) == 0){
			str_copy(full_path, resolved_path);
			return 0;
		} else {
			printf("Cannot find the path specified\n");	
		}	
	}
	return 1;
}

