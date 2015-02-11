#include<stdio.h>
#include<dirent.h>
#include<unistd.h>
#include<string.h>
#include<sys/stat.h>
#include<fcntl.h>

void directory_recursive(char from_dir[],char dir[])
{
	int fd,fd1,n;
	mkdir(dir, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	char str_buffer[1024],file_name[1024],read_dir[1024];
        DIR *fd_dir = opendir(from_dir);
        struct dirent *entry;
	struct stat buff;
        while((entry = readdir(fd_dir)) != NULL)
        {
	    if(entry->d_name[0]=='.' || strcmp(entry->d_name,".") == 0 || strcmp(entry->d_name,"..")==0)
		continue;
		strcpy(file_name,dir);
		strcpy(read_dir,from_dir);
		
		//stat(entry->d_name,&buff);
		strcat(file_name,"/");
		strcat(read_dir,"/");
		strcat(file_name,entry->d_name);
		strcat(read_dir,entry->d_name);
		stat(read_dir,&buff);
		printf("%s -- %s\n",file_name,read_dir);
		
                if(S_IFDIR & buff.st_mode)
                {	
                     directory_recursive(read_dir,file_name);
                }
		else if(S_IFREG & buff.st_mode)
		{
			fd = open(file_name,O_CREAT| O_TRUNC| O_WRONLY, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
			
			fd1 = open(read_dir,O_RDONLY);
			while((n=read(fd1,str_buffer,sizeof(str_buffer)))>0)
			{
				str_buffer[n] = 0;
				write(fd,str_buffer,n);
			}
			close(fd);
			close(fd1);
		}
			
        }

}

int main(int argc, char *argv[])
{
	directory_recursive(argv[1],argv[2]);	
	return 0;
}
