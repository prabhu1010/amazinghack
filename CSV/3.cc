#include <dirent.h> 
#include <stdio.h> 
# include <sys/types.h>
 
DIR           *d;
struct dirent *dir;
struct stat s;
d = opendir(".");
 
if (d)
{
  while ((dir = readdir(d)))
  {
    if (stat(dir->d_name,&s) != 0) {
        /* is this a regular file? */
        if ((s.st_mode & S_IFMT) == S_IFREG)
            printf("%s\n", dir->d_name);
 
    }
  }
  closedir(d);
}
