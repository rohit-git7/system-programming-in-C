/*
Implementing linux command 'chmod' in C.
To run:
	./executable mode filename
*/
#include<stdio.h>
#include<stdlib.h>//exit()
#include<sys/stat.h>//chmod()
#include<string.h>//strtol()
int main(int argc, char *argv[])
{
	if(argc < 3)
	{
		printf("Too few arguments\n");
		exit(0);
	}
	else if(argc > 3)
	{
		printf("Too many arguments\n");
		exit(0);
	}
	
	int res;
	mode_t mode = strtol(argv[1],NULL,8);//change string to mode type
	res = chmod(argv[2],mode);
	if(res == -1)//error
	{
		perror("Error");
		exit(0);
	}

return 0;
}
