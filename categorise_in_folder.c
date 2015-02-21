/*
Write a program that will categorize all files in the current directory based on their file type. 
That is all .txt file in one directory called txt, all .bmp files in another directory called bmp etc.
The argument to the program is a directory name.
*/
#include<stdio.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
	int fd;
	int fd_dest;
	int len;
	int n;
	int j;
	int temp = 0;

	char buffer[1024];
	char file[1024];//full name of file
	char dest_dir[1024];//final directory where file of specific type is moved
	char dest_file[1024];//full name of new file
	char *p;

	DIR *fd_dir = opendir(argv[1]);
	struct dirent *entry;
	struct stat buf;

	bzero(file,sizeof(file));
	bzero(dest_file,sizeof(dest_file));
	bzero(dest_dir,sizeof(dest_dir));
	
	while((entry = readdir(fd_dir)) != NULL)
	{
		strcpy(file,argv[1]);
	
		if(entry->d_name[0] == '.')//skip hidden files
			continue;
		temp = 0;
		strcat(file,entry->d_name);
		stat(file,&buf);
		
		if(S_IFREG & buf.st_mode)
		{
			strcpy(dest_dir,argv[1]);	
			len = strlen(entry->d_name);
	//		printf("%s\n",entry->d_name);	

			for(j = len - 1; j >= 0; j--)
			{
				if(entry->d_name[j] == '.')
				{
					p = (entry->d_name + j + 1);
					strcat(dest_dir,p);
					mkdir(dest_dir,0644);//creating directory
					strcpy(dest_file,dest_dir);
					strcat(dest_file,"/");
					strcat(dest_file,entry->d_name);
					printf("%s\n",dest_file);
					
					//moving file contents to new file
					fd = open(file,O_RDONLY);
					fd_dest = open(dest_file,O_CREAT | O_WRONLY, 0644);
					while((n = read(fd,buffer,sizeof(buffer))) > 0)
					{
						buffer[n]='\0';
						write(fd_dest,buffer,n);
					}
					close(fd);
					close(fd_dest);
					unlink(file);//delete old file
					temp = 1;
				break;
				}
				
			}
		if(temp == 0)//no type could be found for file
		{
			strcat(dest_dir,"Other/");
			mkdir(dest_dir,0644);
			strcpy(dest_file,dest_dir);
			strcat(dest_file,entry->d_name);
			printf("%s\n",dest_file);
			fd = open(file,O_RDONLY);
			fd_dest = open(dest_file,O_CREAT | O_WRONLY, 0644);
			while((n = read(fd,buffer,sizeof(buffer))) > 0)
			{
				buffer[n]='\0';
				write(fd_dest,buffer,n);
			}
			
			close(fd);
			close(fd_dest);
			unlink(file);//delete file
		}
		
		
		}
		bzero(file,sizeof(file));
		bzero(dest_file,sizeof(dest_file));
		bzero(dest_dir,sizeof(dest_dir));
	
	}
	
	closedir(fd_dir);

return 0;
}
