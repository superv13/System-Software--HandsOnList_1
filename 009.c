/*
..........................................................................................................................................
Name : 009.c
Author : SHRUTI VERMA
Description : Write a program to print the following information about a given file.
                a. inode
                b. number of hard links
                c. uid
                d. gid
                e. size
                f. block size
                g. number of blocks
                h. time of last access
                i. time of last modification
                j. time of last change
Date : 25 Aug 2025
..........................................................................................................................................
*/


#include<unistd.h>
#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>

int main() {
    struct stat fileStat;
    int fd;
    fd = open("file7.txt", O_RDONLY , 0444);

    if(stat("file7.txt", &fileStat)==-1)
    {
        perror("stat");
        return 1;
    }

    printf("inode of the file : %ld\n",(long)fileStat.st_ino);
    printf("no. of hardlinks  : %ld\n",fileStat.st_nlink);
    
    printf("uid : %d\n", fileStat.st_uid);
    printf("gid: %d\n",fileStat.st_gid);
    
    printf("total size : %ld\n",(long)fileStat.st_size);
    printf("block size: %ld\n",(long)fileStat.st_blksize);
    
    printf("number of blocks : %ld\n",(long)fileStat.st_blocks);
    printf("time of last access : %ld\n",fileStat.st_atime);
    
    printf("time of last modification: %ld\n",fileStat.st_mtime);
    printf("time of last change: %ld\n",fileStat.st_ctime);

    close(fd);

}

/*
------------------------------------------OUTPUT--------------------------------------------------------------
    vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ gcc 009.c -o 009.out
    vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/HOL1$ ./009.out
    inode of the file : 2386825
    no. of hardlinks  : 1
    uid : 1000
    gid: 1000
    total size : 60
    block size: 4096
    number of blocks : 8
    time of last access : 1755885677
    time of last modification: 1755885639
    time of last change: 1755885639
*/