/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:58:27 by abelov            #+#    #+#             */
/*   Updated: 2023/10/24 15:58:30 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_UTILS_H
# define STRING_UTILS_H
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
/*
 * This is sqrt(SIZE_MAX+1), as s1*s2 <= SIZE_MAX
 * if both s1 < MUL_NO_OVERFLOW and s2 < MUL_NO_OVERFLOW
 */
# define PAGESIZE 2048

static const char	g_ascii_zero_character = '\0';
static const char	g_ascii_space_character = ' ';
static const char	g_ascii_del_character = 127;

char			*ft_empty_string(int length);
char			*ft_strdup(char *src);
void			ft_putstr(char *str);
void			*ft_memset(void *dst, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
char			*ft_strncpy(char *dest, char *src, unsigned int n);
int				ft_strlen(char *str);
int				ft_strcmp(char *s1, char *s2);
char			*ft_strcpy(char *dest, char *src);
char			*ft_strcat(char *dest, char *src);
char			*ft_strjoin(int size, char **strs, char *sep);
size_t			ft_strcspn(const char *s1, const char *s2);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
int				is_numeric(char c);
int				is_printable(char c);
char			*ft_strncat(char *dest, char *src, unsigned int nb);
void			*ft_recallocarray(void *ptr,
					size_t oldnmemb, size_t newnmemb, size_t size);
#endif //STRING_UTILS_H
