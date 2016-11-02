#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>

void print(DIR* strm){
  struct dirent *yes;

  while(yes = readdir(strm)){
    printf("%s\n", yes->d_name);
  }
}

int main(){
  DIR* stream = opendir(".");
  print(stream);

  closedir(stream);
  
  return 0;
}
