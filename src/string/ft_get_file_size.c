#include "libft.h"

ssize_t	ft_get_file_size(const char *path)
{
	struct stat st;

	if (stat(path, &st) == 0)
		return (st.st_size);
	else
		return -1;
}
