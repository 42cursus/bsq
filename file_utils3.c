/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:38:33 by abelov            #+#    #+#             */
/*   Updated: 2023/10/25 16:38:35 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_utils.h"

static inline unsigned char	*foo(int n, t_ft_file *fp, size_t *len,
									unsigned char **p)
{
	(*len) = fp->_r;
	(*p) = fp->ptr;
	if ((int)(*len) > n)
		(*len) = n;
	return (ft_memchr((void *)(*p), '\n', (*len)));
}

char	*get_string(char *buf, t_ft_file *fp, size_t len, t_pointers pointers)
{
	len = ++pointers.t - pointers.p;
	fp->_r -= len;
	fp->ptr = pointers.t;
	(void)ft_strncpy((void *)pointers.s, (void *)pointers.p, len);
	pointers.s[len] = '\0';
	return (buf);
}

/*
* Read at most n-1 characters from the given file.
* Stop when a newline has been read, or the count runs out.
* Return first argument, or NULL if no characters were read.
* Do not return NULL if n == 1.
*/
char	*ft_fget_string_check(char *buf, int n, t_ft_file *fp)
{
	size_t		len;
	t_pointers	pointers;

	pointers.s = buf;
	n--;
	while (n != 0)
	{
		if ((fp->_r) <= 0 && (ft_refill(fp)))
			if (pointers.s == buf)
				return (NULL);
		if ((fp->_r) <= 0 && (ft_refill(fp)))
			break ;
		pointers.t = foo(n, fp, &len, &pointers.p);
		if (pointers.t != NULL)
			return (get_string(buf, fp, len, pointers));
		fp->_r -= len;
		fp->ptr += len;
		(void)ft_strncpy((void *)pointers.s, (void *)pointers.p, len);
		pointers.s += len;
		n -= len;
	}
	*pointers.s = '\0';
	return (buf);
}

char	*ft_fget_string(char *buf, int n, t_ft_file *fp)
{
	if (n <= 0)
		return (NULL);
	return (ft_fget_string_check(buf, n, fp));
}
