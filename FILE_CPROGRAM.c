
#include<stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <malloc.h>


/*
int remove_directory(const char *path)
{
   DIR *d = opendir(path);
   size_t path_len = strlen(path);
printf("\n%u %u\n",path_len,d);
   int r = -1;

   if (d)
   {
      struct dirent *p;

      r = 0;

      while (!r && (p=readdir(d)))
      {
          int r2 = -1;
          char *buf;
          size_t len;

          // Skip the names "." and ".." as we don't want to recurse on them. 
          if (!strcmp(p->d_name, ".") || !strcmp(p->d_name, ".."))
          {
             continue;
          }

          len = path_len + strlen(p->d_name) + 2; 
          buf = malloc(len);

          if (buf)
          {
             struct stat statbuf;

             snprintf(buf, len, "%s/%s", path, p->d_name);

             if (!stat(buf, &statbuf))
             {
                if (S_ISDIR(statbuf.st_mode))
                {
                   r2 = remove_directory(buf);
                }
                else
                {
                   r2 = unlink(buf);
                }
             }

             free(buf);
          }

          r = r2;
      }

      closedir(d);
   }

   if (!r)
   {
      r = rmdir(path);
   }

   return r;
}

*/
void main() {
   	int check,i;
  	char dirname[100],a[80];
  	printf("Enter a directory path and name to be created (C:/name):");
 char command[50];
        for(i=0;i<5;i++) {
                sprintf(command,"mkdir A%d",i);
                system(command);
}
  	//scanf("%s\n%s",dirname,a);
	//system(dirname,a);
 	//int result = mkdir(dirname,0777);
	//DIR* dir = opendir("/home/students/Desktop/tf");
	//if (dir)
	//{
   		printf(" /* Directory exists. */ ");
    	//	closedir(dir);
	//}
	//remove_directory("/home/students/Desktop/t1"); 
	// rmdir("path");  //remove empty directory  
	//system("rm -r /home/students/Desktop/t2"); 	 // itremove all files
} 






