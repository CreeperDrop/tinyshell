#include "shell.h"

void read_line(char* line)
{
	char c;
	int i = 0;

	while ( (c = getchar()) != '\n') {
		
		if (c != '\b'){
			line[i++] = c;
		} else {
			line[i--] = '\0';	
		}

	}
	
	if (line[i] != '\0')
		line[i] = '\0';

	return;
}

void print_line(char* line)
{
	int i;

	for (i = 0; line[i] != '\0'; ++i)
		putchar(line[i]);
	
	return;
}

int str_comp(char* str1, char* str2)
{
	while (*str1 && *str2){
		if(*str1 != *str2)
			return 1;
		++str1;
		++str2;
	}

	return !(*str1 == *str2);
}
