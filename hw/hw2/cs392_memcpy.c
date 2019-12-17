//I pledge my honor that I have abided by the Stevens Honor System.

#include "cs392_string.h"


void * cs392_memcpy ( void * dst, void * src, unsigned num){
// copies “num” bytes of data from the memory pointed to by “src” to the memory pointed to by “dst”. This function returns “dst”
	
	//dst = malloc(num); //do I need to do this or is it already allocated?
	char *char_dst = (char *)dst; //cannot dereference void pointer
	char *char_src = (char *)src; //cast to char since it is one byte large
	int i = 0;
	while(i < num){
	char_dst[i] = char_src[i];
	i++;
	}

	return char_dst;
}
