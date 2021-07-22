#include "libft.h"
#include <stdlib.h>

void	ft_magic_free(char *s1, char *s2, char **tab1, char **tab2)
{
	if (s1 != NULL)
		free(s1);
	if (s2 != NULL)
		free(s2);
	if (tab1 != NULL)
		ft_free_tab(tab1);
	if (tab2 != NULL)
		ft_free_tab(tab2);
}
