#include <iostream>
#include <pthread.h>
#include <random>
#include <unistd.h>

std::random_device rd;
std::default_random_engine eng(rd());
std::uniform_int_distribution<int> distr(1, 5);

pthread_mutex_t mutex_1_2 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex_2_3 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex_3_4 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex_4_5 = PTHREAD_MUTEX_INITIALIZER;

void *threadHandler1(void *ptr){	
	pthread_mutex_lock(&mutex_1_2);
	sleep(distr(eng));
	std::cout<<(char*)ptr<<std::endl;
	pthread_mutex_unlock(&mutex_1_2);
}

void *threadHandler2(void *ptr){
	pthread_mutex_lock(&mutex_2_3);
	pthread_mutex_lock(&mutex_1_2);
	sleep(distr(eng));
	std::cout<<(char*)ptr<<std::endl;
	pthread_mutex_unlock(&mutex_2_3);
}

void *threadHandler3(void *ptr){
	pthread_mutex_lock(&mutex_3_4);
	pthread_mutex_lock(&mutex_2_3);
	sleep(distr(eng));
	std::cout<<(char*)ptr<<std::endl;
	pthread_mutex_unlock(&mutex_3_4);
}

void *threadHandler4(void *ptr){
	pthread_mutex_lock(&mutex_4_5);
	pthread_mutex_lock(&mutex_3_4);
	sleep(distr(eng));
	std::cout<<(char*)ptr<<std::endl;
	pthread_mutex_unlock(&mutex_4_5);
}

void *threadHandler5(void *ptr){
	pthread_mutex_lock(&mutex_4_5);
	sleep(distr(eng));
	std::cout<<(char*)ptr<<std::endl;
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

