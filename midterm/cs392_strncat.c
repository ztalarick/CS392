//I pledge my honor that I have abided by the Stevens Honor System.

#include "cs392_midterm.h"

unsigned cs392_strlen(char *str){
//calculates the length of the string pointed to by “str”, and returns that length
	unsigned int i = 0;
	while(str[i] != '\0'){
		i++;
	}
	return i;
}

char *cs392_strncat(char *dest, char *src, unsigned n){
	unsigned dest_len = cs392_strlen(dest);
	unsigned i = 0;
	for( ; i < n && src[i] != '\0'; i++){
		dest[dest_len + i] = src[i];
	}
	dest[dest_len + i] = '\0';
	return dest;
}




