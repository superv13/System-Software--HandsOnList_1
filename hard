/*
..........................................................................................................................................
Name : 001.c
Author : SHRUTI VERMA
Description : Create the following types of a files using (i) shell command (ii) system call
				a. soft link (symlink system call)
				b. hard link (link system call)
				c. FIFO (mkfifo Library Function or mknod system call)
Date : 19 Aug 2025
..........................................................................................................................................
*/

#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>

int main(void) {
	
	system("ln 001.c hard"); //creating hard link named "hard" for "myfifo"
        system("ln -s hard soft"); //creating symbolic link named "soft" for"hard"
        system("mkfifo FIFO"); //creating a pipe named FIFO


	if(link("001.c", "Hlink.txt")==0)
		printf("Hard Link Created");
	
	if(symlink("001.txt", "Slink")==0)
		printf("Soft Link Created");
	
	const char* myfifo = "my_fifo";
		if(mkfifo(myfifo, 0666)==0)
		printf("my_fifo created");
	
	 
}

/*	-------------------------------------------------OUTPUT----------------------------------------------------------------------------------
	vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ gcc 001.c -o 001.out
	vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ ./001.out
	Hard Link CreatedSoft Link Createdmy_fifo createdvumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ ^C
*/