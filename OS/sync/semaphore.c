#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>

sem_t s;
int shared=1;

void *func1(void * args){
	sem_wait(&s);
	int x=shared;
	printf("The value of shared variable in func1(thread1) is: %d\n",x);
	x++;
	printf("The value of shared variable in func1(thread1) after local increment is: %d\n",x);
	sleep(1);
	shared=x;
	printf("The value of shared value after executing increment func1 is: %d\n",shared);
	sem_post(&s);
}
void *func2(void * args){
	sem_wait(&s);
	int x=shared;
	printf("The value of shared variable in func2(thread2) is: %d\n",x);
	x--;
	printf("The value of shared variable in func2(thread2) after local decrement is: %d\n",x);
	sleep(1);
	shared=x;
	printf("The value of shared value after executing increment func2 is: %d\n",shared);
	sem_post(&s);
}
int main(){
sem_init(&s,0,1);
	pthread_t t1,t2;
	pthread_create(&t1,NULL,func1,NULL);
	pthread_create(&t2,NULL,func2,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	
	printf("Final value of shared variable is %d",shared);
}
