//Zachary Talarick
//I pledge my honor that I have abided by the Stevens Honor System.

#include "cs392_exec.h"
#include "cs392_signal.h"
#include "cs392_log.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

void shell(void){
	int error;
	char buffer[256];

	while(1){
		printf("cs392_shell $: ");
		fflush(stdout); //has no \n after the first print

		error = read(0, buffer, 255);	//read line
		buffer[error - 1] = '\0'; //properly null terminate

		my_log(buffer); //write to log					

		if(strcmp(buffer, "exit") == 0){			//exit			
			exit(0);			
		}
					
		execute(buffer);					//execute command		
	}
}

int main(int argc, int** argv){
	my_signal(); //register SIGINT and SIGTSTP signals
	shell();
	return 0;
}
