/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_infos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 15:29:36 by zamazzal          #+#    #+#             */
/*   Updated: 2019/02/26 15:29:38 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	fileperm(mode_t mode)
{
	(mode & S_IRUSR) ? ft_putchar('r') : ft_putchar('-');
	(mode & S_IWUSR) ? ft_putchar('w') : ft_putchar('-');
	if (mode & S_ISUID)
		(mode & S_IXUSR) ? ft_putchar('s') : ft_putchar('S');
	else if (mode & S_IXUSR)
		ft_putchar('x');
	else
		ft_putchar('-');
	(mode & S_IRGRP) ? ft_putchar('r') : ft_putchar('-');
	(mode & S_IWGRP) ? ft_putchar('w') : ft_putchar('-');
	if (mode & S_ISGID)
		(mode & S_IXGRP) ? ft_putchar('s') : ft_putchar('S');
	else if (mode & S_IXGRP)
		ft_putchar('x');
	else
		ft_putchar('-');
	(mode & S_IROTH) ? ft_putchar('r') : ft_putchar('-');
	(mode & S_IWOTH) ? ft_putchar('w') : ft_putchar('-');
	if (mode & S_ISVTX)
		(mode & S_IXOTH) ? ft_putchar('t') : ft_putchar('T');
	else if (mode & S_IXOTH)
		ft_putchar('x');
	else
		ft_putchar('-');
}

void	showinfo2(char *name, struct stat	buff)
{
	size_t	j;
	size_t	i;
	char	*filetime;

	ft_putchar('\t');
	ft_putnbr(buff.st_size);
	ft_putchar('\t');
	filetime = ctime(&buff.st_mtimespec.tv_sec);
	j = ft_strlen(filetime) - 9;
	i = 3;
	while (i < j)
		ft_putchar(filetime[i++]);
	ft_putchar('\t');
	ft_shownamein(buff, name);
	ft_putchar('\n');
}

void	showinfod(char *name, struct stat	buff)
{
	size_t	j;
	size_t	i;
	char	*filetime;

	ft_putchar('\t');
	if (S_ISCHR(buff.st_mode) || S_ISBLK(buff.st_mode))
	{
		ft_putnbr(major(buff.st_rdev));
		ft_putstr(",  ");
	}
	ft_putnbr(minor(buff.st_rdev));
	ft_putchar('\t');
	filetime = ctime(&buff.st_mtimespec.tv_sec);
	j = ft_strlen(filetime) - 9;
	i = 3;
	while (i < j)
		ft_putchar(filetime[i++]);
	ft_putchar('\t');
	ft_shownamein(buff, name);
	ft_putchar('\n');
}

void	showinfox2(struct stat buff, char *flags)
{
	if (ft_strchr(flags, 'i'))
	{
		ft_putnbr(buff.st_ino);
		ft_putchar('\t');
	}
	if (ft_strchr(flags, 's'))
	{
		ft_putnbr(buff.st_blocks);
		ft_putchar('\t');
	}
	ft_filetype(buff.st_mode);
	fileperm(buff.st_mode);
}

void	showinfo(char *name, char *flags)
{
	struct stat	buff;

	if (lstat(name, &buff) != 0)
		return ;
	showinfox2(buff, flags);
	ft_showacls(name);
	ft_putchar('\t');
	ft_putnbr(buff.st_nlink);
	ft_putchar('\t');
	if (!ft_strchr(flags, 'g'))
	{
		(ft_strchr(flags, 'n')) ? ft_putnbr(buff.st_uid) :
			ft_putstr(getpwuid(buff.st_uid)->pw_name);
		ft_putchar('\t');
	}
	(ft_strchr(flags, 'n')) ? ft_putnbr(buff.st_gid) :
		ft_putstr(getgrgid(buff.st_gid)->gr_name);
	(ft_strstr(name, "/dev/")) ? showinfod(name, buff) : showinfo2(name, buff);
}
