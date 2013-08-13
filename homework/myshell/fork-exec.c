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
    int spaceloc = 0;
    int numspace = 0;
    int i = 1;
    int bg = 0;


    const int MAX_INPUT = 4096;
    const int MAX_COMM = 256;
    const int MAX_ARGS = 3840;
    const char *exit = "exit";
    const char *cd = "cd";
    const char *and = "&";
    const char *argv[MAX_ARGS];


    char input[MAX_INPUT];
    char command[MAX_COMM];
    char *arg;
    char argumentsin[MAX_ARGS];
    char *parse;



    while (!running){
        i = 1;    
        memset(input, '\0', MAX_INPUT);
        memset(command, '\0', MAX_COMM);
        memset(argumentsin, '\0', MAX_ARGS);
        
        printf("Enter the command to run: ");
        fgets(input, MAX_INPUT, stdin);
        parse = strchr(input, ' ');      
        
        if(!parse){            
            strncpy(command, (const char *)input, ((int)strlen(input) - 1)); 
        } else {
            argv[0] = command;
            spaceloc = (int)(parse - input + 1);
            strncpy(argumentsin, (const char *)parse, ((int)strlen(parse)-1));
            memmove (argumentsin, argumentsin+1, strlen (argumentsin));
            arg = strtok(argumentsin, " ");
            
            while(arg != NULL){
                argv[i] = arg;
                arg = strtok(NULL, " ");
                if (!strcmp((const char*)argv[i], and)){ 
                    bg = 1;
                    argv[i] = NULL;
                    break;
                }
                i++;                
            }
            
            argv[i+1] = NULL;                        
            strncpy(command, (const char *)input, (spaceloc -1));
        }
        
        pid_t pid;
        pid_t pidBG;
        if (!strcmp(command, exit)) {
           running = 1;
        }
        
        if(!strncmp((const char *)command, cd, maxcomp)){
            changedir = chdir(argv[2]);
            if(changedir){
                printf("Unable to change to specified directory.");
            }
            
        } 
        


        pid = fork();
        if (pid < 0) {
            fprintf(stderr, "Fork failed\n");
            return -1;
        } else if (pid == 0) {
            if(bg){
                pidBG = fork();
                if(pidBG < 0){
                    fprintf(stderr, "Fork failed\n");
                } else if (pidBG == 0) {
                    main();
                    if(strcmp(argumentsin, "")){
                        execvp(command, (char * const*)argv);
                    } else {
                        execlp(command, command, NULL);
                    }
                } 
            }
            
            if(strcmp(argumentsin, "")){
                execvp(command, (char * const*)argv);
            } else {
                execlp(command, command, NULL);
            }
            
        } else {
            int result;
            wait(&result);
        }
            
    }
}
