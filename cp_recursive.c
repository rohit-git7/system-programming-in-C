/*
Program to copy one directory to another directory recursively.
*/
#include<stdio.h>
#include<dirent.h>//DIR opendir() readdir()
#include<unistd.h>//macros
#include<string.h>
#include<sys/stat.h>//stat()
#include<fcntl.h>//read() write() open()

void directory_recursive(char from_dir[],char dir[])
{
	int fd,fd1,n;
	mkdir(dir, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);//create directory with permissions 644
	char str_buffer[1024],file_name[1024],read_dir[1024];
        DIR *fd_dir = opendir(from_dir);//open firectory from which files needed to be read
        struct dirent *entry;
	struct stat buff;
        while((entry = readdir(fd_dir)) != NULL)//read all files in directory
        {
	    if(entry->d_name[0]=='.' || strcmp(entry->d_name,".") == 0 || strcmp(entry->d_name,"..")==0)//ignore hidden files
		continue;
		
		// to get actual path of files
		strcpy(file_name,dir);
		strcpy(read_dir,from_dir);
		
		strcat(file_name,"/");
		strcat(read_dir,"/");
		strcat(file_name,entry->d_name);
		strcat(read_dir,entry->d_name);
		
		stat(read_dir,&buff);//get file details in "buff"
		
		//printf("%s -- %s\n",file_name,read_dir);
		
                if(S_IFDIR & buff.st_mode)//if directory, recurse in directory
                {	
                     directory_recursive(read_dir,file_name);
                }
		else if(S_IFREG & buff.st_mode)//if file, create new file and copy data
		{
			fd = open(file_name,O_CREAT| O_TRUNC| O_WRONLY, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);//mode 644
			
			fd1 = open(read_dir,O_RDONLY);
			while((n=read(fd1,str_buffer,sizeof(str_buffer)))>0)//while there is data to be read
			{
				str_buffer[n] = 0;
				write(fd,str_buffer,n);
			}
			//close both files
			close(fd);
			close(fd1);
		}
			
        }
        closedir(fd_dir);

}

int main(int argc, char *argv[])
{
	if(argc < 3)
	{
		printf("Too few arguments\n");
	}
	else if(argc > 3)
	{
		printf("Too many arguments\n");
	}
	
	directory_recursive(argv[1],argv[2]);	
	return 0;
}
