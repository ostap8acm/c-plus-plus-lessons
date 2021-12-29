#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <ctime>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void delay_print(void *ptr)
{	
	srand(time(NULL));
	int secconds = (1 + rand() % 5);	
	sleep(secconds);
	std::cout<<(char*)ptr<<"	Second delay:"<<secconds<<std::endl;
}

void *threadHandler1(void *ptr){	
	pthread_mutex_lock(&mutex);
	delay_print(ptr);
	pthread_mutex_unlock(&mutex);
}

void *threadHandler2(void *ptr){
	pthread_mutex_lock(&mutex);
	delay_print(ptr);
	pthread_mutex_unlock(&mutex);
}

void *threadHandler3(void *ptr){
	pthread_mutex_lock(&mutex);
	delay_print(ptr);
	pthread_mutex_unlock(&mutex);
}

void *threadHandler4(void *ptr){
	pthread_mutex_lock(&mutex);
	delay_print(ptr);
	pthread_mutex_unlock(&mutex);
}

void *threadHandler5(void *ptr){
	pthread_mutex_lock(&mutex);
	delay_print(ptr);
	pthread_mutex_unlock(&mutex);
}



int main(int argc, char **argv)
{    	
	pthread_t thread1, thread2, thread3, thread4, thread5;
	
	char message1[] = "Thread 1";
    char message2[] = "Thread 2";
	char message3[] = "Thread 3";
    char message4[] = "Thread 4";
	char message5[] = "Thread 5";

	pthread_create( &thread1, NULL, threadHandler1, (void*)message1);
	pthread_create( &thread2, NULL, threadHandler2, (void*)message2);
	pthread_create( &thread3, NULL, threadHandler3, (void*)message3);
	pthread_create( &thread4, NULL, threadHandler4, (void*)message4);
	pthread_create( &thread5, NULL, threadHandler5, (void*)message5);
	
	pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);
    pthread_join(thread3,NULL);
	pthread_join(thread4,NULL);
    pthread_join(thread5,NULL);
	
	return 0;
}
