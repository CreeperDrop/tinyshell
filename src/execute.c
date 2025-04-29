#include "shell.h"

void execute_command(char* argc, char** argv)
{
	
	pid_t pid = fork();

	switch (pid){
		case -1:
			perror("fork");
			// exit(EXIT_FAILURE);
			break;
		case 0:
			// puts("Child exiting!");
			// exit(EXIT_SUCCESS);
			execve(argc, argv, environ);
			perror("execve");
			exit(EXIT_FAILURE);
			break;
		default:
			printf("Child PID is %d\n", (int) pid);
			// puts("Parent exiting!");
			siginfo_t info;
			waitid(P_ALL, 0, &info, WEXITED);
			// exit(EXIT_SUCCESS);
			break;
	}


	return;
}
				
