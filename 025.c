
/*
..........................................................................................................................................
Name : 025.c
Author : SHRUTI VERMA
Description : Write a program to create three child processes. The parent should wait for a particular child (use
                waitpid system call).
Date : 28 Aug 2025
..........................................................................................................................................
*/

#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<stdlib.h>

int main(void) {
    int i, j, k;
    if(!(i=fork()))
        {
            sleep(1);
            printf("child 1\n");
            exit(0);
        }
       else if(!(j=fork()))
            {
                sleep(2);
                printf("child2\n");
                exit(0);
            }
            else if(!(k=fork()))
                {
                    sleep(3);
                    printf("child3\n");
                    exit(0);
                }
                else {
                        waitpid(getpid(), NULL, 0);
                        perror("ret : ");
                    }
} 

/*------------------------------------OUTPUT-----------------------------------------------------
            vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ gcc 025.c -o 025.out
            vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ ./025.out
            ret : : No child processes
            vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ child 1
            child2
            child3

*/