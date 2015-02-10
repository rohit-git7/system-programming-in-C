#include <unistd.h> //dup() write()
#include <stdlib.h> //exit() 
int main() 
{
    int newfd = dup(STDOUT_FILENO); //Call dup for an aliased fd
    char buff[] = "Hello brother\n";
 
    if(newfd < 0) //Error
    { 
	perror("Error");
        exit(0);
    }
    else if (write(newfd, buff, sizeof(buff)) < 0) 
    { 
	perror("Error");
        exit(0);
    }
 
    return 0;
}
