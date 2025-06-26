#include "shell.h"

void read_line(char* line)
{
	int c;
	int i = 0;

	while ( ((c = getchar())) != '\n') {
		
		if (c == EOF) {
			putchar('\n');
			exit(0);
		}
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

void str_concat(char* str1, char* str2, char* concat)
{
	int i;
	int j;

	for (i = 0; str1[i] != '\0'; ++i)
		concat[i] = str1[i];

	for (j = 0; str2[j] != '\0'; ++j, ++i)
		concat[i] = str2[j];
	
	concat[i] = '\0';
	
	return;
}
/*
void str_copy(char* src, char* dest) {
    while (*src) {
        *dest++ = *src++;
    }
    *dest = '\0';
}
*/
void str_copy(char* src, char* dest)
{
	int i;

	for (i = 0; src[i] != '\0'; ++i)
		dest[i] = src[i];
	
	dest[i] = '\0';

	return;
}

