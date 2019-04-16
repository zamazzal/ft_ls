/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 14:42:28 by zamazzal          #+#    #+#             */
/*   Updated: 2019/03/04 20:41:41 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	sortbyname_rev(t_ulist **t_mylist)
{
	t_ulist	*tmp;
	t_ulist	*tmp2;

	tmp = *t_mylist;
	while (tmp->next)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (ft_strcmp(tmp->name, tmp2->name) < 0)
				ft_swapx(&tmp->name, &tmp->buff, &tmp2->name, &tmp2->buff);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

void	sortbytime_rev(t_ulist **t_mylist)
{
	t_ulist	*tmp;
	t_ulist	*tmp2;

	tmp = *t_mylist;
	while (tmp->next)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if ((tmp->buff.st_mtime > tmp2->buff.st_mtime) ||
			((tmp->buff.st_mtime == tmp2->buff.st_mtime) &&
			(ft_strcmp(tmp->name, tmp2->name) < 0)))
				ft_swapx(&tmp->name, &tmp->buff, &tmp2->name, &tmp2->buff);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

void	sortbysize_rev(t_ulist **t_mylist)
{
	t_ulist	*tmp;
	t_ulist	*tmp2;

	tmp = *t_mylist;
	while (tmp->next)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if ((tmp->buff.st_size > tmp2->buff.st_size) ||
			((tmp->buff.st_size == tmp2->buff.st_size) &&
			(ft_strcmp(tmp->name, tmp2->name) < 0)))
				ft_swapx(&tmp->name, &tmp->buff, &tmp2->name, &tmp2->buff);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}
