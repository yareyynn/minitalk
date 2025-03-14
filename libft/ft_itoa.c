/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakarya  <ysakarya@student.42istanb>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:57:21 by ysakarya          #+#    #+#             */
/*   Updated: 2024/11/14 19:57:21 by ysakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_digits(int n)
{
	int	digits;

	digits = 1;
	if (n < 0)
		digits++;
	while (n / 10)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

static void	ft_recursive_itoa(char *str, int n, int len)
{
	if (n / 10)
		ft_recursive_itoa(str, n / 10, len - 1);
	str[len] = n % 10 + '0';
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_digits(n);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	ft_recursive_itoa(str, n, len - 1);
	str[len] = '\0';
	return (str);
}
