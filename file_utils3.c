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

void	*free_and_return(t_string_list_node *node)
{
	free(node);
	return (NULL);
}

char	*get_string(char *buf, t_ft_file *fp, size_t len, char *s,
					const unsigned char *p, unsigned char *t)
{
	len = ++t - p;
	fp->_r -= len;
	fp->ptr = t;
	(void)ft_strncpy((void *)s, (void *)p, len);
	s[len] = '\0';
	return (buf);
}

/*
* Read at most n-1 characters from the given file.
* Stop when a newline has been read, or the count runs out.
* Return first argument, or NULL if no characters were read.
* Do not return NULL if n == 1.
*/
char	*ft_fget_string(char *buf, int n, t_ft_file *fp)
{
	size_t			len;
	char			*s;
	unsigned char	*p;
	unsigned char	*t;

	if (n <= 0)
		return (NULL);
	s = buf;
	n--;
	while (n != 0)
	{
		if (fp->_r <= 0)
		{
			if (ft_refill(fp))
			{
				if (s == buf)
					return (NULL);
				break ;
			}
		}
		len = fp->_r;
		p = fp->ptr;
		if ((int)len > n)
			len = n;
		t = ft_memchr((void *)p, '\n', len);
		if (t != NULL)
			return (get_string(buf, fp, len, s, p, t));
		fp->_r -= len;
		fp->ptr += len;
		(void)ft_strncpy((void *)s, (void *)p, len);
		s += len;
		n -= len;
	}
	*s = '\0';
	return (buf);
}

t_string_list_node	*read_line(char buf[MAXC], t_ft_file *fp)
{
	size_t				len;
	t_string_list_node	*node;

	len = 0;
	node = (t_string_list_node *)malloc(sizeof(t_string_list_node));
	if (!node)
		return (NULL);
	if (ft_fget_string(buf, MAXC, fp))
	{
		len = ft_strcspn(buf, "\n");
		buf[len] = 0;
		node->data = (char *)malloc(len + 1);
		if (!node->data)
			return (free_and_return(node));
		node->data = ft_strncpy(node->data, buf, len + 1);
		node->next = (NULL);
	}
	else
		return (free_and_return(node));
	return (node);
}

void	add_node_to_list(t_string_list_node **head, t_string_list_node **tail,
	t_string_list_node *node)
{
	if (!(*head))
	{
		(*head) = node;
		(*tail) = node;
	}
	else
	{
		(*tail)->next = node;
		(*tail) = node;
	}
}
