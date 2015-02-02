#include<stdio.h>
#include<dirent.h>
#include<string.h>

int main(int argc,char *argv[])
{
 	char dir_name[100];
 
	 if(argc == 1)
	{
		strcpy(dir_name,".");
	}
	else
	{
		strcpy(dir_name,argv[1]);
	}

	DIR *d = opendir(dir_name);
	struct dirent *entry;
	while((entry = readdir(d))!=NULL)
	{
	    if(strcmp(entry->d_name,".")!=0 && strcmp(entry->d_name,"..")!=0)
 			printf("%s\n",entry->d_name);
	}
	return 0;
}
