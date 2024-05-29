/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclopez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:35:27 by niclopez          #+#    #+#             */
/*   Updated: 2024/02/21 22:08:42 by niclopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[j] != '\0')
	{
		if (i == 0 && (str[j] >= 97 && str[j] <= 122))
		{
			str[j] -= 32;
			i++;
		}
		else if (i > 0 && (str[j] >= 65 && str[j] <= 90))
		{
			str[j] += 32;
		}
		else if (str[j] < 48 || (str[j] > 57 && str[j] < 65)
        || (str[j] > 91 && str[j] < 97) || str[j] > 122)
			i = 0;
		else
			i++;
		j++;
	}
	return (str);
}
/*int main()
{
    char x[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
    char *r;
    r = ft_strcapitalize(x);
    printf("%s", r);
}*/
