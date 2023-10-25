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

t_string_list_node	*ft_read_line_by_line(t_ft_file *fp)
{
	char				buf[MAXC];
	t_string_list_node	*head;
	t_string_list_node	*tail;
	t_string_list_node	*node;

	head = NULL;
	tail = NULL;
	node = read_line(buf, fp);
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
