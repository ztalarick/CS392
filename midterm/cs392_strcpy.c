//I pledge my honor that I have abided by the Stevens Honor System.

#include "cs392_midterm.h"

char *cs392_strcpy(char *dest, char *src){
	char* res = dest;
	while('\0' != *src){
		*dest++ = *src++;
	}
	*dest = '\0';
	return res;
}
