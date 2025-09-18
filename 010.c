/*
..........................................................................................................................................
Name : 010.c
Author : SHRUTI VERMA
Description : Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
            bytes (use lseek) and write again 10 bytes.
            a. check the return value of lseek
            b. open the file with od and check the empty spaces in between the data.
Date : 25 Aug 2025
..........................................................................................................................................
*/

#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>

int main() {

    int fd;
    fd  = open("newFile.txt", O_RDWR | O_CREAT, 0666);

    char buf1[10] = "AAAAAAAAAA";
    char buf2[10] = "BBBBBBBBBB";

    write(fd, buf1, 10);
    
    off_t offset = lseek(fd, 10, SEEK_CUR);
    printf("return vaue of offset : %ld\n", offset);

    write(fd, buf2, 10);
    
    close(fd);
    return 0;

}

/*-----------------------------------OUTPUT------------------------------------------------------------
        vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ gcc 010.c -o 010.0ut
        vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ ./010.0ut
        return vaue of offset : 20
        vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ od -c newFile.txt 
        0000000   A   A   A   A   A   A   A   A   A   A  \0  \0  \0  \0  \0  \0
        0000020  \0  \0  \0  \0   B   B   B   B   B   B   B   B   B   B
        0000036
        vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ ^C
        vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ 

*/