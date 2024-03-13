/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 20:53:19 by abelov            #+#    #+#             */
/*   Updated: 2023/10/25 20:53:21 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_utils.h"

static inline void	*free_and_return(t_string_list_node *node)
{
	free(node);
	return (NULL);
}

t_string_list_node	*ft_read_line_by_line(t_ft_file *fp)
{
	char				buf[MAXC];
	t_string_list_node	*head;
	t_string_list_node	*tail;
	t_string_list_node	*node;

	head = NULL;
	tail = NULL;
	node = read_line(buf, fp);
	if (node)
		add_node_to_list(&head, &tail, node);
	while (node)
	{
		node = read_line(buf, fp);
		add_node_to_list(&head, &tail, node);
	}
	return (head);
}

int	ft_fclose(t_ft_file *fp)
{
	int	r;

	if (fp->_flags == 0)
		return (EOF);
	r = 0;
	if (fp->_close != NULL && (*fp->_close)(fp->_cookie) < 0)
		r = EOF;
	if (fp->_flags & MALLOC_BUF)
		free((char *)fp->s_buf.base);
	fp->_r = 0;
	fp->_w = 0;
	fp->_flags = 0;
	return (r);
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
