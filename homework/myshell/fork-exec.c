#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

/**
 * This program demonstrates the use of the fork() and exec()
 * functions.
 */
int main() {
    int running = 0;
    int maxcomp = 256;
    int changedir = 0;
    const int MAX_INPUT = 4096;
    const int MAX_COMM = 256;
    const int MAX_ARGS = 3840;
    const char *exit = "exit";
    const char *cd = "cd";
    const char *and = "&";


    char input[MAX_INPUT];
    char command[MAX_COMM];
    char *arg;
    char argumentsin[MAX_ARGS];
    char arguments[MAX_ARGS];
    char *parse;
    int spaceloc = 0;
    int numspace = 0;
    int i = 0;

    while (!running){
    
        memset(input, '\0', MAX_INPUT);
        memset(command, '\0', MAX_COMM);
        memset(argumentsin, '\0', MAX_ARGS);

        
        printf("Enter the command to run: ");
        fgets(input, MAX_INPUT, stdin);
        //printf("input: %s\n", input);
        parse = strchr(input, ' ');
        
        
        
        if(!parse){            
            strncpy(command, (const char *)input, ((int)strlen(input) - 1)); 
        } else {
            spaceloc = (int)(parse - input + 1);
            strncpy(argumentsin, (const char *)parse, ((int)strlen(parse)-1));
            memmove (argumentsin, argumentsin+1, strlen (argumentsin));
            arg = strtok(argumentsin, " ");
            
            for(i; i < numspace; i++){
            
            }
            
            //printf("arguments: \"%s\"\n", arguments);
            strncpy(command, (const char *)input, (spaceloc -1));
        }
        



        pid_t pid;

        if (!strcmp(command, exit)) {
           running = 1;
        }
        
        if(!strncmp((const char *)command, cd, maxcomp)){
            changedir = chdir(argumentsin);
            if(changedir){
                printf("Unable to change to specified directory.");
            }
            
        } 



        pid = fork();
        if (pid < 0) {
            fprintf(stderr, "Fork failed\n");
            return -1;
        } else if (pid == 0) {
            printf("Running...\n");
            
            if(strcmp(argumentsin, "")){
                printf("has arguments \"%s\"\n", argumentsin);
                execlp(command, command, argumentsin, NULL);
            } else {
                execlp(command, command, NULL);
            }
            
        } else {
            int result;
            wait(&result);
            //printf("All done; result = %d\n", result);
        }
            //printf("running value: %d\n", running);
            
    }
}
