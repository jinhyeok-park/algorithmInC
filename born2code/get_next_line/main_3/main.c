#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>
int main(void)
{
    int fd = open("test.txt", O_RDONLY);

    char *str;
    str = get_next_line(fd);
    printf("%s", str);
    str = get_next_line(fd);
    printf("%s", str);
    str = get_next_line(fd);
    printf("%s", str);
    str = get_next_line(fd);
    printf("%s", str);
    str = get_next_line(fd);
    printf("%s", str);
    str = get_next_line(fd);
    printf("%s", str);
    str = get_next_line(fd);
    printf("%s", str);

}