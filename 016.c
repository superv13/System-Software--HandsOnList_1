/*
..........................................................................................................................................
Name : 016.c
Author : SHRUTI VERMA
Description : Write a program to perform mandatory locking.
                a. Implement write lock
                b. Implement read lock
Date : 31 Aug 2025
..........................................................................................................................................
*/

#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>

int main() {
    struct flock lock1, lock2;
    int fd1, fd2; 
    
    //a : setting read lock on fd1
    fd1 = open("newFile.txt", O_RDWR);
    lock1.l_type = F_RDLCK; 
    lock1.l_whence = SEEK_SET;
    lock1.l_start = 0;
    lock1.l_len = 0;
    lock1.l_pid = getpid();
    printf("before entering into the ecritical section\n");
    fcntl(fd1, F_SETLKW, &lock1);
    printf("inside rhe critical section with read lock\n");
    printf("enter to unlock\n");

    getchar();
    printf("unlocked\n");
    lock1.l_type = F_UNLCK;
    fcntl(fd1, F_SETLK, &lock1);
    printf("end\n");
    printf("\n");

    //b : setting read lock on fd2
    fd2 = open("newFile.txt", O_RDWR);
    lock2.l_type = F_WRLCK; //a
    lock2.l_whence = SEEK_SET;
    lock2.l_start = 0;
    lock2.l_len = 0;
    lock2.l_pid = getpid();
    printf("before entering into the ecritical section\n");
    fcntl(fd2, F_SETLKW, &lock2);
    printf("inside rhe critical section with write lock\n");
    printf("enter to unlock\n");

    getchar();
    printf("unlocked\n");
    lock1.l_type = F_UNLCK;
    fcntl(fd2, F_SETLK, &lock2);
    printf("end\n");

}

/*-------------------------------OUTPUT----------------------------------------------------
        vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ gcc 016.c -o 016.out
        vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ ./016.out
        before entering into the ecritical section
        inside rhe critical section with read lock
        enter to unlock

        unlocked
        end

        before entering into the ecritical section
        inside rhe critical section with write lock
        enter to unlock
        
        unlocked
        end
        vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ 
*/