#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#ifndef BUFFER_SZIE
# define BUFFER_SIZE 8
#endif

char	*get_next_line(int fd)
{
	char	*start;
	char	*point;

	start = malloc(10000);
	point = start;
	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, NULL, 0) == -1) 
		return (NULL);
	while (read(fd, point, 1) > 0)
	{
		if (*point == '\n')
			break;
		point++;
	}
	if (point > start || *point == '\n')
	{
		if (point == start && *point == '\n')
			point++;
		*point = 0;
		return (start);
	}
	free(start);
	return (NULL);
}

#include <stdio.h>
int main(void)
{
	int	fd = open("test.txt" , O_RDONLY);
	char	*str;

	str = get_next_line(fd);
	printf("%s" , str);
	while (str)
	{
		str = get_next_line(fd);
		printf("%s" , str);
	}
	close(fd);
}
