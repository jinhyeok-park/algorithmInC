#include <fcntl.h>
#include "get_next_line.h"
void test(void);
void test1(int *a, t_string *list);
// int main(void)
// {
// //    char *buff;
// //     int fd = open("test.txt", O_RDONLY);
// //     //char *str = "helloawefawefawefawefawef awe awe fawef\n world \n this is \n test";

// char buff[6];
// int fd = open("test.txt", O_RDONLY);
// char *str = "helloawefawefawefawefawef awe awe fawef\n world \n this is \n test";

// read(fd, buff, 5);
// buff[5] = '\0'; // Null-terminate the string
// printf("%s\n", buff);
// read(fd, buff, 5);
// buff[5] = '\0'; // Null-terminate the string
// printf("%s\n", buff);
// close(fd);
// }
int main(void)
{
    test();

}
void test(void)
{
    static int a;
    static t_string list;
    test1(&a, &list);
    printf("%d" , a);
    printf("%d", list.fd);
}
void test1(int *a , t_string *list)
{
    *a = 1;
    list->fd = 3;
}
