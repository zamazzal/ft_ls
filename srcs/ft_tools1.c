/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 15:31:29 by zamazzal          #+#    #+#             */
/*   Updated: 2019/03/04 20:38:30 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_listsort(t_ulist **t_mylist, char *flags)
{
	if (ft_strchr(flags, 't') && !ft_strchr(flags, 'S'))
		ft_strchr(flags, 'r') ? sortbytime_rev(t_mylist) : sortbytime(t_mylist);
	else if (ft_strchr(flags, 'S'))
		ft_strchr(flags, 'r') ? sortbysize_rev(t_mylist) : sortbysize(t_mylist);
	else
		ft_strchr(flags, 'r') ? sortbyname_rev(t_mylist) : sortbyname(t_mylist);
}

void	freesplit(char **str)
{
	int i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

char	*splitname(char *name)
{
	char	*done;
	char	**file;
	int		i;

	i = 0;
	file = ft_strsplit(name, '/');
	while (file[i])
		i++;
	done = ft_strdup(file[i - 1]);
	freesplit(file);
	return (done);
}

void	ft_listclear(t_ulist *t_mylist)
{
	t_ulist		*tmp;

	while (t_mylist)
	{
		free(t_mylist->name);
		tmp = t_mylist;
		t_mylist = t_mylist->next;
		free(tmp);
	}
}

int		ft_isflag(char c)
{
	if (c == 'l' || c == 'R' || c == 'a' || c == 'i' || c == 's'
	|| c == 'r' || c == 't' || c == '1' || c == 'S' || c == 'g' || c == 'n')
		return (1);
	return (0);
}
