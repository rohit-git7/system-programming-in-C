#include<stdio.h>
#include<unistd.h>
int main()
{
	int status;
	pid_t pd;
	pd = fork();
	if(pd == -1)
	{
		perror("Error");
	}
	else if(pd == 0)
	{
		printf("Child process with process ID %d with parent process ID %d\n",getpid(),getppid());
	}
	else
	{
		wait(&status);
		printf("Parent process %d\n",getpid());
	}

return 0;
}
