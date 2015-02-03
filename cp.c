#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

void func(char first_file[],char second_file[])
{
	char ch;
	char buffer[1024];
	int fd1,fd2,n;

		if(access(first_file,F_OK)!=0)
		{
			perror("Error");
			exit(0);
		}
		
		if(access(second_file,F_OK)==0)
                {
                     printf("A file with name %s is already present. Want to overwrite? ",second_file);
		 ch=getchar();
			
		if(ch!='y'||ch!='Y')
                        exit(0);
                
		}
	
		fd1 = open(first_file,O_RDONLY);
		
		if(fd1 == -1)
		{
			perror("Error");
			exit(0);
		}
	
		fd2 = open(second_file,O_WRONLY|O_CREAT|O_TRUNC);
		
		if(fd2 == -1)
		{
			perror("Error");
			exit(0);
		}
		
		while((n=read(fd1,buffer,sizeof(buffer)))>0)
		{
			write(fd2,buffer,n);
		}
	close(fd1);
	close(fd2);
}

int main(int argc, char *argv[])
{
	int i;

	if(argc <3)
	{
		printf("Error: Too few arguments!!\n");
		exit(0);
	}
	else
	if(argc ==3)
	{
		func(argv[1],argv[2]);
	}
	else
	{
		for(i=1;i<argc-1;i++)
		{
			func(argv[i],argv[argc-1]);
		}
		
	}
return 0;
}
