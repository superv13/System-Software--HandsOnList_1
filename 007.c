/*
..........................................................................................................................................
Name : 007.c
Author : SHRUTI VERMA
Description : Write a program to copy file1 into file2 ($cp file1 file2).
Date : 22 Aug 2025
..........................................................................................................................................
*/

#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>

int main(){
	system("cp 004.txt file7.txt");
}

/*--------------------------------------------OUTPUT--------------------------------------------------------------------------------------------
		vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ gcc 007.c -o 007.oclear
		vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ cat 004.txt
		The contents of this file is meant to be passed to file 7..
		vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ ./007.out
		vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ cat file7.txt
		The contents of this file is meant to be passed to file 7..
*/
