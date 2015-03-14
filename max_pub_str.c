/*
 * 在str1和str2中寻找最长公共子串
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* find_max_pub_str(char* str1,char* str2)
{
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int min_len = len1<len2?len1:len2;

	char* pub_str = malloc(min_len);
	int i = 0;

	int max_len = 0;
	while(1){
		int j = 0;
		if(!str1[i] || !str2[j]){
			break;
		}
		char* tempstr = malloc(min_len);
		while(j<len2){
			int ti = i;
			int t = 0;
			while(str1[ti]==str2[j]){
				tempstr[t++] = str1[ti];
				ti++;
				j++;
				if(!str1[ti] || !str2[j]){
					break;
				}
			}
			if(t>max_len){
				max_len = t;
				strcpy(pub_str,tempstr);
			}
			j++;
		}
		i++;
	}
	return pub_str;
}

int main(int argc, char *argv[])
{
	char* s1 = "abcdefcdehxzcde";
	char* s2 = "abcxzcdehv";
	char* result_str = find_max_pub_str(s1,s2);
	printf("result:%s\n",result_str);
	return 0;
}
