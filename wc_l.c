/*
Implementing linux command 'wc -l' in C.
To run:
	./executable file_name
*/
#include<stdio.h>
#include<fcntl.h>//open() read()
#include<unistd.h>//O_RDONLY
int main(int argc, char *argv[])
{
	int n,count = 0;
	char buff[2];
	int fd = open(argv[1],O_RDONLY);//open file for reading
	
	while((n=read(fd,buff,1))>0)//reading file
	{
		buff[n] = '\0';
		
		if(buff[0] == '\n')//counting newline characters
		{
			count++;
		}
	}

	printf("%d %s\n",count,argv[1]);
return 0;
}
