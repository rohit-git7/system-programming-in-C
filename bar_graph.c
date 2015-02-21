/*
Write a program that takes directory name and file types as arguments and returns a bar graph representing
% of that file type out of 10.
For example
 ./a.out foo c py sh will return bar graph representation of files of type '.c' '.py' '.h' in
 directory foo. 
*/
#include<stdio.h>
#include<dirent.h>//DIR * opendir() readdir() closedir()
#include<sys/stat.h>//stat()
#include<string.h>//strlen() memset()
#include<unistd.h>//S_IFDIR

int main(int argc, char *argv[])
{
	int total = 0;
	int arr[argc-1];
	int len;
	int i;
	int j;
	int temp = 0;
	int temp1 = 0;

	int out[argc-1][16];
	
	char dir[1024];
	char *p;

	DIR *fd_dir = opendir(argv[1]);//open directory
	struct dirent *entry;
	struct stat buf;

	memset(arr,0,sizeof(arr));
	memset(out,0,sizeof(arr));
	
	strcpy(dir,argv[1]);
	while((entry = readdir(fd_dir)) != NULL)//read the directory contents
	{
		if(entry->d_name[0] == '.')//skip hidden files
			continue;
		temp = 0;
		temp1 = 0;
		strcat(dir,entry->d_name);
		stat(dir,&buf);
		
		if(S_IFREG & buf.st_mode)//if entry is regular file
		{
			total += (int)buf.st_size;//total size of regular files
			len = strlen(entry->d_name);

			for(j = len - 1; j >= 0; j--)
			{
				if(entry->d_name[j] == '.')
				{
					temp = 1;
					p = (entry->d_name + j + 1);//get file type
					for(i = 2;i < argc; i++)
					{
						if(strcmp(p,argv[i]) == 0)
						{
							arr[i-2] += (int)buf.st_size;
							temp1 = 1;
							break;
						}
					}
					break;
				}
			}
		
		
		if(temp != 1 && temp1 != 1)//if file type is not mentioned in arguments, add in other
		{
			arr[argc-2] += (int)buf.st_size;
		}
		
		}
	}
	
	closedir(fd_dir);

	for(i = 0; i < argc -1 ; i++)
	{
		arr[i] *= 10;
		arr[i] /= total;
		for(j =0;j<=arr[i];j++)
		{
			out[i][j]=1;
		}
	}
	
	for(i = 15; i > 0 ; i--)
	{
		for(j = 0;j<argc - 1;j++)
		{
			if(out[j][i]==1)
				printf("\t #");
			else
				printf("\t  ");
		}
		printf("\n");
	}
	
	for(i = 0;i<argc - 2 ;i++)
	{
		printf("\t%s",argv[i+2]);
	}
	printf("\tOthers\n");

	printf("\nTotal %d\n",total);
return 0;
}
