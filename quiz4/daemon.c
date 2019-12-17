//Zachary Talarick
//I pledge my honor that I have abided by the Stevens Honor System.

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <time.h>

void getTime(){

}


int main(void){
	pid_t pid = fork();
	if(pid < 0){ //error with forking
		exit(EXIT_FAILURE);
	}
	if(pid > 0){ //exit from parent
		exit(EXIT_SUCCESS);
	}
	//child
	umask(0); //change file permissions
	
	pid_t sid;	
	sid = setsid(); //set new session id
	if(sid < 0){ //error with setsid
		exit(EXIT_FAILURE);
	}

	if((chdir("/tmp")) < 0){ //change directory
		exit(EXIT_FAILURE);
	}
	
	//close file descriptors
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
	
	FILE *fp;
	fp = fopen("cs392_daemon.log", "a+"); //create log file
	
	while(1){
		sleep(2);
		
		//get time
		time_t  t = time(NULL);
		struct tm *tm = localtime(&t); 
		
		fprintf(fp, "%s", asctime(tm)); //write time
		fflush(fp);		
	}
	
	fclose(fp);
	exit(EXIT_SUCCESS);
}
