//Zachary Talarick
//I pledge my honor that I have abided by the Stevens Honor System.

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>

int main(void){
	printf("User ID: %d\n", getuid());

	if(getuid() == 0){
		setgid(1000);
		setuid(1000);
	}
	
	printf("User ID after root check: %d\n", getuid());
	return 0;
}
