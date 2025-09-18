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

//program to store a ticket

#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>

int main(void){

    struct {
        int ticket_no;
    } db;

    db.ticket_no = 23;
    int fd = open("db", O_CREAT | O_RDWR, 0744);
    write(fd, &db, sizeof(db));
    close(fd);
    fd = open("db", O_RDONLY);
    read(fd, &db, sizeof(db));
    printf("Ticket No : %d\n", db.ticket_no);
    close(fd);
}