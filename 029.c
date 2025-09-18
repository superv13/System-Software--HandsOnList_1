
/*
..........................................................................................................................................
Name : 029.c
Author : SHRUTI VERMA
Description : Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
SCHED_RR).
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

        int pid = getpid();
        
        struct sched_param param;
        param.sched_priority = 1;

        int S1 = sched_getscheduler(pid);
        printf("Scheduling policy of %d is %d\n", pid, S1);

        printf("setting scheduling policy to FIFO ->\n"); 
        int d = sched_setscheduler(pid, SCHED_FIFO, &param);
        if(d!=-1){
            int S2 = sched_getscheduler(pid);
            printf("\tScheduling policy of %d is %d\n", pid, S2);
        }
        else printf("scheduling failed\n");

        printf("setting scheduling policy to RR -> \n");
        int e = sched_setscheduler(pid, SCHED_RR, &param);
        if(e!=-1){
            int S3 = sched_getscheduler(pid);
            printf("\tScheduling policy of %d is %d\n", pid, S3);
    
        }else printf("scheduling failed\n");

        
} 

/*------------------------------------OUTPUT-----------------------------------------------------
    vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ gcc 029.c -o  029.out
    vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ sudo ./029.out
    Scheduling policy of 24219 is 0
    setting scheduling policy to FIFO ->
            Scheduling policy of 24219 is 1
    setting scheduling policy to RR -> 
            Scheduling policy of 24219 is 2
    vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ 

*/