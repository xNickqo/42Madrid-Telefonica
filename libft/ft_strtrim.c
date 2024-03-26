#include "libft.h"
#include <stdio.h>
#include <>

/*La funcion elimina todos los caracteres de la string "set"
 * desde el principio y desde el final de "s1", hasta encontrar
 * un caracter no perteneciente a "set". La string resultante
 * se devuelve con una reserva de malloc() */

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*trim;

	if (!s1 || !set)
		return (0);

	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;

	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;

	trim = malloc(end - start + 1);
	ft_memcpy(trim, s1 + start, end - start);
	trim[end - start] = '\0';

	return (trim);
}
