#include "shell.h"


int is_child_running = 0;
char history[200][10];
int hist_ptr = 0;

int main()
{

	char line[200];
	char *cmd[20]; 
	char *argc;

	signal(SIGINT, sigint_handler);
	
	while(1) {
		print_line(PROMPT);
		read_line(line);

		if (line[0] == '\0')
			continue;

		str_copy(line, history[hist_ptr]);

		if(hist_ptr+1 == 10)
			hist_ptr = 0;
		else
			++hist_ptr;

		split_str(line, cmd, ' ');

		argc = cmd[0];
		
		builtin_t cmd_type = is_builtin(argc); 

		if (cmd_type != -1) {
			builtin_execute(cmd_type, cmd);
			continue;
		}

		int status = execute_command(argc, cmd);
		
		if(status == 1)
			printf("An error happened\n");

	}
	return 0;
}
