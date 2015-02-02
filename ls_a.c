/*
Implementing linux command 'ls -a dir_name' in C i.e to list all files(including hidden files)
*/
#include<stdio.h>
#include<dirent.h>
#include<string.h>

int main(int argc,char *argv[])
{
 	char dir_name[100];
 //if no directory name is given by user, run for current directory
	 if(argc == 1)
	{
		strcpy(dir_name,".");
	}
	else
	{
		strcpy(dir_name,argv[1]);
	}

	DIR *d = opendir(dir_name);//open directory list
	struct dirent *entry;
	while((entry = readdir(d))!=NULL)//reading directory
	{
 		printf("%s\n",entry->d_name);
	}
	return 0;
}
