#include<unistd.h>
#include<fcntl.h>

int main(){
	int n,f1,f2,f3,f4;
	char buff[30]; //buffer to store data
	f1=open("abc.txt",O_RDWR);
	//here we will read from abc.txt and then will display it on screen...
	read(f1,buff,10);
	write(1,buff,10);
	f2=lseek(f1,10,SEEK_CUR); //move 10 position from current place...
	read(f1,buff,12);
	write(1,buff,12);
	f3=lseek(f1,8,SEEK_SET); //move the pointer 8 position from starting position...
	read(f1,buff,12);
	write(1,buff,12);
	f3=lseek(f1,-15,SEEK_END); //move the pointer from end...
	read(f1,buff,12);
	write(1,buff,12);
}
