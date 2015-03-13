#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define MAX_STR     1024
#define MAX_COUNT   1024

char** str_split(char* str,char delim)
{
	char **results = malloc(sizeof(char*)*MAX_COUNT);
	char c;
	char * substr = malloc(MAX_STR);
	int i = 0;
	int j = 0;
	int r = 0;
	while(c=str[i++]){
		if (c!=delim)
		{
			substr[j++] = c;
		}
		else
		{
			substr[j++] = '\0';
			results[r++] = substr;
			substr = malloc(MAX_STR);
			j = 0;
		}
	}
	results[r] = substr;
	return results;
}


