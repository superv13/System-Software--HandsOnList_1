/*
..........................................................................................................................................
Name : 011.c
Author : SHRUTI VERMA
Description : Write a program to open a file, duplicate the file descriptor and append the file with both the
                descriptors and check whether the file is updated properly or not.
                a. use dup
                b. use dup2
                c. use fcntl
Date : 25 Aug 2025
..........................................................................................................................................
*/

#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>

int main() {
    int fd;
    fd = open("newFile2.txt", O_RDWR | O_CREAT | O_APPEND, 0666);

    int old_fd = dup(fd);
    printf("old fd : %d\n", old_fd);

    write(fd, "\nHey there from fd : old fd\n", 29);
    write(old_fd, "Hey there from fd : new fd\n", 28);

    int new_fd = dup2(fd, 11);
    printf("new fd : %d\n", new_fd);
}

/*--------------------------------OUTPUT--------------------------------------------------

        vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ gcc 011.c -o 011.out
        vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ ./011.out
        old fd : 4
        new fd : 11
        vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ cat newFile2.txt 

        Hey there from fd : oldHey there from fd : new vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ */