/*
Write a function foo(int fd, char* buff, int b_size,int n, int skip) that reads to buff
from file with file descriptor fd, n blocks of size b_size each. The last argument
specifies how many bytes to skip after reading each block. Return -1 if the operation is unsuccessful. 
Else return total number of bytes read.
*/

#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

int foo(int fd, char *buff, int b_size, int n, int skip)
{
	int k;
	int sum = 0;
	
	while((k = read(fd,buff,b_size)) > 0)
	{
		if( k < b_size || n == -1)//operation unsuccessful if block has size less than b_size or no. of blocks are less than n
			return -1;
	
		sum += k;//count read bytes
		n--;
		lseek(fd,skip,SEEK_CUR);//skip bytes
	}
	if(n > 0)//operation unsuccessful if no. of blocks are less than n
		return -1;
	else
		return sum;
}

int main(int argc, char *argv[])
{
	int fd;
	int b_size;
	int n;
	int skip;
	int num_bytes;
	char *buff;

	if(argc < 5)
	{
		printf("Too few arguments\n");
		exit(1);
	}
	else if(argc > 5)
	{
		printf("Too many arguments\n");
		exit(1);
	}

	fd = open(argv[1],O_RDONLY);
	b_size = atoi(argv[2]);
	n = atoi(argv[3]);
	skip = atoi(argv[4]);
	buff = (char *)malloc(b_size);

	if(fd == -1)
	{
		perror("Error");
		exit(1);
	}

	num_bytes = foo(fd,buff,b_size,n,skip);
	if(num_bytes != -1)
		printf("Total number of bytes read %d\n",num_bytes);
	else
		printf("-1\n");	
return 0;
}
