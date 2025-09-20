/*
..........................................................................................................................................
Name : 004.c
Author : SHRUTI VERMA
Description : Write a program to open an existing file with read write mode. Try O_EXCL flag also.
..........................................................................................................................................
*/

#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<fcntl.h>

int main() {

	int fd;
	fd = open("004.txt", O_CREAT|O_EXCL|O_RDWR, 0666); //6 - read and write
	
	printf("file %d opened in read and write mode", fd);
	return 0;
}
/*---------------------------------------------------------OUTPUT------------------------------------------------------------------------------------
		vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ gcc 004.c -o 004.out
		vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ ./004.out
		file 3 opened in read and write modevumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ ^C
		vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ 

*/
