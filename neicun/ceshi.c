/*************************************************************************
	> File Name: ceshi.c
	> Author: 
	> Mail: 
	> Created Time: 2015年12月08日 星期二 12时42分54秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<sys/mman.h>
#include<sys/types.h>
#include<fcntl.h>
#include<stdlib.h>
#define LEN (10*4096)

int main()
{
    int fd;
    char *vadr;

    if((fd = open("txt",O_RDWR)) < 0)  {
        perror("open");
        exit(-1);
    }
    vadr = mmap(0, LEN, PROT_READ, MAP_PRIVATE|MAP_NORESERVE, fd, 0);
    if (vadr == MAP_FAILED) {
        perror("mmap");
        exit(-1);
    }
    printf("%s\n", vadr);
    close(fd);
    exit(0);
}
