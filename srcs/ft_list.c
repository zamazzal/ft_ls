/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 14:48:31 by zamazzal          #+#    #+#             */
/*   Updated: 2019/03/04 20:41:07 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_swapx(char **name1, struct stat *buff1,
	char **name2, struct stat *buff2)
{
	t_ulist	backup;

	backup.name = *name1;
	backup.buff = *buff1;
	*name1 = *name2;
	*buff1 = *buff2;
	*name2 = backup.name;
	*buff2 = backup.buff;
}

int		ft_newlist(t_ulist **t_mylist, char *name)
{
	t_ulist	*tmp;

	if (!*t_mylist)
	{
		*t_mylist = (t_ulist*)malloc(sizeof(t_ulist));
		lstat(name, &(*t_mylist)->buff);
		(*t_mylist)->name = ft_strdup(name);
		(*t_mylist)->next = NULL;
	}
	else
	{
		tmp = *t_mylist;
		while (tmp->next)
			tmp = tmp->next;
		ft_newlist(&tmp->next, name);
	}
	return (1);
}

void	sortbyname(t_ulist **t_mylist)
{
	t_ulist	*tmp;
	t_ulist	*tmp2;

	tmp = *t_mylist;
	while (tmp->next)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (ft_strcmp(tmp->name, tmp2->name) > 0)
				ft_swapx(&tmp->name, &tmp->buff, &tmp2->name, &tmp2->buff);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

void	sortbytime(t_ulist **t_mylist)
{
	t_ulist	*tmp;
	t_ulist	*tmp2;

	tmp = *t_mylist;
	while (tmp->next)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if ((tmp->buff.st_mtime < tmp2->buff.st_mtime) ||
			((tmp->buff.st_mtime == tmp2->buff.st_mtime) &&
			(ft_strcmp(tmp->name, tmp2->name) > 0)))
				ft_swapx(&tmp->name, &tmp->buff, &tmp2->name, &tmp2->buff);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

void	sortbysize(t_ulist **t_mylist)
{
	t_ulist	*tmp;
	t_ulist	*tmp2;

	tmp = *t_mylist;
	while (tmp->next)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if ((tmp->buff.st_size < tmp2->buff.st_size) ||
			((tmp->buff.st_size == tmp2->buff.st_size) &&
			(ft_strcmp(tmp->name, tmp2->name) > 0)))
				ft_swapx(&tmp->name, &tmp->buff, &tmp2->name, &tmp2->buff);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}
