#include "libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char	*ft_get_fd_contents(int fd, const char *read_error_msg)
{
	char	buffer[32];
	char	*tmp;
	char	*file_contents;
	ssize_t	bytes_read;

	bytes_read = 1;
	file_contents = ft_strdup("");
	while (1)
	{
		bytes_read = read(fd, buffer, 32);
		if (bytes_read == 0)
			break ;
		if (bytes_read < 0)
		{
			free(file_contents);
			ft_print_error(read_error_msg);
			return (NULL);
		}
		tmp = file_contents;
		file_contents = ft_str_merge_buffer(file_contents, buffer, bytes_read);
		free(tmp);
	}
	return (file_contents);
}
