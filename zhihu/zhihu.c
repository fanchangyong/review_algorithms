#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


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

struct topic_relation* str2topic(char* str){
	struct topic_relation * ptr = malloc(sizeof(struct topic_relation));
	ptr->father = strdup(strtok(str," "));
	ptr->child = strdup(strtok(NULL," "));
	return ptr;
}

void pr_topic(struct topic_relation** all_topics,struct topic_relation* topic,
		int indent)
{
	int i;
	for(i=0;i<indent;i++){
		printf("  ");
	}
	printf("%s",topic->father);
	printf("\n");
	struct topic_relation** at = all_topics;
	struct topic_relation** childs = NULL;
	int child_count = 0;
	while(at && *at){
		if(strcmp(topic->child,(*at)->father)==0){
			++child_count;
			childs = realloc(childs,sizeof(struct topic_relation*)*child_count);
			childs[child_count-1] = *at;
		}
		at++;
	}
	struct topic_relation** tmp = childs;
	while(tmp && *tmp){
		pr_topic(all_topics,*tmp,indent+1);
		tmp++;
	}

	struct topic_relation** fathers = NULL;
	at = all_topics;
	while(at && *at){
		if(strcmp(topic->father,(*at)->father)==0){
			++child_count;
			fathers = realloc(fathers,sizeof(struct topic_relation*)*child_count);
			fathers[child_count-1] = *at;
		}
		at++;
	}
	tmp = fathers;
	while(tmp && *tmp){
		pr_topic(all_topics,*tmp,indent+1);
		tmp++;
	}
}


char** split_lines(char* str)
{
	int count = 0;
	char** lines=NULL;
	char* line = strtok(str,"\n");
	while(line){
		++count;
		lines = realloc(lines,count*sizeof(char*));
		lines[count-1] = strdup(line);
		line = strtok(NULL,"\n");
	}
	return lines;
}

int main(int argc, char *argv[])
{
	int fd = open("input.txt",O_RDONLY);
	if (fd==-1)
	{
		perror("open");
		exit(1);
	}

	off_t fsize = lseek(fd,SEEK_SET,SEEK_END);
	lseek(fd,SEEK_SET,0); // return to begin
	char* buf = malloc(fsize);
	int n = read(fd,buf,1024);
	if(n<0){
		perror("read");
		exit(1);
	}
	char** lines = split_lines(buf);
	struct topic_relation** all_topics=NULL;
	int topic_count = 0;
	while(lines && *lines){
		struct topic_relation* ptr = str2topic(*lines);
		++topic_count;
		all_topics = realloc(all_topics,
				topic_count*sizeof(struct topic_relation*));
		all_topics[topic_count-1] = ptr;
		lines++;
	}

	pr_topic(all_topics,all_topics[0],0);
	return 0;
}
