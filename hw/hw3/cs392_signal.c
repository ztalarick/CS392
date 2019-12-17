//Zachary Talarick
//I pledge my honor that I have abided by the Stevens Honor System.

#include "cs392_signal.h"

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

static void handler(int sig, siginfo_t *siginfo, void*context){
	printf("\ninterrupt received.\n");
}

void my_signal(void){

	struct sigaction act;
	memset(&act, '\0', sizeof(act));
	act.sa_sigaction = &handler;
	act.sa_flags = SA_SIGINFO;

	sigaction(SIGTSTP, &act, NULL);
	sigaction(SIGINT, &act, NULL);
}
