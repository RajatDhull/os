#include<stdio.h>
#include<unistd.h>
#include<pthread.h>


pthread_mutex_t l;
int shared=1;

void *func1(void * args){
	printf("Thread1 trying to acquire lock\n");
	pthread_mutex_lock(&l);
	printf("Thread1 acquired lock\n");
	int x=shared;
	printf("The value of shared variable in func1(thread1) is: %d\n",x);
	x++;
	printf("The value of shared variable in func1(thread1) after local increment is: %d\n",x);
	sleep(1);
	shared=x;
	printf("The value of shared value after executing increment func1 is: %d\n",shared);
	pthread_mutex_unlock(&l);
	printf("Thread1 released lock\n");
}
void *func2(void * args){
	printf("Thread2 trying to acquire lock\n");
	pthread_mutex_lock(&l);
	printf("Thread2 acquired lock\n");
	int x=shared;
	printf("The value of shared variable in func2(thread2) is: %d\n",x);
	x--;
	printf("The value of shared variable in func2(thread2) after local decrement is: %d\n",x);
	sleep(1);
	shared=x;
	printf("The value of shared value after executing increment func2 is: %d\n",shared);
	pthread_mutex_unlock(&l);
	printf("Thread2 acquired lock\n");
}
int main(){
 	pthread_mutex_init(&l, NULL);
	pthread_t t1,t2;
	pthread_create(&t1,NULL,func1,NULL);
	pthread_create(&t2,NULL,func2,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	
	printf("Final value of shared variable is %d\n",shared);
}
