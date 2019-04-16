/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 17:32:32 by zamazzal          #+#    #+#             */
/*   Updated: 2019/03/02 17:57:46 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_filetype(mode_t mode)
{
	if (S_ISDIR(mode))
		ft_putchar('d');
	else if (S_ISCHR(mode))
		ft_putchar('c');
	else if (S_ISBLK(mode))
		ft_putchar('b');
	else if (S_ISREG(mode))
		ft_putchar('-');
	else if (S_ISFIFO(mode))
		ft_putchar('p');
	else if (S_ISLNK(mode))
		ft_putchar('l');
	else if (S_ISSOCK(mode))
		ft_putchar('s');
}

void	ft_addinlist(t_ulist **content, char *path, char *name)
{
	char	*ok;
	char	*ok2;

	ok = ft_strjoin(path, "/");
	ok2 = ft_strjoin(ok, name);
	ft_newlist(content, ok2);
	free(ok);
	free(ok2);
}

void	ft_openmydir(char *path, char *flags)
{
	t_ulist			*content;
	DIR				*mydir;
	struct dirent	*dlist;

	content = NULL;
	if (!(mydir = opendir(path)))
		ft_filexerror(path);
	else
	{
		while ((dlist = readdir(mydir)))
			ft_addinlist(&content, path, dlist->d_name);
		closedir(mydir);
		if (content != NULL)
		{
			ft_listsort(&content, flags);
			if (ft_strrchr(flags, 'l'))
				ft_showblocks(content, flags);
			ft_shows(content, flags);
			ft_listclear(content);
			content = NULL;
		}
	}
	ft_listclear(content);
}

void	ft_lsr(t_ulist *t_mylist, char *flags)
{
	ft_listsort(&t_mylist, flags);
	while (t_mylist)
	{
		if (S_ISDIR(t_mylist->buff.st_mode))
		{
			ft_putchar('\n');
			ft_name(t_mylist->name);
			ft_openmydir(t_mylist->name, flags);
		}
		t_mylist = t_mylist->next;
	}
}

void	ft_ls(t_ulist *t_mylist, char *flags)
{
	t_ulist *tmp;
	int		i;

	ft_listsort(&t_mylist, flags);
	i = ft_showfiles(t_mylist, flags);
	while (t_mylist)
	{
		if (S_ISDIR(t_mylist->buff.st_mode))
		{
			if (i > 1)
				ft_name(t_mylist->name);
			ft_openmydir(t_mylist->name, flags);
			if (t_mylist->next != NULL)
			{
				tmp = t_mylist->next;
				if (S_ISDIR(tmp->buff.st_mode))
					ft_putchar('\n');
			}
		}
		t_mylist = t_mylist->next;
	}
}
