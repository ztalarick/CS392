//Zachary Talarick
//I pledge my honor that I have abided by the Stevens Honor System.
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>


int item1_counter = 0, item2_counter = 0, item3_counter = 0;
pthread_mutex_t lock;

void *cs392_thread_run (void *path){

	FILE *fp = fopen((char *)path, "r");
	if(fp){
		char * line = NULL;
    		size_t len = 0;
    		ssize_t read;
		while((read = getline(&line, &len, fp)) != -1) {

			if(strcmp(line, "+item1\n") == 0){
				pthread_mutex_lock(&lock);
				item1_counter++;
				pthread_mutex_unlock(&lock);
			}
			if(strcmp(line, "-item1\n") == 0){
				pthread_mutex_lock(&lock);
				item1_counter--;
				pthread_mutex_unlock(&lock);
			}
			if(strcmp(line, "+item2\n") == 0){
				pthread_mutex_lock(&lock);
				item2_counter++;
				pthread_mutex_unlock(&lock);
			}
			if(strcmp(line, "-item2\n") == 0){
				pthread_mutex_lock(&lock);
				item2_counter--;
				pthread_mutex_unlock(&lock);
			}
			if(strcmp(line, "+item3\n") == 0){
				pthread_mutex_lock(&lock);
				item3_counter++;
				pthread_mutex_unlock(&lock);
			}
			if(strcmp(line, "-item3\n") == 0){
				pthread_mutex_lock(&lock);
				item3_counter--;
				pthread_mutex_unlock(&lock);
			}
		}
		fclose(fp);
		if(line){
			free(line);
		}

	}else{
		printf("Error: File does not exist.");
	}
	pthread_exit(NULL);
	return NULL;
}

int main(int argc, char** argv){
	if(argc != 4){
		printf("Usage: ./cs392_thread <file1> <file2> <file3>\n");
		exit(1);
	}

	pthread_t id[3];

	pthread_mutex_init(&lock, NULL);

	pthread_create(&id[0], NULL, cs392_thread_run, argv[1]);
	pthread_create(&id[1], NULL, cs392_thread_run, argv[2]);
	pthread_create(&id[2], NULL, cs392_thread_run, argv[3]);

	pthread_join(id[0], NULL);
	pthread_join(id[1], NULL);
	pthread_join(id[2], NULL);

	pthread_mutex_destroy(&lock);

	printf("The final value of item1_counter, item2_counter, and item3_counter are %d, %d, and %d\n", item1_counter, item2_counter, item3_counter);

	return 0;
}
