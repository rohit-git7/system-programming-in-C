/*
Implement linux command 'wc -c' in C.
To run:
	./executable file_name
*/
#include<stdio.h>
#include<fcntl.h>//read() open()
#include<unistd.h>//O_RDONLY
#include<sys/stat.h>//fstat()

int main(int argc, char *argv[])
{
	int n,count = 0;
	char buff[2];
	int fd = open(argv[1],O_RDONLY);
	struct stat obj;
	fstat(fd,&obj);
	/*
	We can get number of bytes from file stat structure or by counting each byte
	*/
	while((n=read(fd,buff,1))>0)
	{
		count++;
		
	}

	printf("%d %d %s\n",count,obj.st_size,argv[1]);
return 0;
}
