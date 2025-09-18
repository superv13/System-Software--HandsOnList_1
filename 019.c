/*
..........................................................................................................................................
Name : 019.c
Author : SHRUTI VERMA
Description : Write a program to find out time taken to execute getpid system call. Use time stamp counter.
Date : 1 Sept 2025
..........................................................................................................................................
*/
#define _POSIX_C_SOURCE 199309L
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<time.h>

int main() {
    
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    getpid();
    clock_gettime(CLOCK_MONOTONIC, &end);

    long ns = (end.tv_sec - start.tv_sec)*1e9 + (end.tv_nsec - start.tv_nsec);

   printf("time taken to execute getpid() system call : %ld\n", ns);
   

}

/*-------------------------------OUTPUT----------------------------------------------------
        vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ gcc 019.c -o 019.out
        vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ ./019.out
        time taken to execute getpid() system call : 16618
        vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ 
*/