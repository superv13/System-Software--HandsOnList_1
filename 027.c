
/*
..........................................................................................................................................
Name : 027.c
Author : SHRUTI VERMA
Description : Write a program to execute ls -Rl by the following system calls
                a. execl
                b. execlp
                c. execle
                d. execv
                e. execvp
Date : 5 Sept 2025
..........................................................................................................................................
*/

#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<stdlib.h>

int main(void) {
    int i, j, k, l , m;
    char *c[] = {"ls", "-Rl", NULL};
    char *env[] = {"USER=vumma", NULL};

    if(!(i=fork())){

        printf("\n\nls -Rl from execl\n\n");
        execl("/bin/sh","sh","-c", "ls -Rl | head", NULL);
        
    }
    wait(NULL);

    if(!(j=fork())) {

        printf("\n\nls -Rl from execlp\n\n");
        execlp("ls", "ls -Rl", NULL);
       
    } 
    wait(NULL);


    if(!(k=fork())) {

        printf("\n\nls -Rl from execle\n\n");
        execle("/bin/ls", "ls", "-Rl", (char*)NULL, env);
        
    }
    wait(NULL);

    if(!(l=fork())) {

        printf("\n\nls -Rl from execv\n\n");
        execv("/bin/ls", c);
        
    }
    wait(NULL);

    if(!(m=fork())){

        printf("\n\nls -Rl from execvp\n\n");
        execvp("ls", c);
        
    }
        
} 

/*------------------------------------OUTPUT-----------------------------------------------------
        vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ gcc 027.c -o 027.out
        vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ ./027.out


        ls -Rl from execl

        .:
        total 692
        -rwxr-xr-x 5 vumma vumma  1537 Aug 22 23:18 001.c
        -rwxrwxr-x 1 vumma vumma 16112 Aug 22 23:14 001.out
        -rw-rw-r-- 1 vumma vumma  1658 Aug 22 23:20 002.c
        -rwxrwxr-x 1 vumma vumma 16168 Aug 22 23:18 002.out
        -rw-rw-r-- 1 vumma vumma  1078 Aug 22 23:23 003.c
        -rwxrwxr-x 1 vumma vumma 16000 Aug 22 23:21 003.out
        -rw-rw-r-- 1 vumma vumma  1170 Aug 22 23:33 004.c
        -rwxrwxr-x 1 vumma vumma 16000 Aug 22 23:23 004.out


        ls -Rl from execlp

        001.c	 003.out  005.out     007.out  010.0ut	012.out  015	  018.c		  019.out  021.out  024      026.c    FIFO	 Hlink.txt	readrecords.out
        001.out  004.c	  006.c       008.c    010.c	013.c	 015.c	  018.out	  020	   022.c    024.c    026.out  file1.txt  my_fifo	record.txt
        002.c	 004.out  006.out     008.out  011.c	013.out  015.out  018record.c	  020.c    022.out  024.out  027.c    file7.txt  newFile2.txt	Slink
        002.out  004.txt  007.c       009.c    011.out	014.c	 016.c	  0.18record.out  020.out  023.c    025.c    027.out  fork	 newFile.txt	soft
        003.c	 005.c	  007.oclear  009.out  012.c	014.out  016.out  019.c		  021.c    023.out  025.out  a.out    hard	 readrecords.c


        ls -Rl from execle

        .:
        total 692
        -rwxrwxr-x 1 vumma vumma 16056 Aug 31 16:13 0.18record.out
        -rwxr-xr-x 5 vumma vumma  1537 Aug 22 23:18 001.c
        -rwxrwxr-x 1 vumma vumma 16112 Aug 22 23:14 001.out
        -rw-rw-r-- 1 vumma vumma  1658 Aug 22 23:20 002.c
        -rwxrwxr-x 1 vumma vumma 16168 Aug 22 23:18 002.out
        -rw-rw-r-- 1 vumma vumma  1078 Aug 22 23:23 003.c
        -rwxrwxr-x 1 vumma vumma 16000 Aug 22 23:21 003.out
        -rw-rw-r-- 1 vumma vumma  1170 Aug 22 23:33 004.c
        -rwxrwxr-x 1 vumma vumma 16000 Aug 22 23:23 004.out
        -rw-rw-r-- 1 vumma vumma    60 Aug 22 23:30 004.txt
        -rw-rw-r-- 1 vumma vumma  1781 Aug 25 20:01 005.c
        -rwxrwxr-x 1 vumma vumma 16136 Aug 23 00:16 005.out
        -rw-rw-r-- 1 vumma vumma  1083 Aug 22 23:26 006.c
        -rwxrwxr-x 1 vumma vumma 16048 Aug 22 23:25 006.out
        -rw-rw-r-- 1 vumma vumma  1112 Aug 22 23:32 007.c
        -rwxrwxr-x 1 vumma vumma 15960 Aug 22 23:30 007.oclear
        -rwxrwxr-x 1 vumma vumma 15960 Aug 22 23:27 007.out
        -rw-rw-r-- 1 vumma vumma  1536 Aug 22 22:58 008.c
        -rwxrwxr-x 1 vumma vumma 16176 Aug 25 20:09 008.out
        -rw-rw-r-- 1 vumma vumma  2174 Aug 26 10:06 009.c
        -rwxrwxr-x 1 vumma vumma 16176 Aug 25 20:41 009.out
        -rwxrwxr-x 1 vumma vumma 16176 Aug 25 21:52 010.0ut
        -rw-rw-r-- 1 vumma vumma  1735 Aug 26 10:06 010.c
        -rw-rw-r-- 1 vumma vumma  1506 Aug 26 10:06 011.c
        -rwxrwxr-x 1 vumma vumma 16128 Aug 25 22:17 011.out
        -rw-rw-r-- 1 vumma vumma  1326 Aug 26 10:06 012.c
        -rwxrwxr-x 1 vumma vumma 16088 Aug 25 22:41 012.out
        -rw-rw-r-- 1 vumma vumma  1912 Aug 26 10:06 013.c
        -rwxrwxr-x 1 vumma vumma 16176 Aug 26 09:16 013.out
        -rw-rw-r-- 1 vumma vumma  1758 Aug 26 10:05 014.c
        -rwxrwxr-x 1 vumma vumma 16136 Aug 26 09:53 014.out
        -rwxrwxr-x 1 vumma vumma 17592 Aug 28 15:20 015
        -rw-rw-r-- 1 vumma vumma  1018 Aug 31 12:05 015.c
        -rwxrwxr-x 1 vumma vumma 16072 Aug 28 15:21 015.out
        -rw-rw-r-- 1 vumma vumma  2188 Aug 31 12:05 016.c
        -rwxrwxr-x 1 vumma vumma 16224 Aug 31 15:34 016.out
        -rw-rw-r-- 1 vumma vumma  2705 Aug 31 12:05 018.c
        -rwxrwxr-x 1 vumma vumma 16464 Aug 31 12:05 018.out
        -rw-rw-r-- 1 vumma vumma   696 Aug 31 16:09 018record.c
        -rw-rw-r-- 1 vumma vumma  1152 Sep  1 14:20 019.c
        -rwxrwxr-x 1 vumma vumma 16104 Sep  1 14:19 019.out
        -rwxrwxr-x 1 vumma vumma 17800 Aug 28 14:42 020
        -rw-rw-r-- 1 vumma vumma  1199 Aug 28 14:53 020.c
        -rwxrwxr-x 1 vumma vumma 16096 Aug 28 14:51 020.out
        -rw-rw-r-- 1 vumma vumma  1038 Sep  1 14:26 021.c
        -rwxrwxr-x 1 vumma vumma 16128 Sep  1 14:26 021.out
        -rw-rw-r-- 1 vumma vumma  1417 Sep  1 14:46 022.c
        -rwxrwxr-x 1 vumma vumma 16208 Sep  1 14:45 022.out
        -rw-rw-r-- 1 vumma vumma  1498 Sep  5 14:01 023.c
        -rwxrwxr-x 1 vumma vumma 16216 Sep  5 13:11 023.out
        -rwxrwxr-x 1 vumma vumma 17768 Aug 28 14:50 024
        -rw-rw-r-- 1 vumma vumma  1255 Sep  4 04:47 024.c
        -rwxrwxr-x 1 vumma vumma 16168 Sep  4 05:18 024.out
        -rw-rw-r-- 1 vumma vumma  1488 Sep  5 14:26 025.c
        -rwxrwxr-x 1 vumma vumma 16216 Sep  5 14:25 025.out
        -rw-rw-r-- 1 vumma vumma   956 Sep  5 14:27 026.c
        -rwxrwxr-x 1 vumma vumma 15960 Sep  5 14:27 026.out
        -rw-rw-r-- 1 vumma vumma  1686 Sep  5 15:38 027.c
        -rwxrwxr-x 1 vumma vumma 16304 Sep  5 15:38 027.out
        prw-rw-r-- 1 vumma vumma     0 Aug 22 23:14 FIFO
        -rwxr-xr-x 5 vumma vumma  1537 Aug 22 23:18 Hlink.txt
        lrwxrwxrwx 1 vumma vumma     7 Aug 22 23:14 Slink -> 001.txt
        -rwxrwxr-x 1 vumma vumma 16056 Aug 31 16:07 a.out
        -rw-r--r-- 1 vumma vumma    20 Aug 25 19:59 file1.txt
        -rw-rw-r-- 1 vumma vumma    60 Aug 25 21:47 file7.txt
        -rw-rw-rw- 1 vumma vumma    43 Sep  1 14:45 fork
        -rwxr-xr-x 5 vumma vumma  1537 Aug 22 23:18 hard
        prw-rw-r-- 1 vumma vumma     0 Aug 22 23:14 my_fifo
        -rw-rw-r-- 1 vumma vumma   155 Aug 25 22:15 newFile.txt
        -rw-rw-r-- 1 vumma vumma    48 Aug 25 22:17 newFile2.txt
        -rw-rw-r-- 1 vumma vumma   506 Aug 31 11:01 readrecords.c
        -rwxrwxr-x 1 vumma vumma 16248 Aug 31 11:01 readrecords.out
        -rw-rw-rw- 1 vumma vumma    32 Aug 31 12:05 record.txt
        lrwxrwxrwx 1 vumma vumma     4 Aug 22 23:14 soft -> hard


        ls -Rl from execv

        .:
        total 692
        -rwxr-xr-x 5 vumma vumma  1537 Aug 22 23:18 001.c
        -rwxrwxr-x 1 vumma vumma 16112 Aug 22 23:14 001.out
        -rw-rw-r-- 1 vumma vumma  1658 Aug 22 23:20 002.c
        -rwxrwxr-x 1 vumma vumma 16168 Aug 22 23:18 002.out
        -rw-rw-r-- 1 vumma vumma  1078 Aug 22 23:23 003.c
        -rwxrwxr-x 1 vumma vumma 16000 Aug 22 23:21 003.out
        -rw-rw-r-- 1 vumma vumma  1170 Aug 22 23:33 004.c
        -rwxrwxr-x 1 vumma vumma 16000 Aug 22 23:23 004.out
        -rw-rw-r-- 1 vumma vumma    60 Aug 22 23:30 004.txt
        -rw-rw-r-- 1 vumma vumma  1781 Aug 25 20:01 005.c
        -rwxrwxr-x 1 vumma vumma 16136 Aug 23 00:16 005.out
        -rw-rw-r-- 1 vumma vumma  1083 Aug 22 23:26 006.c
        -rwxrwxr-x 1 vumma vumma 16048 Aug 22 23:25 006.out
        -rw-rw-r-- 1 vumma vumma  1112 Aug 22 23:32 007.c
        -rwxrwxr-x 1 vumma vumma 15960 Aug 22 23:30 007.oclear
        -rwxrwxr-x 1 vumma vumma 15960 Aug 22 23:27 007.out
        -rw-rw-r-- 1 vumma vumma  1536 Aug 22 22:58 008.c
        -rwxrwxr-x 1 vumma vumma 16176 Aug 25 20:09 008.out
        -rw-rw-r-- 1 vumma vumma  2174 Aug 26 10:06 009.c
        -rwxrwxr-x 1 vumma vumma 16176 Aug 25 20:41 009.out
        -rwxrwxr-x 1 vumma vumma 16176 Aug 25 21:52 010.0ut
        -rw-rw-r-- 1 vumma vumma  1735 Aug 26 10:06 010.c
        -rw-rw-r-- 1 vumma vumma  1506 Aug 26 10:06 011.c
        -rwxrwxr-x 1 vumma vumma 16128 Aug 25 22:17 011.out
        -rw-rw-r-- 1 vumma vumma  1326 Aug 26 10:06 012.c
        -rwxrwxr-x 1 vumma vumma 16088 Aug 25 22:41 012.out
        -rw-rw-r-- 1 vumma vumma  1912 Aug 26 10:06 013.c
        -rwxrwxr-x 1 vumma vumma 16176 Aug 26 09:16 013.out
        -rw-rw-r-- 1 vumma vumma  1758 Aug 26 10:05 014.c
        -rwxrwxr-x 1 vumma vumma 16136 Aug 26 09:53 014.out
        -rwxrwxr-x 1 vumma vumma 17592 Aug 28 15:20 015
        -rw-rw-r-- 1 vumma vumma  1018 Aug 31 12:05 015.c
        -rwxrwxr-x 1 vumma vumma 16072 Aug 28 15:21 015.out
        -rw-rw-r-- 1 vumma vumma  2188 Aug 31 12:05 016.c
        -rwxrwxr-x 1 vumma vumma 16224 Aug 31 15:34 016.out
        -rw-rw-r-- 1 vumma vumma  2705 Aug 31 12:05 018.c
        -rwxrwxr-x 1 vumma vumma 16464 Aug 31 12:05 018.out
        -rw-rw-r-- 1 vumma vumma   696 Aug 31 16:09 018record.c
        -rwxrwxr-x 1 vumma vumma 16056 Aug 31 16:13 0.18record.out
        -rw-rw-r-- 1 vumma vumma  1152 Sep  1 14:20 019.c
        -rwxrwxr-x 1 vumma vumma 16104 Sep  1 14:19 019.out
        -rwxrwxr-x 1 vumma vumma 17800 Aug 28 14:42 020
        -rw-rw-r-- 1 vumma vumma  1199 Aug 28 14:53 020.c
        -rwxrwxr-x 1 vumma vumma 16096 Aug 28 14:51 020.out
        -rw-rw-r-- 1 vumma vumma  1038 Sep  1 14:26 021.c
        -rwxrwxr-x 1 vumma vumma 16128 Sep  1 14:26 021.out
        -rw-rw-r-- 1 vumma vumma  1417 Sep  1 14:46 022.c
        -rwxrwxr-x 1 vumma vumma 16208 Sep  1 14:45 022.out
        -rw-rw-r-- 1 vumma vumma  1498 Sep  5 14:01 023.c
        -rwxrwxr-x 1 vumma vumma 16216 Sep  5 13:11 023.out
        -rwxrwxr-x 1 vumma vumma 17768 Aug 28 14:50 024
        -rw-rw-r-- 1 vumma vumma  1255 Sep  4 04:47 024.c
        -rwxrwxr-x 1 vumma vumma 16168 Sep  4 05:18 024.out
        -rw-rw-r-- 1 vumma vumma  1488 Sep  5 14:26 025.c
        -rwxrwxr-x 1 vumma vumma 16216 Sep  5 14:25 025.out
        -rw-rw-r-- 1 vumma vumma   956 Sep  5 14:27 026.c
        -rwxrwxr-x 1 vumma vumma 15960 Sep  5 14:27 026.out
        -rw-rw-r-- 1 vumma vumma  1686 Sep  5 15:38 027.c
        -rwxrwxr-x 1 vumma vumma 16304 Sep  5 15:38 027.out
        -rwxrwxr-x 1 vumma vumma 16056 Aug 31 16:07 a.out
        prw-rw-r-- 1 vumma vumma     0 Aug 22 23:14 FIFO
        -rw-r--r-- 1 vumma vumma    20 Aug 25 19:59 file1.txt
        -rw-rw-r-- 1 vumma vumma    60 Aug 25 21:47 file7.txt
        -rw-rw-rw- 1 vumma vumma    43 Sep  1 14:45 fork
        -rwxr-xr-x 5 vumma vumma  1537 Aug 22 23:18 hard
        -rwxr-xr-x 5 vumma vumma  1537 Aug 22 23:18 Hlink.txt
        prw-rw-r-- 1 vumma vumma     0 Aug 22 23:14 my_fifo
        -rw-rw-r-- 1 vumma vumma    48 Aug 25 22:17 newFile2.txt
        -rw-rw-r-- 1 vumma vumma   155 Aug 25 22:15 newFile.txt
        -rw-rw-r-- 1 vumma vumma   506 Aug 31 11:01 readrecords.c
        -rwxrwxr-x 1 vumma vumma 16248 Aug 31 11:01 readrecords.out
        -rw-rw-rw- 1 vumma vumma    32 Aug 31 12:05 record.txt
        lrwxrwxrwx 1 vumma vumma     7 Aug 22 23:14 Slink -> 001.txt
        lrwxrwxrwx 1 vumma vumma     4 Aug 22 23:14 soft -> hard


        ls -Rl from execvp

        vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ .:
        total 692
        -rwxr-xr-x 5 vumma vumma  1537 Aug 22 23:18 001.c
        -rwxrwxr-x 1 vumma vumma 16112 Aug 22 23:14 001.out
        -rw-rw-r-- 1 vumma vumma  1658 Aug 22 23:20 002.c
        -rwxrwxr-x 1 vumma vumma 16168 Aug 22 23:18 002.out
        -rw-rw-r-- 1 vumma vumma  1078 Aug 22 23:23 003.c
        -rwxrwxr-x 1 vumma vumma 16000 Aug 22 23:21 003.out
        -rw-rw-r-- 1 vumma vumma  1170 Aug 22 23:33 004.c
        -rwxrwxr-x 1 vumma vumma 16000 Aug 22 23:23 004.out
        -rw-rw-r-- 1 vumma vumma    60 Aug 22 23:30 004.txt
        -rw-rw-r-- 1 vumma vumma  1781 Aug 25 20:01 005.c
        -rwxrwxr-x 1 vumma vumma 16136 Aug 23 00:16 005.out
        -rw-rw-r-- 1 vumma vumma  1083 Aug 22 23:26 006.c
        -rwxrwxr-x 1 vumma vumma 16048 Aug 22 23:25 006.out
        -rw-rw-r-- 1 vumma vumma  1112 Aug 22 23:32 007.c
        -rwxrwxr-x 1 vumma vumma 15960 Aug 22 23:30 007.oclear
        -rwxrwxr-x 1 vumma vumma 15960 Aug 22 23:27 007.out
        -rw-rw-r-- 1 vumma vumma  1536 Aug 22 22:58 008.c
        -rwxrwxr-x 1 vumma vumma 16176 Aug 25 20:09 008.out
        -rw-rw-r-- 1 vumma vumma  2174 Aug 26 10:06 009.c
        -rwxrwxr-x 1 vumma vumma 16176 Aug 25 20:41 009.out
        -rwxrwxr-x 1 vumma vumma 16176 Aug 25 21:52 010.0ut
        -rw-rw-r-- 1 vumma vumma  1735 Aug 26 10:06 010.c
        -rw-rw-r-- 1 vumma vumma  1506 Aug 26 10:06 011.c
        -rwxrwxr-x 1 vumma vumma 16128 Aug 25 22:17 011.out
        -rw-rw-r-- 1 vumma vumma  1326 Aug 26 10:06 012.c
        -rwxrwxr-x 1 vumma vumma 16088 Aug 25 22:41 012.out
        -rw-rw-r-- 1 vumma vumma  1912 Aug 26 10:06 013.c
        -rwxrwxr-x 1 vumma vumma 16176 Aug 26 09:16 013.out
        -rw-rw-r-- 1 vumma vumma  1758 Aug 26 10:05 014.c
        -rwxrwxr-x 1 vumma vumma 16136 Aug 26 09:53 014.out
        -rwxrwxr-x 1 vumma vumma 17592 Aug 28 15:20 015
        -rw-rw-r-- 1 vumma vumma  1018 Aug 31 12:05 015.c
        -rwxrwxr-x 1 vumma vumma 16072 Aug 28 15:21 015.out
        -rw-rw-r-- 1 vumma vumma  2188 Aug 31 12:05 016.c
        -rwxrwxr-x 1 vumma vumma 16224 Aug 31 15:34 016.out
        -rw-rw-r-- 1 vumma vumma  2705 Aug 31 12:05 018.c
        -rwxrwxr-x 1 vumma vumma 16464 Aug 31 12:05 018.out
        -rw-rw-r-- 1 vumma vumma   696 Aug 31 16:09 018record.c
        -rwxrwxr-x 1 vumma vumma 16056 Aug 31 16:13 0.18record.out
        -rw-rw-r-- 1 vumma vumma  1152 Sep  1 14:20 019.c
        -rwxrwxr-x 1 vumma vumma 16104 Sep  1 14:19 019.out
        -rwxrwxr-x 1 vumma vumma 17800 Aug 28 14:42 020
        -rw-rw-r-- 1 vumma vumma  1199 Aug 28 14:53 020.c
        -rwxrwxr-x 1 vumma vumma 16096 Aug 28 14:51 020.out
        -rw-rw-r-- 1 vumma vumma  1038 Sep  1 14:26 021.c
        -rwxrwxr-x 1 vumma vumma 16128 Sep  1 14:26 021.out
        -rw-rw-r-- 1 vumma vumma  1417 Sep  1 14:46 022.c
        -rwxrwxr-x 1 vumma vumma 16208 Sep  1 14:45 022.out
        -rw-rw-r-- 1 vumma vumma  1498 Sep  5 14:01 023.c
        -rwxrwxr-x 1 vumma vumma 16216 Sep  5 13:11 023.out
        -rwxrwxr-x 1 vumma vumma 17768 Aug 28 14:50 024
        -rw-rw-r-- 1 vumma vumma  1255 Sep  4 04:47 024.c
        -rwxrwxr-x 1 vumma vumma 16168 Sep  4 05:18 024.out
        -rw-rw-r-- 1 vumma vumma  1488 Sep  5 14:26 025.c
        -rwxrwxr-x 1 vumma vumma 16216 Sep  5 14:25 025.out
        -rw-rw-r-- 1 vumma vumma   956 Sep  5 14:27 026.c
        -rwxrwxr-x 1 vumma vumma 15960 Sep  5 14:27 026.out
        -rw-rw-r-- 1 vumma vumma  1686 Sep  5 15:38 027.c
        -rwxrwxr-x 1 vumma vumma 16304 Sep  5 15:38 027.out
        -rwxrwxr-x 1 vumma vumma 16056 Aug 31 16:07 a.out
        prw-rw-r-- 1 vumma vumma     0 Aug 22 23:14 FIFO
        -rw-r--r-- 1 vumma vumma    20 Aug 25 19:59 file1.txt
        -rw-rw-r-- 1 vumma vumma    60 Aug 25 21:47 file7.txt
        -rw-rw-rw- 1 vumma vumma    43 Sep  1 14:45 fork
        -rwxr-xr-x 5 vumma vumma  1537 Aug 22 23:18 hard
        -rwxr-xr-x 5 vumma vumma  1537 Aug 22 23:18 Hlink.txt
        prw-rw-r-- 1 vumma vumma     0 Aug 22 23:14 my_fifo
        -rw-rw-r-- 1 vumma vumma    48 Aug 25 22:17 newFile2.txt
        -rw-rw-r-- 1 vumma vumma   155 Aug 25 22:15 newFile.txt
        -rw-rw-r-- 1 vumma vumma   506 Aug 31 11:01 readrecords.c
        -rwxrwxr-x 1 vumma vumma 16248 Aug 31 11:01 readrecords.out
        -rw-rw-rw- 1 vumma vumma    32 Aug 31 12:05 record.txt
        lrwxrwxrwx 1 vumma vumma     7 Aug 22 23:14 Slink -> 001.txt
        lrwxrwxrwx 1 vumma vumma     4 Aug 22 23:14 soft -> hard


*/