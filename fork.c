/*
Program to create and terminate processes (using fork(), wait(), exit())
getpid(): Get process ID
getppid(): get parent process ID
*/
#include<stdio.h>
#include<stdlib.h>//exit()
#include<unistd.h>//pid_t
int main()
{
	int status;
	pid_t pd;
	pd = fork();
	if(pd == -1)//fork() failed
	{
		perror("Error");
		exit(0);
	}
	else if(pd == 0)//child process
	{
		printf("Child process with process ID %d with parent process ID %d\n",getpid(),getppid());
	}
	else// parent process
	{
		wait(&status);// wait for the completion of child process
		// It is important to prevent creation of zombie processes
		printf("Parent process %d\n",getpid());
	}

return 0;
}
