#include<stdio.h>
#include<dirent.h>
#include<string.h>
#include<sys/stat.h>
#include<grp.h>
#include<pwd.h>
#include<time.h>

int main(int argc,char *argv[])
{
 	char dir_name[100];
	char time_buff[200]; 
	struct dirent *entry;
	struct stat buff;
	struct tm *info;
	struct group *gp;		
	struct passwd *pw;

	 if(argc == 1)
	{
		strcpy(dir_name,".");
	}
	else
	{
		strcpy(dir_name,argv[1]);
	}
	
	DIR *d = opendir(dir_name);

	while((entry = readdir(d))!=NULL)
	{
		stat(entry->d_name,&buff);
	   	struct group *gp = getgrgid(buff.st_gid);		
		struct passwd *pw = getpwuid(buff.st_uid);
		info = localtime(&(buff.st_mtime));
		strftime(time_buff,sizeof(time_buff),"%b %d %H:%M",info);
	   if(strcmp(entry->d_name,".")!=0 && strcmp(entry->d_name,"..")!=0)
 		{
 
		if(buff.st_mode & S_IFREG)
			printf("-");
		else
		 if(buff.st_mode & S_IFDIR)
                        printf("d");
		else
		  if(buff.st_mode & S_IFBLK)
			printf("b");
		else
		  if(buff.st_mode & S_IFCHR)
			printf("c");

		if(buff.st_mode & S_IRUSR)
			printf("r");
		else
			printf("-");

		if(buff.st_mode & S_IWUSR)
			printf("w");
		else
			printf("-");

		if(buff.st_mode & S_IXUSR)
			printf("x");
		else
			printf("-");

		if(buff.st_mode & S_IRGRP)
			printf("r");
		else
			printf("-");

		if(buff.st_mode & S_IWGRP)
			printf("w");
		else
			printf("-");

		if(buff.st_mode & S_IXGRP)
			printf("x");
		else
			printf("-");

		if(buff.st_mode & S_IROTH)
			printf("r");
		else
			printf("-");

		if(buff.st_mode & S_IWOTH)
			printf("w");
		else
			printf("-");
			
		if(buff.st_mode & S_IXOTH)
			printf("x");
		else
			printf("-");
		
		printf(" %d %s %s %4d %s %s\n",buff.st_nlink,pw->pw_name,gp->gr_name,(int)buff.st_size,time_buff,entry->d_name);
		}
	}
	return 0;
}
