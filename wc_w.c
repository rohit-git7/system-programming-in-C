/*
Implement linux command 'wc -w' in C.
To run:
	./executable file_name
*/
#include<stdio.h>
#include<fcntl.h>//read() open()
#include<unistd.h>//O_RDONLY
int main(int argc, char *argv[])
{
	int n,count = 0;
	char buff[2];
	int fd=open(argv[1],O_RDONLY);//open file for reading
	
	while((n=read(fd,buff,1))>0)
	{
		buff[n] = '\0';
		if(buff[0] == ' ' ||buff[0] == '\t' || buff[0] == '\n')//count words
			count++;
	}
	printf("%d\n",count);
return 0;
}
