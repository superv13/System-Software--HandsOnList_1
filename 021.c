/*
..........................................................................................................................................
Name : 021.c
Author : SHRUTI VERMA
Description : Write a program, call fork and print the parent and child process id.
Date : 01 Sept 2025
..........................................................................................................................................
*/

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/resource.h>

int main() {
    int child;
    child = fork();

    if(child==0) {
        printf("child process pid : %d\t ppid : %d\n", getpid(), getppid());
    } else {
        printf("parent process pid : %d\n", getpid());
        sleep(10);
    }
}


/*---------------------------------------OUTPUT-----------------------------------------------
    vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ gcc 021.c -o 021.out
    vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ ./021.out
    parent process pid : 9082
    child process pid : 9083         ppid : 9082    
*/