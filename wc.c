#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(int argc, char *argv[])
{
	int n,count = 0;
	char buff[5];
	int fd=open(argv[1],O_RDONLY);
	
	while((n=read(fd,buff,1))>0)
	{
		buff[n] = '\0';
		if(buff[0] == ' ' ||buff[0] == '\t' || buff[0] == '\n')
			count++;
	}
	printf("%d\n",count);
return 0;
}
