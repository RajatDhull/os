
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

//This is thread function
void *thread_function1(void *arg) {    
int i;
 printf("Inside Thread with ID: %ld\n",pthread_self());
 int sum=0;
 for(i=1;i<=5;i++)
 {
 sum+=i;
 }
 printf("Sum: %d\n",sum);
 pthread_exit("Thread Work over!!");
 }
 
 void *thread_function2(void *arg){
 int i,sum=0;
 printf("Inside thread func2 with ID: %ld\n",pthread_self());
 int *arr=arg;
 	for(i=0;i<10;i++){
 		sum+=arr[i];
 	}
 	printf("Sum is: %d\n",sum);
 	pthread_exit("Sum calculated");
 }
 
 void *thread_function3(void *arg){
 int temp,i,j;
 int *a=arg;
 printf("Inside thread func3 with ID: %ld\n",pthread_self());
  for(i=0;i<10;i++)
  {
   for(j=0;j<9;j++)
   {
    if(a[j]>a[j+1])
    {
     temp=a[j];
     a[j]=a[j+1];
     a[j+1]=temp;
    }
  }
 }
 for(i=0;i<10;i++){
 printf("%d  ",a[i]);
 }
 printf("\n");
 pthread_exit("Array Sorted");
 }
 
 void *thread_function4(void *arg){
 	int max=-9999;
 	int *arr=arg;
 	printf("Inside thread func4 with ID: %ld\n",pthread_self());
 	if(arr[0]>max) max=arr[0];
 	if(arr[1]>max) max=arr[1];
 	if(arr[2]>max) max=arr[2];
 	printf("Among %d,%d,%d, %d is the largest\n",arr[0],arr[1],arr[2],max);
 	pthread_exit("Largest number found!!");
 }
 int main() {
 int i,j;
 void * res1,*res2,*res3,*res4;
 int arr[10]={1,2,3,4,5,6,7,8,9,10};
 int arr2[10]={5,4,3,2,1,10,9,8,7,6};
 int arr3[3]={30,25,50};
pthread_t thread1,thread2,thread3,thread4;  //thread declaration
 //thread creation
 pthread_create(&thread1, NULL, thread_function1, NULL);
 pthread_create(&thread2, NULL, thread_function2, (void *)arr);
 pthread_create(&thread3,NULL,thread_function3,(void *)arr2);
 pthread_create(&thread4,NULL,thread_function4,(void *)arr3);
 pthread_join(thread1, &res1);//process waits for thread to finish, store argument of pthread_exit in res1
 pthread_join(thread2, &res2);
 pthread_join(thread3, &res3);
 pthread_join(thread4,&res4);
 printf("\nInside Main\n");
 printf("Thread returned: %s\n",(char*)res1);
 printf("Thread returned: %s\n",(char*)res2);
 printf("Thread returned: %s\n",(char*)res3);
  printf("Thread returned: %s\n",(char*)res4);
 }
