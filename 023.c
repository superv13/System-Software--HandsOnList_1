
/*
..........................................................................................................................................
Name : 023.c
Author : SHRUTI VERMA
Description : Write a program to create a Zombie state of the running program.
Date : 5 Sept 2025
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
        exit(0);
    }
    else {
        printf("parent process id : %d\n", getpid());
        sleep(50);
        wait(0);
    }
        
} 

/*------------------------------------OUTPUT-----------------------------------------------------
            vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ gcc 023.c -o 023.out
            vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ ./023.out
            parent process id : 10723
            Child process id : 10724         parent id : 10723

            vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ cat /proc/10724/status | head
            Name:   023.out
            State:  Z (zombie)
            Tgid:   10724
            Ngid:   0
            Pid:    10724
            PPid:   10723
            TracerPid:      0
            Uid:    1000    1000    1000    1000
            Gid:    1000    1000    1000    1000
            FDSize: 0

*/