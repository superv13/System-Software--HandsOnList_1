
/*
..........................................................................................................................................
Name : 026.c
Author : SHRUTI VERMA
Description : Write a program to execute an executable program.
a. use some executable program
b. pass some input to an executable program. (for example execute an executable of $./a.out name)
Date : 5 Sept 2025
..........................................................................................................................................
*/

#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<stdlib.h>

int main(void) {

    execl("/home/vumma/Desktop/HOL1/025.out","./025.out", NULL);
        
} 

/*------------------------------------OUTPUT-----------------------------------------------------
        vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ gcc 026.c -o 026.out
        vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ ./026.out
        ret : : No child processes
        vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ child 1
        child2
        child3

*/