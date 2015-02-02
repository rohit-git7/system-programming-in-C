/*
Implementing linux command 'ls -l directory_name' in C i.e a detailed view of file permissions, number of links,
username, groupname, file size, time of modification, file name.
*/
#include<stdio.h>
#include<dirent.h> //struct dirent,opendir()
#include<string.h>
#include<sys/stat.h> // stat()
#include<grp.h> //getgrgid(),struct group
#include<pwd.h> //getpwuid(),struct passwd
#include<time.h> //strftime(), struct tm

int main(int argc,char *argv[])
{
 	char dir_name[100];
	char time_buff[200]; 
	struct dirent *entry;
	struct stat buff; //to store complete information about file
	struct tm *info; // to resolve st_mtime i.e time_t format to string format
	struct group *gp; // structure that gives groupname for group id
	struct passwd *pw; // struture that gives username for user id

// run program for current directory if no argument is passed
	 if(argc == 1)
	{
		strcpy(dir_name,".");
	}
	else
	{
		strcpy(dir_name,argv[1]);
	}
	
	DIR *d = opendir(dir_name);//open directory list

	while((entry = readdir(d))!=NULL)// read each file one by one
	{
		stat(entry->d_name,&buff); // get complete file information in object of structure stat
	   	struct group *gp = getgrgid(buff.st_gid);// get groupname from groupid
		struct passwd *pw = getpwuid(buff.st_uid);//get username from user id
		info = localtime(&(buff.st_mtime)); // getting mtime details in structure tm
		strftime(time_buff,sizeof(time_buff),"%b %d %H:%M",info); //getting required details from structure to string time_buff
	   if(strcmp(entry->d_name,".")!=0 && strcmp(entry->d_name,"..")!=0 && entry->d_name[0]!='.')//skip hidden files
 		{
 // checking file type
		if(buff.st_mode & S_IFREG) //file is regullar file
			printf("-");
		else
		 if(buff.st_mode & S_IFDIR)// file is directory
                        printf("d");
		else
		  if(buff.st_mode & S_IFBLK)// file is block device
			printf("b");
		else
		  if(buff.st_mode & S_IFCHR)// file is character device
			printf("c");
//checking permission bits that are set for file
		if(buff.st_mode & S_IRUSR)//owner can read
			printf("r");
		else
			printf("-");

		if(buff.st_mode & S_IWUSR)//owner can write
			printf("w");
		else
			printf("-");

		if(buff.st_mode & S_IXUSR)// owner can execute
			printf("x");
		else
			printf("-");

		if(buff.st_mode & S_IRGRP)// members of group can read
			printf("r");
		else
			printf("-");

		if(buff.st_mode & S_IWGRP)//members of group can write
			printf("w");
		else
			printf("-");

		if(buff.st_mode & S_IXGRP)// members of group can execute
			printf("x");
		else
			printf("-");

		if(buff.st_mode & S_IROTH)// everyone can read
			printf("r");
		else
			printf("-");

		if(buff.st_mode & S_IWOTH)//everyone can write
			printf("w");
		else
			printf("-");
			
		if(buff.st_mode & S_IXOTH)//everyone can execute
			printf("x");
		else
			printf("-");
		
		printf(" %d %s %s %4d %s %s\n",buff.st_nlink,pw->pw_name,gp->gr_name,(int)buff.st_size,time_buff,entry->d_name);
		}
	/*
	st_nlink= number of links
	pw_name = owner name
	gr_name= group name
	st_size = size of file
	*/
	}
	return 0;
}
