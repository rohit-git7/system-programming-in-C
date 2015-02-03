/*
Implementing linux command 'mv' to rename a file.
Compile and run executable
To run executable:
	./exec old_name new_name

*/

#include<stdio.h>
#include<string.h>// strcpy
#include<stdlib.h>//exit()
#include<unistd.h>//F_OK

int main(int argc, char *argv[])
{
	char old_name[1024];
	char new_name[1024];

	if(argc < 3)//Two arguments are required
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
	else//more than two arguments
	{
		printf("Error: Too many arguments!!!\n");
		exit(0);
	}
	
	if(access(old_name,F_OK)!=0)//to check if file is actually present or not
	{
		perror("Error");
		exit(0);
	}
	else//file is present
	{
	 	if(access(new_name,F_OK)==0)//to check if a file with new_name is already present
	  	{
			printf("A file with name %s is already present. Want to  overwrite? ",new_name);
			char ch=getchar();
			if(ch=='y'|| ch=='Y')//Overwrite the previous file
			{
				if(rename(old_name,new_name)==0)// returns 0 on success
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
		else//no file with the name 'new_name'
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
