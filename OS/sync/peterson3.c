#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<sys/wait.h>
#include<stdlib.h>

int ready[2];
int turn;
int counter=0;
pthread_t t1,t2;
void *thread_func1(void *args){
	
	if(pthread_equal(t1,pthread_self())){
		ready[0]=1;
		turn=1;
		while(ready[1]&&turn==1);
		//critical section
		counter++;
		printf("Hey, I am first thread,received CPU\n");
		printf("Counter is now %d\n\n",counter);
		ready[1]=0; 
	}
	else if(pthread_equal(t2,pthread_self())){
		ready[1]=1;
		turn=0;
		while(ready[0]&&turn==0);
		//critical section
		counter++;
		printf("Hey, I am second thread,received CPU\n");
		printf("Counter is now %d\n\n",counter);
		ready[0]=0;
	}
}
int main(){
//pthread_t t1,t2;
while(counter<=25){
pthread_create(&t1,NULL,thread_func1,NULL);
pthread_create(&t2,NULL,thread_func1,NULL);
}
//pthread_join(t1,NULL);
//pthread_join(t2,NULL);
printf("Hey, I am in the main function after execution of threads \n");
}
