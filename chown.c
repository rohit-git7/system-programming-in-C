#include<stdio.h>
#include<stdlib.h>
#include<pwd.h>

int main(int argc,char *argv[])
{
	struct passwd *pass;
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
	
	pass = getpwnam(argv[1]);

	res = chown(argv[3],pass->pw_uid,pass->pw_gid);
	if(res == -1)
	{
		perror("Error");
		exit(0);
	}

return 0;
}
