#include <string.h>
#include <stdio.h>

int shift_str(char* arr,int len,int shift)
{
	// shift by one
	while(shift-->0){
		int i;
		int t = arr[0];
		for(i=0;i<len-1;i++){
			arr[i] = arr[i+1];
		}
		arr[len-1] = t;
	}
	return 0;
}

int main(int argc, char *argv[])
{
	char* str = strdup("abcdefgh");
	shift_str(str,8,3);
	printf("str:%s\n",str);
	return 0;
}
