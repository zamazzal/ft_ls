/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 15:35:28 by zamazzal          #+#    #+#             */
/*   Updated: 2019/03/01 19:02:02 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_showinfo(char *name, char *flags)
{
	int		i;
	char	*oname;

	oname = splitname(name);
	if (oname[0] == '.' && !ft_strchr(flags, 'a'))
	{
		free(oname);
		return ;
	}
	else
	{
		i = ft_getmyflag(flags);
		if (i == 2)
			ft_putendl(oname);
		else if (i == 1)
			showinfo(name, flags);
		else
		{
			ft_putstr(oname);
			ft_putstr("   ");
		}
	}
	free(oname);
}

void	ft_shows(t_ulist *t_mylist, char *flags)
{
	int		i;
	char	*oname;
	t_ulist	*r_content;

	r_content = NULL;
	i = 0;
	while (t_mylist)
	{
		oname = splitname(t_mylist->name);
		ft_showinfo(t_mylist->name, flags);
		i++;
		if (ft_strchr(flags, 'R') && (S_ISDIR(t_mylist->buff.st_mode)))
		{
			if (oname[0] == '.' && !ft_strchr(flags, 'a'))
				oname = (oname != NULL) ? oname : NULL;
			else
			{
				if (!ft_strequ(oname, ".") && !ft_strequ(oname, ".."))
					ft_newlist(&r_content, t_mylist->name);
			}
		}
		free(oname);
		t_mylist = t_mylist->next;
	}
	ft_manglin(flags, r_content, i);
}

int		ft_showfiles(t_ulist *t_mylist, char *flags)
{
	int j;
	int i;
	int x;

	i = 0;
	x = 0;
	j = 0;
	while (t_mylist)
	{
		if (!S_ISDIR(t_mylist->buff.st_mode))
		{
			ft_showinfo(t_mylist->name, flags);
			j++;
		}
		else
			x++;
		t_mylist = t_mylist->next;
		i++;
	}
	if (x > 0 && j > 0)
		ft_putchar('\n');
	return (i);
}

void	ft_showblocks(t_ulist *t_mylist, char *flags)
{
	char		*oname;
	struct stat	buffx;
	int			i;
	int			size;

	size = 0;
	i = 0;
	while (t_mylist)
	{
		oname = splitname(t_mylist->name);
		if ((lstat(t_mylist->name, &buffx) != 0) ||
			(oname[0] == '.' && !ft_strchr(flags, 'a')))
		{
			free(oname);
			t_mylist = t_mylist->next;
			continue ;
		}
		size += buffx.st_blocks;
		t_mylist = t_mylist->next;
		i++;
		free(oname);
	}
	if (i > 0 || ft_strchr(flags, 'a'))
		ft_showblck(size);
}

void	ft_shownamein(struct stat	buff, char *name)
{
	char *buffx;
	char *only;

	only = splitname(name);
	if (S_ISLNK(buff.st_mode))
	{
		buffx = ft_strnew(buff.st_size);
		readlink(name, buffx, buff.st_size + 1);
		ft_putstr(only);
		ft_putstr(" -> ");
		ft_putstr(buffx);
		free(buffx);
	}
	else
		ft_putstr(only);
	free(only);
}
