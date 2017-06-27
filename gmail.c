
#include<stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <malloc.h>

struct stat sb;
void signup();
int check_Email_Exist(char mail[]);
int check_Folder_Exist(char folder[]);
void create_Folder(char []);
void main() {
	char folder[50]="t3";
       clrscr();
       strcpy(folder,"t1");
       create_Folder("test\\t2\\t3\\t5");
       if(check_Folder_Exist("Gmail")){
	       system("cd Gmail");
       }
       else{
	       create_Folder("Gmail");
	       system("cd Gmail");
       }

getch();

}

int check_Email_Exist(char mail[])
{

	system("cd users");
	FILE *fp=fopen("user.txt","r");
	if(fp==NULL)
	{
		fclose(fp);
		return 1;
	}
	else{
		do{
		char almail[50];
		fscanf(fp,"%s", almail);
		printf("%s",almail);


int check_Folder_Exist(char folder[]){
	      if(stat(folder,&sb)==0 )
       {
	   return 1;
       }
       else
       {
       return 0;
       }
}

void create_Folder(char path[])
{
	char pathset[100];
	sprintf(pathset,"mkdir %s",path);
	printf("%s",pathset);
	system(pathset);
}
void signup(){
	char username[50];
	char mailid[50];
	char password[50];
	printf("\nEnter the username:\t");
	scanf("%s",username);
	printf("\nEnter the mailId:\t");
	scanf("\n%s",mailid);
	printf("\nEnter the password:\t");
	scanf("\n%s",password);

}

