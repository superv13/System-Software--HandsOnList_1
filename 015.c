/*
..........................................................................................................................................
Name : 009.c
Author : SHRUTI VERMA
Description : Write a program to display the environmental variable of the user (use environ).
Date : 28 Aug 2025
..........................................................................................................................................
*/

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

extern char **environ;

int main() {

    int i = 0;
    printf("Environment variables : ");
    while(environ[i]!=NULL) {
        if(strncmp(environ[i], "USER=", 5)==0)
         {
            printf("%s\n ", environ[i]);
            break;
         }
        i++;
    }    

    return 0;
}

/*-------------------OUTPUT---------------------------------------------------------
        vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ gcc 015.c -o 015.out
        vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ ./015.out
        Environment variables : USER=vumma
*/