#include<stdio.h>
#include<string.h>

int main(int argc,char *argv[])
{
	char dir_name[1024];
	getcwd(dir_name,sizeof(dir_name));
	printf("%s\n",dir_name);
	
return 0;
}
