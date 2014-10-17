/*
 * =====================================================================================
 *
 *       Filename:  fcntl.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/26/14 15:42:39
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */
#include <fcntl.h>   
#include <unistd.h>   
#include <sys/types.h>   
#include <sys/stat.h>   
#include <stdio.h>   
#include <string.h>   
 
#define STDIN 0   
int main()   
{   
    int mode, fd, value;   
    char buf[255];   

    memset(buf, 0x00, 255);   

    // ó�� �Է��� �������   
    read (STDIN, buf, 255);   
    printf("-> %s\n", buf);   
    memset(buf, 0x00, 255);   

    // NONBLOCKING ���� �����Ѵ�.   
    value = fcntl(STDIN, F_GETFL, 0);   
    value |= O_NONBLOCK;   
    fcntl(STDIN, F_SETFL, value);   
    printf("NON BLOCKING MODE �� ���� \n");   

    // 2���� ����� ���� ����.   
    sleep(2);   

    // �ٻ۴��(busy wait) ����   
//    while(1)   
 //   {   
        read (STDIN, buf, 255);   
        printf("-> %s\n", buf);   
  //  }   
        return 0;
}  
