/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakarya  <ysakarya@student.42istanb>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:57:21 by ysakarya          #+#    #+#             */
/*   Updated: 2024/11/14 19:57:21 by ysakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*tmp;

	tmp = dst;
	if (dst < src && len != 0)
	{
		while (len--)
			*(char *)dst++ = *(char *)src++;
	}
	else if (dst > src && len != 0)
	{
		dst += len;
		src += len;
		while (len--)
			*(char *)--dst = *(char *)--src;
	}
	return (tmp);
}
