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
# define MAXC 80
# define NOT_SAFE	0x0000
# define SAFE_TO_READ	0x0004
# define SAFE_TO_WRITE	0x0008
/* RD and WR are never simultaneously asserted */
# define SAFE_TO_READ_AND_WRITE	0x0010
# define FOUND_EOF	0x0020		/* found EOF */
# define FOUND_ERR	0x0040		/* found error */
# define MALLOC_BUF	0x0080		/* _buf is from malloc */
# define OFFSET_IS_CORRECT	0x1000		/* set iff _offset is in fact correct */
/* Macros for common mode bit masks.  */
# define ACCESSPERMS (S_IRWXU|S_IRWXG|S_IRWXO) /* 0777 */
# define ALLPERMS (S_ISUID|S_ISGID|S_ISVTX|S_IRWXU|S_IRWXG|S_IRWXO)/* 07777 */
# define DEFFILEMODE (S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)/* 0666*/

int			check_safety_flags(const char *mode, int *optr);
t_ft_file	*ft_prep_fp(void);
int			ft_refill(t_ft_file *fp);
int			ft_fread(void *cookie, char *buf, int n);
int			ft_fdopen(const char *filename, const char *mode);
#endif //FILE_UTILS_H