#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
    int fd = open("test.txt", O_RDWR);
    char *str = get_next_line(fd);
    printf("%s" , str);
    char *str1 = get_next_line(fd);
    printf("%s" , str1);
    	// char *temp;
		// 	do {
		// 		temp = get_next_line(fd);
		// 		free(temp);
		// 	} while (temp != NULL);
    // str1 = get_next_line(fd);
    // printf("%s" , str1);
    close(fd);
    fd = open("test.txt", O_RDWR);
    char *str3 = get_next_line(fd);
    printf("%s" , str3);
    str3 = get_next_line(fd);
    printf("%s" , str3);
    str3 = get_next_line(fd);
    printf("%s" , str3);
    str3 = get_next_line(fd);
    printf("%s" , str3);
}