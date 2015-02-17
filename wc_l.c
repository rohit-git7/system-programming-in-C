#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(int argc, char *argv[])
{
	int n,count = 0;
	char buff[2];
	int fd = open(argv[1],O_RDONLY);
	
	while((n=read(fd,buff,1))>0)
	{
		buff[n] = '\0';
		
		if(buff[0] == '\n')
		{
			count++;
		}
	}

	printf("%d %s\n",count,argv[1]);
return 0;
}
