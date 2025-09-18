/*
..........................................................................................................................................
Name : 020.c
Author : SHRUTI VERMA
Description : Find out the priority of your running program. Modify the priority with nice command.
Date : 28 Aug 2025
..........................................................................................................................................
*/

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/resource.h>

int main() {
    printf("The priority of the process is : %d\n",getpriority(PRIO_PROCESS, 0));
    nice(9);
    printf("The modified priority of the process is : %d\n",getpriority(PRIO_PROCESS, 0));

    setpriority(PRIO_PROCESS, 0, 5);
    printf("The modified priority of the process is : %d\n",getpriority(PRIO_PROCESS, 0));
}


/*---------------------------------------OUTPUT-----------------------------------------------
        vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ gcc 020.c -o 020.out
        vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ ./020.out
        The priority of the process is : 0
        The modified priority of the process is : 9
        The modified priority of the process is : 9
*/