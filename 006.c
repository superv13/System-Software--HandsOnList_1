/*
..........................................................................................................................................
Name : 002.c
Author : SHRUTI VERMA
Description : Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
Date : 22 Aug 2025
..........................................................................................................................................
*/

#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>

int main() {

	char buffer[128];
	
	ssize_t data = read(0, buffer, sizeof(buffer)-1);
	write(1, buffer, data);
}


/*------------------------------------OUTPUT--------------------------------------------------------------------------------------------------
		vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ gcc 006.c -o 006.out
		vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ ./006.out
		Hello there, trying to complete the assignment.
		Hello there, trying to complete the assignment.
		vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ 

*/
