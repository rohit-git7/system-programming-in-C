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
	char buff[2],last = ' ';
	int fd=open(argv[1],O_RDONLY);//open file for reading
	
	while((n=read(fd,buff,1))>0)
	{
		buff[n] = '\0';
		if(buff[0] == ' ' || buff[0] == '\t' || buff[0] == '\n')
		{
			count++;
			if(last == ' '|| last == '\t' || last == '\n')
			count--;
		}
		last = buff[0];
	}
	printf("%d %s\n",count,argv[1]);
return 0;
}
