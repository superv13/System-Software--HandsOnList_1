/*
..........................................................................................................................................
Name : 012.c
Author : SHRUTI VERMA
Description : Write a program to find out the opening mode of a file. Use fcntl.
Date : 22 Aug 2025
..........................................................................................................................................
*/

#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>

int main() {
    int fd;
    fd = open("file7.txt",O_RDWR, 0666);

    int flags = fcntl(fd, F_GETFL);
    int mode = flags & O_ACCMODE;

    if(mode == O_RDWR) printf("file opened in read and write mode");
    else if(mode == O_RDONLY) printf("file opened in read only mode");
    else if(mode == O_WRONLY) printf("file opened in write only mode");

    if(flags && O_APPEND)
    printf("file opened with append mode");

    if(flags & O_CREAT)
    printf("file opened with creat mode");

    close(fd);
    
}
/*---------------------OUTPUT---------------------------------------------------------------
vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ gcc 012.c -o 012.out
vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ ./012.out
file opened in read and write modevumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ 
*/