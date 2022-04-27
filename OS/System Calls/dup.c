#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>

int main(){
	int fd1,fd2,fd3;
	fd1=open("abc.txt",O_RDWR);
	printf("File descriptor is:\t%d\n",fd1);
	
	fd2=dup(fd1);
	printf("Duplicate file descriptor is:\t%d\n",fd2);
	
	fd3=dup2(fd1,11);
	printf("Self assigned duplicate file descriptor is:\t%d\n",fd3);
	



}
