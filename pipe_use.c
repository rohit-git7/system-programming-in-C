#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
int main()
{
        int fd[2], nbytes;
        pid_t pd;
        char str[] = "hello brother\n";
        char buffer[100];

        pipe(fd);
        
        if((pd = fork()) == -1)
        {
                perror("ERROR");
                exit(1);
        }

        if(pd == 0)
        {
                /* Child process closes up input side of pipe */
                close(fd[0]);

                /* Send "string" through the output side of pipe */
                write(fd[1], str, (strlen(str)+1));
                exit(0);
        }
        else
        {
                /* Parent process closes up output side of pipe */
                close(fd[1]);

                /* Read in a string from the pipe */
                nbytes = read(fd[0], buffer, sizeof(buffer));
                printf("Received string: %s", buffer);
        }
        
        return(0);
}
