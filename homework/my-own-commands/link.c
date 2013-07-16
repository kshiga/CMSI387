
#include <linux/types.h>
#include <linux/unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int result;
    char *link = "link";
    char *unlink = "unlink";
    char *command =  argv[1];
    
  if(!(strcmp(link, command))){
    result = syscall(86, argv[2], argv[3]);    
    if (result == -1) {
      char *errorMessage = "That file doesn't exist or the link already exists!\n";
      syscall(1, 2, errorMessage, strlen(errorMessage));
    }
  } else if (!(strcmp(unlink, command))) {
    result = syscall(87, argv[2]);
    if (result == -1) {
      char *errorMessage = "That link doesn't exist!\n";
      syscall(1, 2, errorMessage, strlen(errorMessage));
    }
  }
  
}
