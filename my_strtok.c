#include <stdio.h>
#include <malloc.h>
#include <string.h>

static char* str;
// implementation of strtok
char* my_strtok(char* cur_str,const char* delim)
{
	if(cur_str!=NULL) str = cur_str;

	char* ret_str = malloc(strlen(str)+1);

	int i = 0;
	int j = 0;
	int r = 0;
	int found = 0;
	while(str[i]) {
		int complete = 0;
		char* delimstr = malloc(strlen(delim)+1);
		int d = 0;
		while(str[i]==delim[j]) {
			delimstr[d++] = str[i];
			i++;
			j++;
			if(!str[i]) {
				complete = 1;
				break;
			}
			if(!delim[j]){
				found = 1;
				break;
			}
		}
		if(found){
			break;
		}else{
			if(d>0){
				int t = 0;
				for(;t<d;t++){
					ret_str[r+t] = delimstr[t];
				}
			}else{
				ret_str[r++] = str[i];
			}
		}
		if(complete){
			if(d>0){
				int t = 0;
				for(;t<d;t++){
					ret_str[r+t] = delimstr[t];
				}
			}else{
				ret_str[r++] = str[i];
			}
			break;
		}
		i++;
	}
	str = str + i;
	return ret_str;

}

int main(int argc, char *argv[])
{
	char* str = my_strtok("abcheeeee","h");
	char* s2 = my_strtok(NULL,"h");
	printf("str:%s\n",str);
	printf("s2:%s\n",s2);
	return 0;
}
