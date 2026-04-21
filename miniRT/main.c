#include "miniRT.h"

void	parsing(miniRT *miniRT)
{
	int		fd;
	char	*line;

	fd = open(miniRT->path, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (1)
	{
		line = get_next_line(fd);
		
	}
}

int main(int argc, char **argv)
{
	miniRT	miniRT;

	ft_bzero(&miniRT, sizeof(miniRT));
	miniRT.path = argv[1];
	parsing(&miniRT);
	return (0);
}