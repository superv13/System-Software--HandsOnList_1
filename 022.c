/*
..........................................................................................................................................
Name : 022.c
Author : SHRUTI VERMA
Description : Write a program, open a file, call fork, and then write to the file by both the child as well as the
                parent processes. Check output of the file.
Date : 01 Sept 2025
..........................................................................................................................................
*/

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>

int main() {
    int fd;
    fd = open("fork", O_CREAT|O_RDWR, 0644);
    
    int child;
    child = fork();

    if(child==0) {
        const char *msg = "written by the child\n";
        write(fd, msg, strlen(msg));
        printf("child wrote\n");
        close(fd);
    } else {
        const char *text = "written by the parent\n";
        write(fd, text, strlen(text));
        printf("parent wrote\n");
        close(fd);
        sleep(10);
    }
}


/*---------------------------------------OUTPUT-----------------------------------------------
        vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ gcc 022.c -o 022.out
        vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ ./022.out
        parent wrote
        child wrote
        vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ cat fork
        written by the parent
        written by the child
        vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$    
*/