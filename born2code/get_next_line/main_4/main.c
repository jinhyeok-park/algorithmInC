#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>
int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    int fd1 = open("test1.txt", O_RDONLY);
    int fd2 = open("test2.txt", O_RDONLY);

    char *str;
    str = get_next_line(fd);
    printf("%s", str);
    str = get_next_line(fd1);
    printf("%s", str);
    str = get_next_line(fd2);
    printf("%s", str);
    str = get_next_line(fd);
    printf("%s", str);
    str = get_next_line(fd);
    printf("%s", str);
    // str = get_next_line(fd);
    // printf("%s", str);
    // str = get_next_line(fd);
    // printf("%s", str);

}