//Zachary Talarick
//I pledge my honor that I have abided by the Stevens Honor System.

#include "cs392_log.h"

#include <stdio.h>
#include <stdlib.h>

void my_log(char* input){
	FILE * fp = fopen("cs392_shell.log", "a");
	fprintf(fp, "%s", input);
	fclose(fp);
}


