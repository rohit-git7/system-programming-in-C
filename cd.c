#include<stdio.h>
int main(int argc, char *argv[])
{
	char buffer[1024];
	/*
	if(chdir("..")!=-1)
	{
		getcwd(buffer,sizeof(buffer));
        	printf("%s\n",buffer);
	}
	else
	{
		perror("Error");
	}*/
	if(chdir(argv[1])!=-1)
	{
		getcwd(buffer,sizeof(buffer));
        	printf("Directory changed to %s\n",buffer);
	}
	else
	{
		perror("Error");
	}
return 0;
}
