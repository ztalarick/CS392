#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

//Zachary Talarick
//I pledge my honor that I have abided by the Stevens Honor System.

static void handler1(int sig, siginfo_t *siginfo, void*context){
	printf("\nSIGINT Received\n");
}


int main(){
	struct sigaction act;
	memset(&act, '\0', sizeof(act));

	act.sa_sigaction = &handler1;
	act.sa_flags = SA_SIGINFO | SA_RESETHAND;

	sigaction(SIGINT, &act, NULL);

	while(1){
		sleep(1);
		printf("Hello\n");
	}

	return 0;
}
