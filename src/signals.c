#include "shell.h"

void sigint_handler()
{
	print_line("\nCaught SIGINT. Use 'exit' or Ctrl+D to exit TinyShell\n");
	print_line(PROMPT);
	fflush(stdout);
	return;
}
