#include<stdio.h>
#include<dirent.h>
#include<unistd.h>
#include<bsd/unistd.h>
#include<string.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<ctype.h>
#include<sys/types.h>

int create_perm_int(char *perm, char *argv)
{
	int i = 0;
	int j = 1;

	for(i = 0, j = 1; perm[j] != '\0' || argv[i] == '\0'; i++,j += 3)
	{

		if(i == 0)
		{
			if(argv[i] == 55)
			{	
				if(!(perm[j] == 'r' && perm[j+1] == 'w' && perm[j+2] == 'x'))
					return -1;

			}
			else
			if(argv[i] == 54)
			{	
				if(!(perm[j] == 'r' && perm[j+1] == 'w' && perm[j+2] == '-'))
					return -1;
			}
			else
			if(argv[i] == 53)
			{	
				if(!(perm[j] == 'r' && perm[j+1] == '-' && perm[j+2] == 'x'))
					return -1;
			}
			else
			if(argv[i] == 52)
			{	
				if(!(perm[j] == 'r' && perm[j+1] == '-' && perm[j+2] == '-'))
					return -1;
			}
			else
			if(argv[i] == 51)
			{	
				if(!(perm[j] == '-' && perm[j+1] == 'w' && perm[j+2] == 'x'))
					return -1;
			}
			else
			if(argv[i] == 50)
			{	
				if(!(perm[j] == '-' && perm[j+1] == 'w' && perm[j+2] == '-'))
					return -1;
			}
			else
			if(argv[i] == 49)
			{	
				if(!(perm[j] == '-' && perm[j+1] == '-' && perm[j+2] == 'x'))
					return -1;
			}
			else
			{	
				printf("Error: -perm expects argument of type mode_t\n");
				exit(1);
			}
		}
	
		if(i == 1)
		{
			if(argv[i] == 55)
			{	
				if(!(perm[j] == 'r' && perm[j+1] == 'w' && perm[j+2] == 'x'))
					return -1;

			}
			else
			if(argv[i] == 54)
			{	
				if(!(perm[j] == 'r' && perm[j+1] == 'w' && perm[j+2] == '-'))
					return -1;
			}
			else
			if(argv[i] == 53)
			{	
				if(!(perm[j] == 'r' && perm[j+1] == '-' && perm[j+2] == 'x'))
					return -1;
			}
			else
			if(argv[i] == 52)
			{	
				if(!(perm[j] == 'r' && perm[j+1] == '-' && perm[j+2] == '-'))
					return -1;
			}
			else
			if(argv[i] == 51)
			{	
				if(!(perm[j] == '-' && perm[j+1] == 'w' && perm[j+2] == 'x'))
					return -1;
			}
			else
			if(argv[i] == 50)
			{	
				if(!(perm[j] == '-' && perm[j+1] == 'w' && perm[j+2] == '-'))
					return -1;
			}
			else
			if(argv[i] == 49)
			{	
				if(!(perm[j] == '-' && perm[j+1] == '-' && perm[j+2] == 'x'))
					return -1;
			}
			else
			{	
				printf("Error: -perm expects argument of type mode_t\n");
				exit(1);
			}
	
		}
		
		if(i == 2)
		{
			if(argv[i] == 55)
			{	
				if(!(perm[j] == 'r' && perm[j+1] == 'w' && perm[j+2] == 'x'))
					return -1;

			}
			else
			if(argv[i] == 54)
			{	
				if(!(perm[j] == 'r' && perm[j+1] == 'w' && perm[j+2] == '-'))
					return -1;
			}
			else
			if(argv[i] == 53)
			{	
				if(!(perm[j] == 'r' && perm[j+1] == '-' && perm[j+2] == 'x'))
					return -1;
			}
			else
			if(argv[i] == 52)
			{	
				if(!(perm[j] == 'r' && perm[j+1] == '-' && perm[j+2] == '-'))
					return -1;
			}
			else
			if(argv[i] == 51)
			{	
				if(!(perm[j] == '-' && perm[j+1] == 'w' && perm[j+2] == 'x'))
					return -1;
			}
			else
			if(argv[i] == 50)
			{	
				if(!(perm[j] == '-' && perm[j+1] == 'w' && perm[j+2] == '-'))
					return -1;
			}
			else
			if(argv[i] == 49)
			{	
				if(!(perm[j] == '-' && perm[j+1] == '-' && perm[j+2] == 'x'))
					return -1;
			}
			else
			{	
				printf("Error: -perm expects argument of type mode_t\n");
				exit(1);
			}
	
		}
	}

		return 1;
}


int check_mode(char *str)
{
	int i = 0;
	
	if(strlen(str) < 3 || strlen(str) > 4)
		return -1;

	for( i = 0; str[i] != '\0';i++)
	{
		if(0 >= str[i] - '0' && 8 <= str[i] - '0')
			return -1;
	}
	
	return 1;
}

int check_int(char *str)
{
	int i = 0;
	
	for(i = 0; str[i] != '\0';i++)
	{
		if(!isdigit(str[i]))
			return -1;
	}

	return 1;
}


void directory_recursive(char *argv[],char *from_dir,int argc,int maxdepth, int mindepth)
{
	int ret = 0;
	int size;
	int n = 0;
	int file_found = 0;
	int file_notfound = 0;

	char read_dir[4096];
	char *perm = (char *)malloc(1024);

        DIR *fd_dir = opendir(from_dir);

        struct dirent *entry;
	struct stat buff;

        while((entry = readdir(fd_dir)) != NULL)
        {
		bzero(read_dir,4096);
		file_found = 0;
		file_notfound = 0;
		
		if(entry->d_name[0] == '.' || strcmp(entry->d_name,".") == 0 || strcmp(entry->d_name,"..") == 0)
			continue;

		strcpy(read_dir,from_dir);

		if(read_dir[strlen(read_dir) - 1] !='/')
			strcat(read_dir,"/");

		strcat(read_dir,entry->d_name);
		stat(read_dir,&buff);
		
		if((S_IFDIR ^(S_IFMT & buff.st_mode)) == 0)
                {	
			if(maxdepth > 0)
                		directory_recursive(argv,read_dir,argc,maxdepth - 1,mindepth - 1);
		}
		
		if( mindepth <= 0)
		{
			n = 1;
			while(n < argc)
			{
				if(strcmp(argv[n],"-size") == 0)
				{
					if(n == argc -1)
					{
						printf("Error: -size expects argument\n");
						closedir(fd_dir);
						exit(1);
					}
				
					if(argv[n+1][0] == '-' || argv[n+1][0] == '+')
					{
						ret = check_int(&argv[n+1][1]);
			
						if(ret == -1)
						{
							printf("Error: -size expects integer value\n");
							closedir(fd_dir);
							exit(1);
						}
						else
						{
							size = atoi(&argv[n+1][1]);
							if(argv[n+1][0] == '-')
							{
								if(buff.st_size > size)
								{
									file_notfound = 1;
									break;
								}
								else
								{
									file_found = 1;
								}
							}
							else if(argv[n+1][0] == '+')
							{
								if(buff.st_size < size)
								{
									file_notfound = 1;
									break;
								}
								else
								{
									file_found = 1;
								}
							}
						}
					}
					else
					{
						ret = check_int(argv[n+1]);
					
						if(ret == -1)
						{
							printf("Error: -size expects integer value\n");
							closedir(fd_dir);
							exit(1);
						}
						else
						{
							size = atoi(argv[n+1]);
			
							if(size != buff.st_size)
							{
								file_notfound = 1;
								break;
							}
							else
							{
								file_found = 1;
							}
						}
					}	
				}

				if(strcmp(argv[n],"-name") == 0)
				{
					if(strcmp(argv[n-1],"-not") != 0)
					{

						if(strcmp(entry->d_name,argv[n+1]) != 0)
						{
							file_notfound = 1;
							break;
						}
						else
						{
							file_found = 1;
						}
					}
					else
					{
						if(strcmp(entry->d_name,argv[n+1]) != 0)
						{
							file_found = 1;
						}
						else
						{
							file_notfound = 1;
							break;
						}

					}
				}
				
				if(strcmp(argv[n],"-iname") == 0)
				{
					if(strcmp(argv[n-1],"-not") != 0)
					{
						if(strcasecmp(entry->d_name,argv[n+1]) != 0)
						{
							file_notfound = 1;
							break;
						}
						else
						{
							file_found = 1;
						}
					}
					else
					{
						if(strcmp(entry->d_name,argv[n+1]) != 0)
						{
							file_found = 1;
						}
						else
						{
							file_notfound = 1;
							break;
						}
					}
				}

				if(strcmp(argv[n],"-type") == 0)
				{
					if(strcmp(argv[n+1],"s") == 0)
					{
						if((S_IFSOCK ^(S_IFMT & buff.st_mode)) != 0)
						{
							file_notfound = 1;
							break;
						}
						else
						{
							file_found = 1;
						}
					}
					
					if(strcmp(argv[n+1],"l") == 0)
					{
						if((S_IFLNK ^(S_IFMT & buff.st_mode)) != 0)
						{
							file_notfound = 1;
							break;
						}
						else
						{
							file_found = 1;
						}
					}
					
					if(strcmp(argv[n+1],"f") == 0)
					{
						if((S_IFREG ^(S_IFREG & buff.st_mode)) != 0)
						{
							file_notfound = 1;
							break;
						}
						else
						{
							file_found = 1;
						}
					}
					
					if(strcmp(argv[n+1],"d") == 0)
					{
						if((S_IFDIR ^(S_IFDIR & buff.st_mode)) != 0)
						{
							file_notfound = 1;
							break;
						}
						else
						{
							file_found = 1;
						}
					}
				}

				if(strcmp(argv[n],"-empty") == 0)
				{
					if(buff.st_size != 0)
					{
						file_notfound = 1;
						break;
					}
					else
					{
						file_found = 1;
					}				

				}
		
				if(strcmp(argv[n],"-perm") == 0)
				{
					ret = check_mode(argv[n+1]);		

					if(ret == -1)
					{
						printf("Error: -perm expects argument of type mode_t\n");
						exit(1);
					}
						
					strmode(buff.st_mode,perm);
					ret = create_perm_int(perm,argv[n+1]);	
	
					if(ret == -1)
					{
						file_notfound = 1;
						break;
					}
					else
					{
						file_found = 1;
					}				
					
				}

				n++;
				
			}
		if(file_found == 1 && file_notfound == 0)
			printf("%s\n",read_dir);		

		}
			
        }
	closedir(fd_dir);
}

int main(int argc, char *argv[])
{
	char dir[4096];
	int maxdepth = -1;
	int mindepth = -1;
	int ret = 0;
	int i = 0;

	if(argv[1][0] == '-')
		strcpy(dir,".");
	else
		strcpy(dir,argv[1]);
 
	for( i = 1 ; i < argc; i++)
	{
		if(strcmp(argv[i],"-maxdepth") == 0)
		{
			ret = check_int(argv[i+1]);
			
			if(ret == -1)
			{
				printf("Error : Integer value expected for MAXDEPTH\n");
				exit(1);
			}
			else
			{
				maxdepth = atoi(argv[i+1]);
			}
		}
		
		if(strcmp(argv[i],"-mindepth") == 0)
		{
			ret = check_int(argv[i+1]);
			
			if(ret == -1)
			{
				printf("Error : Integer value expected for MINDEPTH\n");
				exit(1);
			}
			else
			{
				mindepth = atoi(argv[i+1]);
			}
		}
		
	}

	directory_recursive(argv,dir,argc,maxdepth - 1,mindepth - 1);	
	return 0;
}
