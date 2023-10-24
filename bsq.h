/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:04:58 by abelov            #+#    #+#             */
/*   Updated: 2023/10/24 17:05:00 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H
# include "string_utils.h"
# include "bsq_def.h"

t_baguette	get_solution(t_baguette b);
char		*serializer(t_baguette b);
#endif //BSQ_H