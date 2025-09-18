
/*
..........................................................................................................................................
Name : 024.c
Author : SHRUTI VERMA
Description : Write a program to create an orphan process.
Date : 02 Sept 2025
..........................................................................................................................................
*/

#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<stdlib.h>

int main(void) {
    if(!fork()) {
        printf("Child process id : %d\t parent id : %d\n", getpid(),getppid());
        sleep(1);
        printf("after being abandoned parent process id : %d\n", getppid());
    }
    else {
        printf("parent process id : %d\n", getpid());
        exit(0);
    }
        
} 

/*------------------------------------OUTPUT-----------------------------------------------------
            vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ gcc 024.c -o 024.out
            vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ ./024.out
            parent process id : 4519
            Child process id : 4520  parent id : 4519
            vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ after being abandoned parent process id : 1866

*/