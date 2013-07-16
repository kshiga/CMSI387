/**
 * This program demonstrates invocation of the creat
 * system call (85) using the syscall function.
 *
 * Note: System call numbers are for 64-bit Linux Systems
 */
 
#include <linux/types.h>
#include <linux/unistd.h>
#include <string.h>


int main(int argc, char *argv[]) {
  int result = syscall(85, argv[1], 0);
  
  if(result == -1){
    char *errorMessage = "You cannot create this file\n";
    syscall(1, 2, errorMessage, strlen(errorMessage));
  }
  
}
