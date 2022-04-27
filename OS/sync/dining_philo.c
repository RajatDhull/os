#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
sem_t chopstick[5];
void * func1(void * n)
 {
         int p=*(int *)n;
         printf("Philosopher %d wishes to eat\n",p+1);
         printf("Philosopher %d tries to pick left chopstick\n",p+1);
         sem_wait(&chopstick[p]);	//this will check if the left chopstick is free, if it is free, then give it to him
         printf("Philosopher %d picks the left chopstick\n",p+1);
         printf("Philosopher %d tries to pick the right chopstick\n",p+1);
         // waiting for right chopstick
         sem_wait(&chopstick[(p+1)%5]);
         printf("Philosopher %d picks the right chopstick\n",p+1);
         printf("Philosopher %d begins to eat\n",p+1);	//philosopher starts eating
         sleep(1);
         printf("Philosopher %d has finished eating\n",p+1);
         sem_post(&chopstick[(p+1)%5]);
         printf("Philosopher %d puts the right chopstick\n",p+1);
         sem_post(&chopstick[p]);
         printf("Philosopher %d puts the left chopstick\n",p+1);
 }

int main()
 {
         int i,n[5];
         pthread_t T[5];
         //initializing 5 chopsticks as available
         for(i=0;i<5;i++)
         sem_init(&chopstick[i],0,1);	//here 0 indicates we are using thread,1 indicates the availability of chopstick
         //here we are creating 5 threads denoting each philosophers
         for(i=0;i<5;i++){
                 n[i]=i;
                 pthread_create(&T[i],NULL,func1,(void *)&n[i]);
                 }
         //This ensures that all thread execution takes place before termination of program
         for(i=0;i<5;i++)
                 pthread_join(T[i],NULL);
         printf("Now we are in main function after execution of all threads\n");
 }
