#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char* my_strsep(char** strp,const char* delim)
{
	char* str = *strp;
	if(str==NULL){
		return NULL;
	}
	char* ret_str = malloc(strlen(str));

	int i = 0;
	int j = 0;
	int r = 0;
	while(1){
		char* delimstr = malloc(strlen(delim)+1);
		int d = 0;
		int complete = 0;
		int found = 0;
		if(!str[i]){
			*strp = NULL;
			break;
		}
		while(str[i]==delim[j]){
			delimstr[d++] = str[i];
			i++;
			j++;
			if(!str[i]){
				complete = 1;
				break;
			}
			if(!delim[j]){
				found = 1;
				break;
			}
		}
		if(found){
			ret_str[r] = 0;
			*strp = str+i;
			break;
		}
		if(complete){
			*strp = NULL;
			break;
		}
		if(d>0){
			int t = 0;
			while(t<d){
				ret_str[r++] = delimstr[t++];
			}
		}
		ret_str[r++] = str[i];
		i++;
	}
	return ret_str;
}

int main(int argc, char *argv[])
{
	char* str = strdup("a*c");
	char* r;
	while(r=my_strsep(&str,"*")){
		printf("r:%s\n",r);
	}
	return 0;
}
