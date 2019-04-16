/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 15:40:25 by zamazzal          #+#    #+#             */
/*   Updated: 2019/03/04 17:49:01 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_newline(char *flags, int i)
{
	if (!ft_strchr(flags, 'l') && !ft_strchr(flags, '1')
			&& !ft_strchr(flags, 'g') && !ft_strchr(flags, 'n'))
	{
		if (i > 2 || ft_strchr(flags, 'a'))
			ft_putchar('\n');
	}
}

int		ft_getmyflag(char *flags)
{
	int i;

	i = ft_strlen(flags) - 1;
	while (i >= 0)
	{
		if (flags[i] == 'l' || flags[i] == 'g' || flags[i] == 'n')
			return (1);
		else if (flags[i] == '1')
			return (2);
		i--;
	}
	return (0);
}

void	ft_manglin(char *flags, t_ulist *r_content, int i)
{
	ft_newline(flags, i);
	if (r_content != NULL)
		ft_lsr(r_content, flags);
	ft_listclear(r_content);
}

void	ft_showacls(char *name)
{
	acl_t	acl;
	ssize_t xattr;

	acl = NULL;
	xattr = 0;
	acl = acl_get_link_np(name, ACL_TYPE_EXTENDED);
	xattr = listxattr(name, NULL, 0, XATTR_NOFOLLOW);
	if (xattr > 0)
		ft_putchar('@');
	else if (acl != NULL)
		ft_putchar('+');
}
