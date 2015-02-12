/*
Simple program to show use of lseek() in file operations.
STDOUT_FILENO 1 : File descriptor for Standard output
SEEK_SET 0 : Macro for seeking from beginning of file
SEEK_CUR 1 : Macro for seeking from current position of file pointer
SEEK_END 2 : Macro for seeking from end of file
*/

#include<stdio.h>
#include<fcntl.h>//read() write()
#include<unistd.h>//for MACROS
int main()
{
	
	int fd,n;
	char buff[1024];
	fd = open("file.txt",O_RDONLY);//open an existing file in read only mode
	lseek(fd,0,SEEK_SET);//put file pointer at the beginning of file
	while((n=read(fd,buff,sizeof(buff)))>0)
	{
		write(STDOUT_FILENO,buff,n);
	}
	
	lseek(fd,-5,SEEK_CUR);//move file pointer back by 5 positions from its current position
	while((n=read(fd,buff,sizeof(buff)))>0)
	{
		write(STDOUT_FILENO,buff,n);
	}
	
	lseek(fd,-5,SEEK_END);//move file pointer back by 5 positions from the end of file
	while((n=read(fd,buff,sizeof(buff)))>0)
	{
		write(STDOUT_FILENO,buff,n);
	}
	
	return 0;
}
