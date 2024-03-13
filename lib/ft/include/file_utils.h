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

/**
 * FT_IO_FILE object type capable of recording all the information needed to
 * control a stream, including its file position indicator, a pointer to its
 * associated buffer (if any), an error indicator that records whether a
 * read/write error has occurred, and an end-of-file indicator that records
 * whether the end of the file has been reached;
 */
typedef struct s_ft_io_file {
	int				_r;
	int				_w;
	int				_offset;
	void			*_cookie;
	int				(*_close)(void*);
	int				(*_read)(void*, char*, int);
	int				(*_write)(void*, const char*, int);
	unsigned char	*ptr;
	short			_flags;
	short			_file;
	struct {
		unsigned char	*base;
		int				size;
	}	s_buf;
	struct {
		unsigned char	*base;
		int				size;
	}	s_line_buf;
}	t_ft_file;

typedef struct s_string_glue {
	char						*data;
	struct s_string_glue		*next;
}	t_string_list_node;

typedef struct s_pointers
{
	char			*s;
	unsigned char	*p;
	unsigned char	*t;
}						t_pointers;

int					check_safety_flags(const char *mode, int *optr);
t_ft_file			*ft_prep_fp(void);
int					ft_refill(t_ft_file *fp);
int					ft_fread(void *cookie, char *buf, int n);
t_ft_file			*ft_fopen(const char *filename, const char *mode);
int					ft_fclose(t_ft_file *fp);
int					ft_fdopen(const char *filename, const char *mode);
t_string_list_node	*ft_read_line_by_line(t_ft_file *fp);
t_string_list_node	*read_line(char buf[MAXC], t_ft_file *fp);
char				*ft_fget_string(char *buf, int n, t_ft_file *fp);
void				add_node_to_list(t_string_list_node **head,
						t_string_list_node **tail, t_string_list_node *node);
#endif //FILE_UTILS_H