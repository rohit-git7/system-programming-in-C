#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
	int fd,fd1,n;
	char buff[1024];
	fd = creat("test.txt",0644);
	if(fd == -1)
	{
		perror("Error");
	}

	fd1 = open("test.txt",O_WRONLY);
	
	while(n=read(STDIN_FILENO,buff,1)>0)
	{
		write(fd1,buff,n);
	}
close(fd);
close(fd1);
return 0;
}
