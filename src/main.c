#include "shell.h"

int main()
{
	char line[200];
	// char word[200];
	char *cmd[20]; 
	char *argc;
	// char **argv;
	 int i;
	// int word_count;
	while(1) {
		print_line("tinyshell># ");
		read_line(line);

		// for (i = 0; i < 20; i++) {
		// 	cmd[i] = malloc(MAX_CMD_WORD_LENGTH * sizeof(char));  // Allocate memory for each word
		//	if (cmd[i] == NULL) {  // Ensure memory allocation succeeded
		//		printf("Memory allocation failed for cmd[%d]\n", i);
		//		return 1;  // Exit if allocation fails
		//	}
		// }

		/* word_count = */ split_str(line, cmd);
		// printf("Word Count = %d\n", word_count);

		argc = cmd[0];
		if (!str_comp(argc, "exit"))
			return 0;

		execute_command(argc, cmd);

		for (i = 0; cmd[i] != NULL; ++i){
			printf("%s\n", cmd[i]);
		}

	//	free(*cmd);
	}
	return 0;
}
