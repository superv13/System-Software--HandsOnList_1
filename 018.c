/*
..........................................................................................................................................
Name : 016.c
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

  struct {
        int train_no;
        int ticket_count;
    }db;

int main() {

    int fd, input;
    fd = open("record.txt", O_RDWR);
    printf("select train no from 1 - 4\n");
    scanf("%d", &input);

    struct flock lock2;

    //a: setting write lock on record of fd
    fd = open("record.txt", O_RDWR);
    lock2.l_type = F_WRLCK; 
    lock2.l_whence = SEEK_SET;
    lock2.l_start = (input-1)*sizeof(db);
    lock2.l_len = sizeof(db);
    lock2.l_pid = getpid();
    
    
    lseek(fd, (input-1)*sizeof(db), SEEK_SET);
    read(fd, &db, sizeof(db));
    printf("before entering into the critical section\n");
    
    fcntl(fd, F_SETLKW, &lock2);
    printf("current count : %d\n", db.ticket_count);
    db.ticket_count++;
    lseek(fd, -1 * sizeof(db), SEEK_CUR);
    write(fd, &db, sizeof(db));
    printf("to book ticket, press enter\n");
    getchar();


    getchar(); 
    lock2.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock2);
    printf("ticket booked on train no %d with ticket no %d\n", db.train_no, db.ticket_count);;

    int inp;
    printf("the train no (1-4) whose record you want to read \n");
    scanf("%d", &inp);
    
    //b: setting read lock on record of fd
    lock2.l_type = F_RDLCK; 
    lock2.l_whence = SEEK_SET;
    lock2.l_start = (inp-1)*sizeof(db);
    lock2.l_len = sizeof(db);
    lock2.l_pid = getpid();
    
    
    lseek(fd, (inp-1)*sizeof(db), SEEK_SET);
    read(fd, &db, sizeof(db));

    printf("before entering into the critical section\n");
    
    fcntl(fd, F_SETLKW, &lock2);
    
    getchar();

    lock2.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock2);
    printf("ticket  count of train no %d : %d\n", inp, db.ticket_count);

    close(fd);
   

}

/*-------------------------------OUTPUT----------------------------------------------------
    vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ gcc 018.c -o 018.out
    vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ ./018.out
    select train no from 1 - 4
    3
    before entering into the critical section
    current count : 7
    to book ticket, press enter

    ticket booked on train no 3 with ticket no 8
    the train no (1-4) whose record you want to read 
    3
    before entering into the critical section
    ticket  count of train no 3 : 8
*/