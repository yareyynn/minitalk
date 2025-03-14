/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakarya  <ysakarya@student.42istanb>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:57:21 by ysakarya          #+#    #+#             */
/*   Updated: 2024/11/14 19:57:21 by ysakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (dstsize <= dst_len || dstsize == 0)
		return (dstsize + src_len);
	dst += dst_len;
	while (dstsize-- - dst_len > 1 && *src)
		*dst++ = *src++;
	*dst = '\0';
	return (dst_len + src_len);
}
