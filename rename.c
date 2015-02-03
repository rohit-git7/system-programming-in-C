#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
	char old_name[1024];
	char new_name[1024];

	if(argc < 3)
	{
		printf("Error: Too few arguments!!!\n");
		exit(0);
	}
	else
	if(argc==3)
	{
		strcpy(old_name,argv[1]);
		strcpy(new_name,argv[2]);
	}
	else
	{
		printf("Error: Too many arguments!!!\n");
		exit(0);
	}
	
	if(access(old_name,F_OK)!=0)
	{
		perror("Error");
		exit(0);
	}
	else
	{
	 if(access(new_name,F_OK)==0)
	  {
		printf("A file with name %s is already present. Want to  overwrite? ",new_name);
		char ch=getchar();
		if(ch=='y'|| ch=='Y')
		{
			if(rename(old_name,new_name)==0)
			{
				printf("File renamed succesfully\n");
			}
			else
			{
				perror("Error");
				exit(0);
			}
		}
		else
		{
			exit(0);
		}
		
	   }
	else
	{
		      if(rename(old_name,new_name)==0)
                        {
                                printf("File renamed succesfully\n");
                        }
                        else
                        {
                                perror("Error");
                                exit(0);
                        }

	}

	}

return 0;
}
