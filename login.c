/*
Simple Program for login.
Compile program with library 'lcrypt'
*/
#include<stdio.h>
#include<pwd.h>
#include<shadow.h>
#include<crypt.h>
#include<stdlib.h>

int sys_auth_user(char *username, char *password)
{
  struct passwd *pw;
  struct spwd *sp;
  char *encrypted, *correct;

  pw = getpwnam(username);
  endpwent();

  if (!pw)
	return 1; //user doesn't really exist

  sp = getspnam (pw->pw_name);
  endspent();
  if(sp)
     correct = sp->sp_pwdp;
  else
     correct = pw->pw_passwd;

  encrypted = crypt(password, correct);
  return strcmp (encrypted, correct) ? 2 : 0;  // bad password=2, success=0
}

int main()
{
	char *pass=malloc(1024);
	char user[1024];
	int result;
	printf("Enter username: ");
	fgets(user);
	pass=getpasswd("Enter your password: ");
	result = sys_auth_user(user,pass);
	
	if(result == 1)
		printf("No such user \n");
	else if(result == 2)
		printf("Wrong password\n");
	else
		printf("Login successful\n");
	
	return 0;
}
