
/*
..........................................................................................................................................
Name : 028.c
Author : SHRUTI VERMA
Description : Write a program to get maximum and minimum real time priority.
Date : 5 Sept 2025
..........................................................................................................................................
*/

#include<unistd.h>
#include<stdio.h>
#include<sys/time.h>
#include<sys/resource.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<sched.h>

int main(void) {

    int maxF = sched_get_priority_max(SCHED_FIFO);
    int minF = sched_get_priority_min(SCHED_FIFO);

    int maxR = sched_get_priority_max(SCHED_RR);
    int minR = sched_get_priority_min(SCHED_RR);

    printf("Maximum real time priority of FIFO sched: %d\n", maxF);
    printf("Minimum real time priority of FIFO sched: %d\n", minF);
    printf("Maximum real time priority of RR sched: %d\n", maxR);
    printf("Mininmum real time priority of RR sched: %d\n", minR);
        
} 

/*------------------------------------OUTPUT-----------------------------------------------------
        vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ gcc 028.c -o 028.out
        vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ ./028.out
        Maximum real time priority of FIFO sched: 99
        Minimum real time priority of FIFO sched: 1
        Maximum real time priority of RR sched: 99
        Mininmum real time priority of RR sched: 1
        vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ 

*/