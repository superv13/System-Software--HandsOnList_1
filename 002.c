/*
..........................................................................................................................................
Name : 002.c
Author : SHRUTI VERMA
Description : Write a simple program to execute in an infinite loop at the background. Go to /proc directory and
				identify all the process related information in the corresponding proc directory.
Date : 22 Aug 2025
..........................................................................................................................................
*/

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
int main(){

	int n = 139;
	int pid = getpid();
        char command[100];
	while(n){
        printf("infinity ");
		sprintf(command, "ls -l /proc/%d/cmdline", pid);
		sprintf(command, "ls -l /proc/%d/status", pid);
		system(command);
		sleep(5);
	}	
}

/*----------------------------------------------------------------------------------OUTPUT----------------------------------------------------------------------------------------------
 *
 *
 * 	vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/Learn/HoL-1$ gcc 002.c -o 002.out
	vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/Learn/HoL-1$ ./002.out &
	[1] 7908
	vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/Learn/HoL-1$ -r--r--r-- 1 vumma vumma 0 Aug 22 19:13 /proc/7908/status
	-r--r--r-- 1 vumma vumma 0 Aug 22 19:13 /proc/7908/status
	-r--r--r-- 1 vumma vumma 0 Aug 22 19:13 /proc/7908/status
	-r--r--r-- 1 vumma vumma 0 Aug 22 19:13 /proc/7908/status
	-r--r--r-- 1 vumma vumma 0 Aug 22 19:13 /proc/7908/status
	-r--r--r-- 1 vumma vumma 0 Aug 22 19:13 /proc/7908/status

 *
 * */

