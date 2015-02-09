#include<stdio.h>
#include<string.h>
int main()
{
	char str[]="hello brother";
	int fd[2],n;
	char buff[100];
	pipe(fd);
	write(fd[1],str,strlen(str));
	if((n= read(fd[0],buff,sizeof(buff)))>0)
	{
		printf("read %d bytes from pipe: %s\n",n,buff);
	}
	else
	{
		perror("Error");
	}
	return 0;
}
