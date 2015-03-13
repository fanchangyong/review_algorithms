#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

/*
 * 给定以下字符串:
 * a b
 * a c
 * b d
 * c f
 * 输出:
 * a
 *   b
 *     d
 *   c
 *     f
 */

struct topic_relation{
	char* father;
	char* child;
};



int main(int argc, char *argv[])
{
	int fd = open("input.txt",O_RDONLY);
	if (fd==-1)
	{
		perror("open");
		exit(1);
	}

	off_t fsize = lseek(fd,SEEK_SET,SEEK_END);
	lseek(fd,SEEK_SET,0);
	char* buf = malloc(fsize);

	int n = read(fd,buf,1024);
	printf("buf: %s\n",buf);
	return 0;
}
