#include "shell.h"

int main()
{

	char line[200];
	char *cmd[20]; 
	char *argc;
//	int i;

	while(1) {
	//	for (i = 0; i < 22/* environ[i] != NULL */; ++i)
	//		printf("environ[%d]: %s\n", i, environ[i]);
		print_line("tinyshell># ");
		read_line(line);

		// for (i = 0; i < 20; i++) {
		// 	cmd[i] = malloc(MAX_CMD_WORD_LENGTH * sizeof(char));  // Allocate memory for each word
		//	if (cmd[i] == NULL) {  // Ensure memory allocation succeeded
		//		printf("Memory allocation failed for cmd[%d]\n", i);
		//		return 1;  // Exit if allocation fails
		//	}
		// }


		if (line[0] == '\0')
			continue;

		split_str(line, cmd, ' ');

		argc = cmd[0];
		
		builtin_t cmd_type = is_builtin(argc); 

		if (cmd_type != -1) {
			builtin_execute(cmd_type, cmd);
			continue;
		}

		execute_command(argc, cmd);

//		for (i = 0; cmd[i] != NULL; ++i){
//			printf("cmd[%d]: %s\n", i, cmd[i]);
//		}

	//	free(*cmd);
	}
	return 0;
}
