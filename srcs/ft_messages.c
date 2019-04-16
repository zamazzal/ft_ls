/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 15:31:12 by zamazzal          #+#    #+#             */
/*   Updated: 2019/02/26 15:36:25 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_flagerror(char c)
{
	ft_putstr("ft_ls : illegal option -- ");
	ft_putchar(c);
	ft_putchar('\n');
	ft_putendl("usage: ft_ls [-RSalgrntis1] [file ...]");
}

void	ft_fileerror(char *name)
{
	ft_putstr("ft_ls: ");
	ft_putstr(name);
	ft_putendl(": No such file or directory");
}

void	ft_filexerror(char *name)
{
	ft_putstr("ft_ls: ");
	ft_putstr(name);
	perror(" ");
}

void	ft_name(char *str)
{
	ft_putstr(str);
	ft_putendl(":");
}

void	ft_showblck(int nbr)
{
	ft_putstr("total ");
	ft_putnbr(nbr);
	ft_putchar('\n');
}
