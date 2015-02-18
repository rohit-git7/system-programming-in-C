#include<unistd.h>
#include<stdio.h>
#include<utmp.h>
#include<string.h>
#include<time.h>
int main()
{
       char *s,*c;
       struct utmp *u;
       int i;
       c=getlogin();
       setutent();
       u=getutent();
       while(u!=NULL)
       {
          if(u->ut_type==7 && strcmp(u->ut_user,c)==0)
          {
               printf("%-12s",u->ut_user);
               printf("%-9s",u->ut_line);
               s=ctime(&u->ut_time);
               for(i=4;i<16;i++)
               printf("%c",s[i]);
               printf("(%s",u->ut_host);
               printf(")\n");
          }
       u=getutent();
       }
return 0;
}
