/*
..........................................................................................................................................
Name : 003.c
Author : SHRUTI VERMA
Description : Write a program to create a file and print the file descriptor value. Use creat ( ) system call
Date : 22 Aug 2025
..........................................................................................................................................
*/
#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){

	int fd;
	fd = creat("003.c", O_RDWR);

	printf("File descriptor value of the file is : %d", fd);

	return 0;
}

/*-----------------------------------------OUTPUT---------------------------------------------------------------------------------------------------
	vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ gcc 003.c -o 003.out
	vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ ./003.out
	File descriptor value of the file is : 3vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ 


*/