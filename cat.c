#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
	char file[1024];
	char buffer[1024];
	char err[1024];
	int n,i,fd;
	
	if(argc < 2)
	{
		printf("No file name specified\n");
		exit(1);
	}
	
	for(i = 1;i < argc; i++)
	{
		strcpy(file,argv[i]);
		strcpy(err,"cat: ");
		strcat(err,file);

		fd = open(file,O_RDONLY);
		if(fd == -1)
		{
			perror(err);
			continue;
		}

		while((n = read(fd,buffer,sizeof(buffer))) > 0)
		{
			buffer[n]='\0';
			write(STDOUT_FILENO,buffer,n);
		}
		
		bzero(file,sizeof(file));
	}

return 0;
}
