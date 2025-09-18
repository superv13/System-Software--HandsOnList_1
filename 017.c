/*
..........................................................................................................................................
Name : 017.c
Author : SHRUTI VERMA
Description : Write a program to simulate online ticket reservation. Implement write lock
              Write a program to open a file, store a ticket number and exit. Write a separate program, to
              open the file, implement write lock, read the ticket number, increment the number and print
              the new ticket number then close the file.
Date : 5 Sept 2025
..........................................................................................................................................
*/

#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>

struct {
    int ticket_no;
}db;

int main() {

    int fd, input;
    fd = open("db", O_RDWR);

    struct flock lock;
    fd = open("record.txt", O_RDWR);

    lock.l_type = F_WRLCK; 
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_pid = getpid();
    
    
    lseek(fd, 0, SEEK_SET);
    read(fd, &db, sizeof(db));
    
    printf("before entering into the critical section\n");
    fcntl(fd, F_SETLKW, &lock);
    
    printf("current Ticket No : %d\n", db.ticket_no);
    db.ticket_no++;
    
    write(fd, &db, sizeof(db));
    printf("incremented -->\t\t");
    printf("Ticket no : %d\n",db.ticket_no);
    // printf("press enter to unlock\n");
    getchar();

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);

    close(fd);

}

/*-------------------------------OUTPUT----------------------------------------------------
    vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ gcc 017.c -o 017.out
    vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ ./017.out
    before entering into the critical section
    current Ticket No : 1
    incremented -->         Ticket no : 2
*/