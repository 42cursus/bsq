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

static const char	g_ascii_zero_character = '\0';

char	*ft_strdup(char *src);
void	ft_putstr(char *str);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strcat(char *dest, char *src);
char	*ft_strjoin(int size, char **strs, char *sep);
#endif //STRING_UTILS_H
