/*
..........................................................................................................................................
Name : 014.c
Author : SHRUTI VERMA
Description : Write a program to find the type of a file.
                a. Input should be taken from command line.
                b. program should be able to identify any type of a file.
Date : 26 Aug 2025
..........................................................................................................................................
*/

#include<unistd.h>
#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(int argc, char *argv[]) {
    struct stat fileStatus;

   if(argc!=2) {

   }
   if(stat(argv[1], &fileStatus)==-1) {
        perror("stat");
   }

    if(S_ISREG(fileStatus.st_mode)) printf("regular file\n");
    else if(S_ISLNK(fileStatus.st_mode)) printf("symbolic link\n");
    else if(S_ISDIR(fileStatus.st_mode)) printf("directory file\n");
    else if(S_ISCHR(fileStatus.st_mode)) printf("character special file\n");
    else if(S_ISBLK(fileStatus.st_mode)) printf("block special file\n");
    else if(S_ISFIFO(fileStatus.st_mode)) printf("fifo file\n");
    else if(S_ISSOCK(fileStatus.st_mode)) printf("rsocket file\n");
    else printf("unknown");

}
/*-------------------------OUTPUT------------------------------------------------------------

        vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ ./014.out 014.out
        regular file
        vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ ./014.out soft
        regular file
        vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ ./014.out my_fifo 
        fifo file
        vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ 
*/

