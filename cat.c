/*
Implementing linux command 'cat' using C.
To run:
	./executable file_1 file_2 file_3 ... file_n
*/
#include<stdio.h>
#include<fcntl.h>//open()
#include<unistd.h>//read() write()
#include<string.h>//strcpy() bzero()
#include<stdlib.h>//exit()

int main(int argc, char *argv[])
{
	char file[1024];
	char buffer[1024];
	char err[1024];
	int n,i,fd;
	
	if(argc < 2)//no file name specified
	{
		printf("No file name specified\n");
		exit(1);
	}
	
	for(i = 1;i < argc; i++)//for each file
	{
		strcpy(file,argv[i]);
		strcpy(err,"cat: ");
		strcat(err,file);

		fd = open(file,O_RDONLY);
		if(fd == -1)//error in opening file
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
