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
	char file[1024];
	char dest_dir[1024];
	char dest_file[1024];
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
	
		if(entry->d_name[0] == '.')
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
					mkdir(dest_dir,0644);
					strcpy(dest_file,dest_dir);
					strcat(dest_file,"/");
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
					unlink(file);
					temp = 1;
				break;
				}
				
			}
		if(temp == 0)
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
			unlink(file);
		}
		
		
		}
		bzero(file,sizeof(file));
		bzero(dest_file,sizeof(dest_file));
		bzero(dest_dir,sizeof(dest_dir));
	
	}
	
	closedir(fd_dir);

return 0;
}
