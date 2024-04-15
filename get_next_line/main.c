#include "get_next_line.h"
/*
int	main(void)
{
	int i = 0;
	int	fd = open("input/42_no_nl", O_RDWR);
	if (fd == -1)
	{
		printf("fd == -1\n");
		return (0);
	}
	char *str;
	while (i < 13)
	{
		str = get_next_line(fd);
		printf("call [%d] to get_next_line:",i);
		printf("%s",str);
		printf("======NEW LINE======\n");
		free(str);
		i++;
	}
	return (0);
}
*/
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int	fd;
	char	*line;

	fd = open("files/multiple_nlx5", O_RDONLY);
	//fd = open("test.txt", O_RDONLY);
	
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return 0;

}
