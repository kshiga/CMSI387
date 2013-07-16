/**
 * This program demonstrates invocation of the rmdir
 * system call (84) using the syscall function.
 *
 * Note: System call numbers are for 64-bit Linux Systems
 */
 
#include <linux/types.h>
#include <linux/unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
  int result = syscall(84, argv[1]);
  if (result == -1) {
    char *errorMessage = "That directory doesn't exist!\n";
    syscall(1, 2, errorMessage, strlen(errorMessage));
  }
}
