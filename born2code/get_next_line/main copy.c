#include "get_next_line.h"
#include <string.h>
int main(void)
{
    char buf[8];
    char    *test;
    int fd = open("test.txt", O_RDONLY);
    int fd1 = open("test1.txt", O_RDONLY);
    test = get_next_line(fd);
    printf("%s\n", test);
    // test = get_next_line(fd);
    // printf("%s\n", test);
    // test = get_next_line(fd);
    // printf("%s\n", test);
    // test = get_next_line(fd);
    // printf("%s\n", test);
    test = get_next_line(fd1);
    printf("%s\n", test);
    test = get_next_line(fd1);
    printf("%s\n", test);

    close(fd);
    return (0);
}