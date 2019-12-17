//Zachary Talarick
//I pledge my honor that I have abided by the Stevens Honor System.

#include "cs392_log.h"
#include <stdio.h>
#include <stdlib.h>

void cs392_socket_log(char * ip, char * port){
	FILE * fp = fopen("cs392_socket.log", "a");
	
	fprintf(fp, "port: %s ip: %s\n", port, ip);
	fclose(fp);

}
