#include "get_next_line.h"
#include <stdio.h>

int        main(void)
{
	int fd = open("gnl7_3.txt", O_RDONLY);
	char    *line = NULL;
	int 	ret;
	ret = 0;
	printf("test 1 du main, fd est %d\n", fd);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("test 2 du main\n");
		printf("%s\n", line);
	}
	printf("test 3 du main\n");
	close(fd);
	printf("test 4 du main\n");
	return (0);
}
