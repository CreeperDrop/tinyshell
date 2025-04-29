#include "shell.h"
 
int split_str (char* str, char** split)
{
	int i = 0;
	int word_idx = 0;

	while (str[i] != '\0'){
		
		if(str[i] 

		if (str[i] != ' ' && str[i] != '\0')
			split[word_idx++] = &str[i];	

		while (str[i] != '\0' && str[i] != ' ')
			++i;

		if (str[i] != '\0')
			str[i++] = '\0';

	}
	
	split[word_idx] = NULL;

	return word_idx;
}

/*
int split_str (char* str, char** split)
{
	int word_idx = 0;
	int char_idx = 0;
	int i;

	for (i = 0; str[i] != '\0'; ++i){
		
		if (str[i] != ' '){
			split[word_idx][char_idx++] = str[i];
		} else if (char_idx > 0) {
			split[word_idx++][char_idx] = '\0';
			char_idx = 0;
		}
	}


	//if(char_idx > 0)
		split[word_idx][char_idx] = '\0';

	split[++word_idx] = NULL;
	



	return word_idx;
}
*/
void get_first_word(char* str, char* first_word)
{
	
	int i;

	for (i = 0; (str[i] != ' ' && str[i] != '\0' && str[i] != '\n'); ++i){

		first_word[i] = str[i];
	
	}

	first_word[i] = '\0';

	return;
}

		
