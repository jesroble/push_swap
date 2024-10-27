/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesroble <jesroble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:03:43 by jesroble          #+#    #+#             */
/*   Updated: 2024/01/23 11:33:40 by jesroble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*i;
	int		n;

	i = NULL;
	n = 0;
	while (s[n])
	{
		if (s[n] == (char) c)
			i = (char *) &s[n];
		n++;
	}
	if ((char) c == '\0')
		return ((char *) &s[n]);
	return (i);
}

int	main(void)
{
	char s[] = "fakin bukpies";
	int c = 'k';

	printf("%s\n", ft_strrchr(s, c));
	printf("%s", strrchr(s, c));
}