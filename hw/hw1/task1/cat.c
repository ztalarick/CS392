//“I pledge my honor that I have abided by the Stevens Honor System.”
//Zachary Talarick
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>



off_t fsize(const char *filename) { //gets file size, only works in unix system
    struct stat st;

    if (stat(filename, &st) == 0)
        return st.st_size;

    exit(1);
}

int main(int argc, char** argv){
	FILE *fp; //file pointer
	size_t length = 0;
	ssize_t read;
	if(argc != 2){ //if arguments are off
		printf("Expected: ./cat <filename>\n");
		exit(1);
	}

	fp = fopen(argv[1], "r"); //open file in read mode
	if(fp){ //file exists
		char *line = malloc(fsize(argv[1]) * sizeof(char)); //variable for line in dynamic memory
		while((read = getline(&line, &length, fp)) != -1){ //while there are lines and no errors
			printf("%s", line);
		}
		free(line);
		fclose(fp); //close stream
	} else{ //file doesn't exist
		printf("No such file or directory.\n");
		exit(1);
	}
	return 0;
}
