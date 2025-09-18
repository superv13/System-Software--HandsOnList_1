/*
..........................................................................................................................................
Name : 013.c
Author : SHRUTI VERMA
Description : Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
              verify whether the data is available within 10 seconds or not (check in $man 2 select).
Date : 26 Aug 2025
..........................................................................................................................................
*/

#include<unistd.h>
#include<stdio.h>
#include<sys/select.h>
#include<sys/time.h>

int main() {
    struct timeval tv;
    int ret;
    fd_set readfds;

    tv.tv_sec = 10;

    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO, &readfds);


    printf("waiting for input......\n");

    ret = select(STDIN_FILENO+1,&readfds,NULL,NULL,&tv);

    if(ret==-1) {
        perror("select");
    } else if(ret==0)
    printf("timed out");
    else {
        if(FD_ISSET(STDIN_FILENO, &readfds)){
        char buf[50];
        read(STDIN_FILENO, buf, sizeof(buf));
        printf("input from the STDIN : %s\n", buf);
    }
    return 0;

}


/*-------------------------OUTPUT--------------------------------------------

    vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ man select
    vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ gcc 013.c -o 013.out
    vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ ./013.out
    waiting for input......
    timed outvumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ ./013.out
    waiting for input......
    hello there!!!timed outvumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ hello there!!!
    hello there./013.out!
    vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ ./013.out
    waiting for input......
    hola amigo
    input from the STDIN : hola amigo
*/