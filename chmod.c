#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<string.h>
int main(int argc, char *argv[])
{
	int res;
	mode_t mode = strtol(argv[1],NULL,8);
	res = chmod(argv[2],mode);

	if(res == -1)
	{
		perror("Error");
		exit(0);
	}

return 0;
}
