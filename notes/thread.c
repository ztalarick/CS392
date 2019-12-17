#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int counter = 0;
pthread_mutex_t lock;

void* run_thread(void* noarg){
	
	pthread_mutex_lock(&lock);
	for(int i = 0; i < 1000000; i++){
		counter++;
	}
	pthread_mutex_unlock(&lock);
	
	pthread_exit(NULL);
	return NULL;
}

int main(void){
	pthread_t id;
	pthread_t id2;
	
	pthread_mutex_init(&lock, NULL);

	pthread_create(&id, NULL, run_thread, NULL);
	pthread_create(&id2, NULL, run_thread, NULL);

	pthread_join(id, NULL);
	pthread_join(id2, NULL);

	pthread_mutex_destroy(&lock);

	printf("%d\n", counter);
	return 0;
}
