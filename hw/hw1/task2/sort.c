//“I pledge my honor that I have abided by the Stevens Honor System.”
//Zachary Talarick


#include "sort.h" 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
I need to:
	check proper arugment numbers
	open inputfile in read mode
		check if it exists
	read lines and store each line as a string (char[]) with dynamic memory
	close inputfile

	convert strings to ints <-----here
	sort ints
	convert ints to binary
	open outputfile in writemode
		create if it doesn't exist?? or error???
	write  binary ints to output file
	close outputfile
	
	free stuff!!	
*/


int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

void printArray(int *arr, int size){ //for debugging
	for(int i = 0; i < size; i++){
		printf("%d\n", arr[i]);	
	}
}

int main(int argc, char **argv){
	if(argc != 3){
		printf("Usage: ./sort <inputfile> <outputfile>\n");
		exit(1);	
	}
	
	FILE *inputfp = fopen(argv[1], "r"); //open input file
	if(inputfp){ //inputfile exists
		int *data = NULL;
		char line[11];
		int convert_line;
		int counter = 0;
		while(fgets(line, 10, inputfp)){
			data = realloc(data,(counter+1) * sizeof(int *)); //allocate memory for line just read

			convert_line = atoi(line); //convert line to int //atoi is bad there must be a better way
			
			data[counter] = convert_line; 
			counter++;
		}
		fclose(inputfp); //close input file

		qsort(data, counter - 1, sizeof(int), cmpfunc); //sort
		
		FILE *outputfp = fopen(argv[2], "wb"); //create output file
		for(int i = 0; i <= counter; i++){ //loop over data
			
			fwrite(&data[i], sizeof(int), 1, outputfp); 
			
			fputc('\n', outputfp); //put a newline
		}
		fclose(outputfp);
		free(data);

		
	} else{ //inputfile doesn't exist
		printf("No such input file or directory.\n");
		exit(1);
	}


	return 0;
}


