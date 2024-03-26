#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*res = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (res == 0)
		return (0);

	i = 0;
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		res[ft_strlen(s1) + i] = s2[i];
		i++;
	}
	res[ft_strlen(s1) + i] = '\0';
	return (res);
}

int	main(void)
{
	char	*s1 = "hola";
	char	*s2 = "mundo";
	char	*res = ft_strjoin(s1, s2);
	printf("%s\n", res);
}
