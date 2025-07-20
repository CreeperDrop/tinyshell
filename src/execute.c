#include "shell.h"

int execute_command(char* argc, char** argv)
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
	int i;
	int j;
	int k;
	int is_background = 0;
	int is_append = 0;
	int is_create = 0;
	int is_pipe = 0;

	char *file_dest = NULL;
	int fd = -1;
	int pipe_fd[2] = {-1, -1};
//	char pipe_buffer[1024];
	char *cmd1[10];
	char *cmd2[10];

	for (i = 0; argv[i] != NULL; ++i){
		if(argv[i][0] == '&'){
			is_background = 1;
			argv[i] = NULL;
		}

	}

	for (i = 0; argv[i] != NULL; ++i){
		if(argv[i][0] == '|'){
			is_pipe = 1;
			argv[i] = NULL;

			for(j = 0; argv[j] != NULL; ++j)
				cmd1[j] = argv[j];
			
			cmd1[j] = NULL;

			for(k = 0, j = i+1; argv[j] != NULL; ++k, ++j)
				cmd2[k] = argv[j];
			
			cmd2[k] = NULL;

			break;
		}

	}

	for(i = 0; argv[i] != NULL; ++i){

		if(argv[i][0] == '>'){
			if(argv[i][1] == '>')
				is_append = 1;
			else
				is_create = 1;

			file_dest = argv[i+1];
			argv[i] = NULL;

		}
	}

	if(is_pipe){
		
//		for(i = 0; cmd1[i] != NULL; ++i)
//			printf("cmd1[%d] = %s\n", i, cmd1[i]);
//		for(i = 0; cmd2[i] != NULL; ++i)
//			printf("cmd2[%d] = %s\n", i, cmd2[i]);
	
		if(pipe(pipe_fd) == -1) {
			perror("pipe");
			return 1;
		}

		pid_t pid1 = fork();


		switch (pid1){
			case -1:
				perror("fork");
				break;
			case 0:
			/*
				if(is_create){
					fd = open(file_dest, O_WRONLY | O_CREAT | O_TRUNC, 0666);
					if(fd == -1){
						printf("Can't open file %s\n", file_dest);
						return 1;
					}
					dup2(fd, 1);  // stdout go to file
					dup2(fd, 2);  // stderr go to file
				}
				if(is_append){
					fd = open(file_dest, O_WRONLY | O_CREAT | O_APPEND, 0666);
					if(fd == -1){
						printf("Can't open file %s\n", file_dest);
						return 1;
					}
					dup2(fd, 1);  // stdout go to file
					dup2(fd, 2);  // stderr go to file
				}
			*/
				dup2(pipe_fd[1], STDOUT_FILENO);
				close(pipe_fd[0]);
				close(pipe_fd[1]);
				execvp(cmd1[0], cmd1); // --> This uses internal PATH search
			//	close(fd);
				perror("execve");
				_exit(EXIT_FAILURE);
				break;
			default:
				
			//	if(!is_background)
			//	close(pipe_fd[0]);
			//	close(pipe_fd[1]);
			//	waitpid(pid1, NULL, 0);
			//	else
			//		printf("Background PID: %d\n", pid);

				break;
		}

		pid_t pid2 = fork();
		switch (pid2){
			case -1:
				perror("fork");
				break;
			case 0:
			/*
				if(is_create){
					fd = open(file_dest, O_WRONLY | O_CREAT | O_TRUNC, 0666);
					if(fd == -1){
						printf("Can't open file %s\n", file_dest);
						return 1;
					}
					dup2(fd, 1);  // stdout go to file
					dup2(fd, 2);  // stderr go to file
				}
				if(is_append){
					fd = open(file_dest, O_WRONLY | O_CREAT | O_APPEND, 0666);
					if(fd == -1){
						printf("Can't open file %s\n", file_dest);
						return 1;
					}
					dup2(fd, 1);  // stdout go to file
					dup2(fd, 2);  // stderr go to file
				}
			*/
				dup2(pipe_fd[0], STDIN_FILENO);
				close(pipe_fd[0]);
				close(pipe_fd[1]);
				execvp(cmd2[0], cmd2); // --> This uses internal PATH search
			//	close(fd);
				perror("execve");
				_exit(EXIT_FAILURE);
				break;
			default:
				
			//	if(!is_background)
			//	close(pipe_fd[0]);
			//	close(pipe_fd[1]);
			//	waitpid(pid2, NULL, 0);
			//	else
			//		printf("Background PID: %d\n", pid);

				break;
		}
				close(pipe_fd[0]);
				close(pipe_fd[1]);
				waitpid(pid1, NULL, 0);
				waitpid(pid2, NULL, 0);
		return 0;
	}

	pid_t pid = fork();
//	siginfo_t info;


	switch (pid){
		case -1:
			perror("fork");
			break;
		case 0:
		//	execve(resolved_path, argv, environ); // --> This creates problem because str_split

			if(is_create){
				fd = open(file_dest, O_WRONLY | O_CREAT | O_TRUNC, 0666);
				if(fd == -1){
					printf("Can't open file %s\n", file_dest);
					return 1;
				}
				dup2(fd, 1);  // stdout go to file
				dup2(fd, 2);  // stderr go to file
			}
			if(is_append){
				fd = open(file_dest, O_WRONLY | O_CREAT | O_APPEND, 0666);
				if(fd == -1){
					printf("Can't open file %s\n", file_dest);
					return 1;
				}
				dup2(fd, 1);  // stdout go to file
				dup2(fd, 2);  // stderr go to file
			}

		 	execvp(argc, argv); // --> This uses internal PATH search
			close(fd);
			perror("execve");
			_exit(EXIT_FAILURE);
			break;
		default:
			is_child_running = 1;
			
			if(!is_background)
				waitpid(pid, NULL, 0);
			else
				printf("Background PID: %d\n", pid);

			is_child_running = 0;
			break;
	}


	return 0;
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

