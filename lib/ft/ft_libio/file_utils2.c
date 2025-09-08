/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:31:22 by abelov            #+#    #+#             */
/*   Updated: 2023/10/25 16:31:25 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_utils.h"

int	ft_fdopen(const char *filename, const char *mode)
{
	int	fd;
	int	flags;
	int	oflags;

	if (ft_strcmp ((char *)filename, "/dev/null") == 0)
		filename = "NUL";
	flags = check_safety_flags(mode, &oflags);
	if (flags == 0)
		return (-1);
	fd = open(filename, oflags,
			(S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH));
	return (fd);
}

/*
 * Expand the line buffer.  Return -1 on error.
 */
static int	ft_expand_buffer(t_ft_file *fp, int newsize)
{
	void	*p;

	if (fp->s_buf.size >= newsize)
		return (0);
	p = ft_recallocarray(fp->s_buf.base, fp->s_buf.size, newsize, sizeof(char));
	if (p == NULL)
		return (-1);
	fp->s_buf.base = p;
	fp->s_buf.size = newsize;
	return (0);
}

/*
 * r      Open text file for reading.  The stream is positioned at the be‐
 *        ginning of the file.
 * r+     Open  for  reading and writing.  The stream is positioned at the
 *        beginning of the file.
 * w      Truncate file to zero length or create text  file  for  writing.
 *        The stream is positioned at the beginning of the file.
 * w+     Open  for  reading  and writing.
 * a      Open  for  appending (writing at end of file).
 * a+     Open  for  reading  and appending (writing at end of file).
 */
t_ft_file	*ft_fopen(const char *filename, const char *mode)
{
	int			fd;
	t_ft_file	*fp;

	fp = ft_prep_fp();
	if (fp == NULL)
		return (NULL);
	fd = ft_fdopen(filename, mode);
	if (fd < 0 || fd > SHRT_MAX)
	{
		fp->_flags = 0;
		close(fd);
		free(fp);
		return (NULL);
	}
	fp->_file = fd;
	fp->_cookie = fp;
	fp->_read = ft_fread;
	return (fp);
}

///*
// * Expand the line buffer.  Return -1 on error.
// */
//static int	ft_expand_line_buffer(t_ft_file *fp, int newsize)
//{
//	void *p;
//
//	if (fp->s_line_buf.size >= newsize)
//		return (0);
//	p = ft_recallocarray(fp->s_line_buf.base, fp->s_line_buf.size, newsize, 1);
//	if (p == NULL)
//		return (-1);
//	fp->s_line_buf.base = p;
//	fp->s_line_buf.size = newsize;
//	return (0);
//}

int	ft_refill(t_ft_file *fp)
{
	fp->_r = 0;
	if ((fp->_flags & SAFE_TO_READ) == 0)
		fp->_flags |= SAFE_TO_READ;
	if (fp->s_buf.base == NULL)
		ft_expand_buffer(fp, MAXC);
	fp->ptr = fp->s_buf.base;
	fp->_r = (*fp->_read)(fp->_cookie, (char *)fp->ptr, fp->s_buf.size);
	if (fp->_r <= 0)
	{
		if (fp->_r == 0)
			fp->_flags |= FOUND_EOF;
		else
		{
			fp->_r = 0;
			fp->_flags |= FOUND_ERR;
		}
		return (EOF);
	}
	return (0);
}
