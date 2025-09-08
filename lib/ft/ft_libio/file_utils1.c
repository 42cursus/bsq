/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:35:43 by abelov            #+#    #+#             */
/*   Updated: 2023/10/25 15:35:45 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_utils.h"

static inline int	ft_check_first_flag(const char *mode, int *m, int *o)
{
	int	ret;

	if (*mode == 'r')
	{
		ret = SAFE_TO_READ;
		(*m) = O_RDONLY;
		(*o) = 0;
	}
	else if (*mode == 'w')
	{
		ret = SAFE_TO_WRITE;
		(*m) = O_WRONLY;
		(*o) = O_CREAT | O_TRUNC;
	}
	else if (*mode == 'a')
	{
		ret = SAFE_TO_WRITE;
		(*m) = O_WRONLY;
		(*o) = O_CREAT | O_APPEND;
	}
	else
		ret = NOT_SAFE;
	return (ret);
}

static void	ft_check_second_flag(const char *mode, int *ret, int *m, int *o)
{
	while (*mode != '\0')
	{
		if (*mode == 'b')
			;
		else if (*mode == '+')
		{
			(*ret) = SAFE_TO_READ_AND_WRITE;
			(*m) = O_RDWR;
		}
		else if (*mode == 'e')
			(*o) |= O_CLOEXEC;
		else if (*mode == 'x')
		{
			if ((*o) & O_CREAT)
				(*o) |= O_EXCL;
		}
		else
		{
			(*ret) = 0;
			break ;
		}
		mode++;
	}
}

/**
 * Return the (stdio) flags for a given mode.  Store the flags
 * to be passed to an open() syscall through *optr.
 * Return 0 on error.
 */
int	check_safety_flags(const char *mode, int *optr)
{
	int	m;
	int	o;
	int	ret;

	ret = ft_check_first_flag(mode, &m, &o);
	if (ret == NOT_SAFE)
		return (NOT_SAFE);
	ft_check_second_flag(++mode, &ret, &m, &o);
	*optr = m | o;
	return (ret);
}

/**
 * Prepare an FT_FILE for ft_fopen()
 */
t_ft_file	*ft_prep_fp(void)
{
	t_ft_file	*fp;

	fp = malloc(sizeof(t_ft_file));
	*fp = (t_ft_file){0};
	fp->_flags |= MALLOC_BUF;
	fp->_file = -1;
	return (fp);
}

int	ft_fread(void *cookie, char *buf, int n)
{
	int			ret;
	t_ft_file	*fp;

	fp = cookie;
	ret = read(fp->_file, buf, n);
	if (ret >= 0)
		fp->_offset += ret;
	else
		fp->_flags &= ~OFFSET_IS_CORRECT;
	return (ret);
}
