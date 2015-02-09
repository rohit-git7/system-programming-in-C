/*
Program to show use of pipe for interprocess communication
*/
#include<stdio.h>
#include<unistd.h>//pid_t
#include<stdlib.h>//exit()
#include<string.h>//strlen()
int main()
{
        int fd[2], nbytes;
        pid_t pd;
        char str[] = "hello brother\n";
        char buffer[100];

        pipe(fd);
        
        if((pd = fork()) == -1)//forking process
        {
                perror("ERROR");//error in fork()
                exit(1);
        }

        if(pd == 0)//child process
        {
                // Child process closes up input side of pipe
                close(fd[0]);

                // Send "str" through the output side of pipe
                write(fd[1], str, (strlen(str)+1));
                exit(0);
        }
        else// parent process
        {
                // Parent process closes up output side of pipe
                close(fd[1]);

                // Read in a string from the pipe
                nbytes = read(fd[0], buffer, sizeof(buffer));
                printf("Received string: %s", buffer);
        }
        
        return(0);
}
