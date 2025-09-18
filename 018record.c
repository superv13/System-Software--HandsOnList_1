/*
..........................................................................................................................................
Name : 018record.c
Author : SHRUTI VERMA
Description : Write a program to perform Record locking.
                a. Implement write lock
                b. Implement read lock
                Create three records in a file. Whenever you access a particular record, first lock it then modify/access
                to avoid race condition.
Date : 31 Aug 2025
..........................................................................................................................................
*/

#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>

int main() {
    int fd;
    struct {
        int train_no;
        int ticket_count;
    } db[4];

    for(int i=0; i<4; i++) {
        db[i].train_no = i+1;
        db[i].ticket_count = 0;
    }

    fd = open("record.txt", O_CREAT | O_RDWR);
    write(fd, &db, sizeof(db));
}

