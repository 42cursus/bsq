/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:34:27 by abelov            #+#    #+#             */
/*   Updated: 2023/10/25 15:34:30 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_UTILS_H
# define FILE_UTILS_H
# include "bsq_def.h"
# include "string_utils.h"
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# define MAXC 256
# define NOT_SAFE	0x0000
# define SAFE_TO_READ	0x0004
# define SAFE_TO_WRITE	0x0008
/* RD and WR are never simultaneously asserted */
# define SAFE_TO_READ_AND_WRITE	0x0010
# define FOUND_EOF	0x0020		/* found EOF */
# define FOUND_ERR	0x0040		/* found error */
# define MALLOC_BUF	0x0080		/* _buf is from malloc */
# define OFFSET_IS_CORRECT	0x1000		/* set iff _offset is in fact correct */

int					check_safety_flags(const char *mode, int *optr);
t_ft_file			*ft_prep_fp(void);
int					ft_refill(t_ft_file *fp);
int					ft_fread(void *cookie, char *buf, int n);
t_ft_file			*ft_fopen(const char *filename, const char *mode);
int					ft_fclose(t_ft_file *fp);
int					ft_fdopen(const char *filename, const char *mode);
t_string_list_node	*ft_read_line_by_line(t_ft_file *fp);
t_string_list_node	*read_line(char buf[MAXC], t_ft_file *fp);
void				add_node_to_list(t_string_list_node **head,
						t_string_list_node **tail, t_string_list_node *node);
#endif //FILE_UTILS_H