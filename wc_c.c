#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
int main(int argc, char *argv[])
{
	int n,count = 0;
	char buff[2],last=' ';
	int fd = open(argv[1],O_RDONLY);
	struct stat obj;
	fstat(fd,&obj);
	while((n=read(fd,buff,1))>0)
	{
		count++;
		
	}

	printf("%d %d %s\n",count,obj.st_size,argv[1]);
return 0;
}
