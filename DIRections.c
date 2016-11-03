#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(){
  DIR* stream = opendir(".");
  
  struct dirent *yes;

  int size = 0;

  while(yes = readdir(stream)){
    if (yes->d_type == DT_DIR)
      printf("%s (Directory)\n", yes->d_name);
    
    else
      printf("%s\n", yes->d_name);
   
    struct stat filestat;
    stat(yes->d_name,&filestat);
    size+= filestat.st_size;    
  }
  
  closedir(stream);

  printf("Total size of directory: %d Bytes\n", size);
  return 0;
}
