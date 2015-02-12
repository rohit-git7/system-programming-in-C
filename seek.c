#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
	
	int fd,n;
	char buff[1024];
	fd = open("file.txt",O_RDONLY);
	lseek(fd,0,SEEK_SET);
	while((n=read(fd,buff,sizeof(buff)))>0)
	{
		write(STDOUT_FILENO,buff,n);
	}
	
	lseek(fd,-5,SEEK_CUR);
	while((n=read(fd,buff,sizeof(buff)))>0)
	{
		write(STDOUT_FILENO,buff,n);
	}
	
	lseek(fd,-5,SEEK_END);
	while((n=read(fd,buff,sizeof(buff)))>0)
	{
		write(STDOUT_FILENO,buff,n);
	}
	
	return 0;
}
