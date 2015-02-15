/*
Implementing basic file operations in C.
creat()
open()
read()
write()
close()
STDIN_FILENO: file descriptor for standard input. we cn also use '0'
STDOUT_FILENO: file descriptor for standard output. we cn also use '1'
*/

#include<stdio.h>
#include<fcntl.h>// for read() write() open() creat()
#include<unistd.h>// O_WRONLY STDOUT_FILENO STDIN_FILENO
int main()
{
	int fd,fd1,n;
	char buff[1024];
	fd = creat("test.txt",0644);// create a file if not present. otherwise it will truncate file to zero
	if(fd == -1)
	{
		perror("Error");//report error if file canot be created
	}

	fd1 = open("test.txt",O_WRONLY);// open file in write only mode. we can also use O_CREAT flag with open() to create file if it is not present 
	if(fd1 == -1)
	{
		perror("Error");//report error if file cannot be opened
	}
	while((n=read(STDIN_FILENO,buff,1))>0)// reading from standard input
	{
		write(fd1,buff,n);//writing to file with file descriptor fd1
	}
close(fd1);// close file
return 0;
}
