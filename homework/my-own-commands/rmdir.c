
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
