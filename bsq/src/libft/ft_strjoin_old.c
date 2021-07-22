#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

char	*ft_strjoin_old(const char *s1, const char *s2)
{
	size_t	total_size;
	char	*str_new;

	total_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	str_new = malloc(sizeof(char *) * total_size);
	if (str_new && s1 && s2)
	{
		if (*s1 == '\0' && *s2 == '\0')
		{
			*str_new = '\0';
			return (str_new);
		}
		ft_strcpy(str_new, (char *)s1);
		ft_strlcat(str_new, (char *)s2, total_size);
		return (str_new);
	}
	else
		return (NULL);
}
