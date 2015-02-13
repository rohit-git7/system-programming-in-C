/*
Implementing linux comand 'chown'
To run:
	./executable user_name group_name file_name
*/
#include<stdio.h>
#include<stdlib.h>//exit()
#include<pwd.h> // getpwnam()

int main(int argc,char *argv[])
{
	struct passwd *pass;//structure to get information from passwd file
	int res;

	if(argc < 4)
	{
		printf("Too few arguments\n");
		exit(0);
	}
	else if(argc > 4)
	{
		printf("Too many arguments\n");
		exit(0);
	}
	
	pass = getpwnam(argv[1]);//get user details from 'passwd' file

	res = chown(argv[3],pass->pw_uid,pass->pw_gid);
	if(res == -1)//error
	{
		perror("Error");
		exit(0);
	}

return 0;
}
