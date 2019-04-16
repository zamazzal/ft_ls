/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 21:51:22 by zamazzal          #+#    #+#             */
/*   Updated: 2019/03/04 18:17:19 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*ft_getflags(int argc, char **argv)
{
	char	*fg;
	int		i;
	int		j;
	int		x;

	fg = ft_memalloc(128);
	i = 1;
	x = 0;
	while (i < argc && argv[i][0] == '-' && ft_isprint(argv[i][1])
	&& !ft_strequ(argv[i], "--"))
	{
		j = 1;
		while (argv[i][j] != '\0')
		{
			if (ft_isflag(argv[i][j]))
				fg[x++] = argv[i][j++];
			else
			{
				ft_flagerror(argv[i][j]);
				return (NULL);
			}
		}
		i++;
	}
	return (fg);
}

t_ulist		*ft_getnames(int argc, char **argv)
{
	t_ulist		*list_n;
	int			i;
	int			check;
	struct stat	tester;

	list_n = NULL;
	i = 1;
	check = 0;
	while (i < argc && argv[i][0] == '-' &&
	ft_isprint(argv[i][1]) && !ft_strequ(argv[i], "--"))
		i++;
	if (ft_strequ(argv[i], "--"))
		i++;
	while (i < argc)
	{
		(lstat(argv[i], &tester) == 0) ? ft_newlist(&list_n, argv[i])
		: ft_fileerror(argv[i]);
		i++;
		check = 1;
	}
	if (check == 0 && list_n == NULL)
		ft_newlist(&list_n, ".");
	return (list_n);
}

int			main(int argc, char **argv)
{
	t_ulist *list_n;
	char	*flags;

	if ((flags = ft_getflags(argc, argv)) == NULL)
		exit(EXIT_FAILURE);
	if ((list_n = ft_getnames(argc, argv)) == NULL)
		exit(EXIT_FAILURE);
	ft_ls(list_n, flags);
	free(flags);
	ft_listclear(list_n);
	exit(EXIT_SUCCESS);
}
