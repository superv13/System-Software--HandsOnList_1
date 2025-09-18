#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>

struct {
    int train_no;
    int ticket_count;
} db;

int main() {
    int fd = open("record.txt", O_RDONLY);
    if(fd<0) 
    {
        perror("open");
        exit(0);
    }

    printf("train records\n");
    printf("-------------------\n");

    while(read(fd, &db, sizeof(db))) {
        printf("train no : %d   ", db.train_no);
        printf("ticket count : %d\n", db.ticket_count);
    }
    close(fd);
    return 0;


}