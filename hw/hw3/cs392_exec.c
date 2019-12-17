//Zachary Talarick
//I pledge my honor that I have abided by the Stevens Honor System.

#include "cs392_exec.h"

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int argc;
char** parse(char *str){
	argc = 1;
    	for(int i=0; str[i] != '\0'; i++){
        	if(str[i] == ' '){
        	    ++argc;
        	}
    	}
    	char** arr = malloc(256 * sizeof(char*));
    	for(int i=0; i<argc; i++){
        	arr[i] = malloc(sizeof(char) * argc);
    	}
    	char* word = strtok(str, " ");
    	int place = 0;
    	while(word != NULL){
        	strcpy(arr[place], word);
        	word = strtok(NULL, " ");
        	place++;
    	}
   	arr[place] = NULL;
    
	return arr;
}

void execute(char *command){
	pid_t pid;
	int status;
	char** argv = parse(command); //parse into argv array

	if((pid = fork()) < 0){ //create fork
		printf("error forking\n");
		for(int i=0; i<argc; i++){
                	free(argv[i]);
		}
		free(argv);
		
		exit(1);
	}else if(pid == 0){ //child
		if(execvp(argv[0], argv) < 0){
			printf("error executing\n");
			for(int i=0; i<argc; i++){
              		  	free(argv[i]);
			}
			free(argv);
			exit(1);
		}
		for(int i=0; i<argc; i++){
                	free(argv[i]);
		}
		free(argv);
	}else{ //parent
		while(wait(&status) != pid)
			;
	}	
}
