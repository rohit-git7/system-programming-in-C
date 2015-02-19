#include<stdio.h>
#include<time.h>

int main()
{
	time_t t = time(NULL);
	struct tm time_struct;
	time_struct = *localtime(&t);
	
	printf("Today : %d-%d-%d %d:%d:%d\n",time_struct.tm_mday, time_struct.tm_mon + 1, time_struct.tm_year + 1900, time_struct.tm_hour, time_struct.tm_min, time_struct.tm_sec);
	return 0;
}
