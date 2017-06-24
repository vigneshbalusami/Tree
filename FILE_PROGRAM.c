
#include<stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
void main() {
   int check;
  char dirname[100];
  printf("Enter a directory path and name to be created (C:/name):");
  scanf("%s",dirname);
 int result = mkdir(dirname,0777);
DIR* dir = opendir("/home/students/Desktop/t4");
if (dir)
{
   printf(" /* Directory exists. */ ");
    closedir(dir);
}
}
