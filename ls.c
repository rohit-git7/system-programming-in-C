/*
Implementing command `ls Directory-name` in C 
*/
#include<stdio.h>
#include<dirent.h>
#include<string.h> 

int main(int argc,char *argv[])
{
 	char dir_name[100];
 //if no directory name is given, run for current directory
	 if(argc == 1)
	{
		strcpy(dir_name,".");
	}
	else
	{
		strcpy(dir_name,argv[1]);
	}

	DIR *d = opendir(dir_name); // to open directory
	struct dirent *entry;
	while((entry = readdir(d))!=NULL) //read all entries one by one
	{
	    if(strcmp(entry->d_name,".")!=0 && strcmp(entry->d_name,"..")!=0 && entry.d_name[0]!='.')//don't print names of hidden files
 			printf("%s\n",entry->d_name);
	}
	return 0;
}
