/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utilities_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raida <raida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 12:33:53 by raida             #+#    #+#             */
/*   Updated: 2021/07/08 22:31:42 by raida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

static size_t	ft_size(long long n)
{
	size_t	size;

	size = 0;
	if (n == 0)
		size++;
	if (n < 0)
	{
		size++;
		n *= -1;
	}
	while (n > 0)
	{
		size++;
		n = n / 10;
	}
	return (size);
}

char	*ft_itoa(unsigned int n)
{
	char			*result;
	size_t			size;
	unsigned int	num;

	num = n;
	size = ft_size(num);
	result = (char *)malloc(sizeof(char) * (size + 1));
	if (!result)
		return (NULL);
	result[size--] = '\0';
	if (num == 0)
		result[0] = '0';
	if (num < 0)
	{
		result[0] = '-';
		num *= -1;
	}
	while (num > 0)
	{
		result[size--] = (num % 10) + '0';
		num = num / 10;
	}
	return (result);
}
