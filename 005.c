/*
..........................................................................................................................................
Name : 001.c
Author : SHRUTI VERMA
Description : Write a program to create five new files with infinite loop. Execute the program in the background
              and check the file descriptor table at /proc/pid/fd.
Date : 19 Aug 2025
..........................................................................................................................................
*/

#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>

int main() {  
        int fds[5];
        const char *filename[5] = {
            "file1.txt",
            "file2.txt",
            "file3.txt",
            "file4.txt",
            "file5.txt",
        };


        for(int i=0; i<5; i++) {
            fds[i] = open(filename[i], O_CREAT | O_WRONLY, 0644);
            if(fds[i]== -1)
            {
                perror("error creating file");
                exit;
            }
            dprintf(fds[i], " This is %s\n ",filename[i]);
        }
        int pid = getpid();
        printf("Process ID : %d", pid);

        while(1) {
                sleep(1);
        }
        return 0;
        
}

/*---------------------------------------------OUTPUT---------------------------------------------------------------------

        vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ ./005.out &
        [2] 7058
        vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ cd /
        vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:/$ cd /proc/7058/fd
        vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:/proc/7058/fd$ ls
        0  1  103  2  3  41
        vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:/proc/7058/fd$ 

*/
