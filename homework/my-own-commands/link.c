/**
 * This program demonstrates invocation of the link, unlink,
 * and symlink system calls (86, 87, 88) using the syscall function.  
 * The command second argument after calling the program
 * must be "link"/"symlink" to link/symbolic link or "unlink" to unlink. 
 *
 * Note: System call numbers are for 64-bit Linux Systems
 */

#include <linux/types.h>
#include <linux/unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int result;
    char *link = "link";
    char *unlink = "unlink";
    char *symlink = "symlink";
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
  } else if (!(strcmp(symlink, command))) {
    result = syscall(88, argv[2]), argv[3];
    if (result == -1) {
      char *errorMessage = "That file doesn't exist or the link already exists!\n";
      syscall(1, 2, errorMessage, strlen(errorMessage));
    }
  } else {
    char *errorMessage = "Specify whether you are linking (\"link\" or \" symlink \") or unlinking (\"unlink\")\n";
    syscall(1, 2, errorMessage, strlen(errorMessage));  
  }
  
}
