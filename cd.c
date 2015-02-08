/*
Implement linux command cd.
To run:
	./executable directory-name
*/
#include<stdio.h>
int main(int argc, char *argv[])
{
	char buffer[1024];
	/*
	if(chdir("..")!=-1)// to show usage of chdir()
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
		getcwd(buffer,sizeof(buffer));//to get name of current working directory
        	printf("Directory changed to %s\n",buffer);
	}
	else//returns -1 in case of an error
	{
		perror("Error");
	}
return 0;
}
