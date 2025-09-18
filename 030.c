
/*
..........................................................................................................................................
Name : 030.c
Author : SHRUTI VERMA
Description : Write a program to run a script at a specific time using a Daemon process.
Date : 5 Sept 2025
..........................................................................................................................................
*/

#include<unistd.h>
#include<stdio.h>
#include<time.h>
#include<fcntl.h>
#include<sys/resource.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<sched.h>

int main(void) {

    int d = daemon(0,0);

    FILE *log = fopen("log.txt", "a");
    while(1) {
        time_t now = time(NULL);
        struct tm *t = localtime(&now);
       
        
        if(d!=-1)  {
            //task
            if(t->tm_min == 0) {
                int k = t->tm_hour;
                fprintf(log, "Time is %d hrs\n", k);
                fflush(log);
            }
        }else sleep(10);
    }
    fclose(log);    
} 

/*------------------------------------OUTPUT-----------------------------------------------------
        vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ gcc 030.c -o 030.out
        vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ ./030.out
        vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ cat log.txt
        vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ 

*/