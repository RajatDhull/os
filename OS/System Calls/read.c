#include<stdio.h>
#include<unistd.h>
int main(){
char str[15];
printf("Enter a string:");
read(0,str,10);
//write(1,str,20);
write(1,str,5);
}
