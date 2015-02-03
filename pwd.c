/*
Implementing linux command 'pwd' in C
*/

#include<stdio.h>

int main(int argc,char *argv[])
{
	char dir_name[1024];
	getcwd(dir_name,sizeof(dir_name));//get name of current working directory in string
	printf("%s\n",dir_name);
	
return 0;
}
