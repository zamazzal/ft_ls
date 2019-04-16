/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 18:52:52 by zamazzal          #+#    #+#             */
/*   Updated: 2019/03/04 20:08:27 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include <stdio.h>
# include <sys/stat.h>
# include <dirent.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <sys/types.h>
# include <pwd.h>
# include <time.h>
# include <sys/acl.h>
# include <sys/xattr.h>

typedef struct		s_ulist
{
	struct stat		buff;
	char			*name;
	struct s_ulist	*next;
}					t_ulist;

void				ft_filetype(mode_t mode);
void				fileperm(mode_t mode);
void				showtime(struct timespec mytime);
void				ft_shownamein(struct stat	buff, char *name);
void				showinfo(char *name, char *flags);
int					ft_newlist(t_ulist **t_mylist, char *name);
void				sortbyname(t_ulist **t_mylist);
void				sortbytime(t_ulist **t_mylist);
void				sortbysize(t_ulist **t_mylist);
void				ft_addinlist(t_ulist **content, char *path, char *name);
void				ft_openmydir(char *path, char *flags);
void				ft_lsr(t_ulist *t_mylist, char *flags);
void				ft_ls(t_ulist *t_mylist, char *flags);
char				*ft_getflags(int argc, char **argv);
t_ulist				*ft_getnames(int argc, char **argv);
int					main(int argc, char **argv);
void				ft_flagerror(char c);
void				ft_fileerror(char *name);
void				ft_filexerror(char *name);
void				ft_name(char *str);
void				sortbyname_rev(t_ulist **t_mylist);
void				sortbytime_rev(t_ulist **t_mylist);
void				sortbysize_rev(t_ulist **t_mylist);
void				ft_showinfo(char *name, char *flags);
void				ft_shows(t_ulist *t_mylist, char *flags);
int					ft_showfiles(t_ulist *t_mylist, char *flags);
void				ft_showblocks(t_ulist *t_mylist, char *flags);
void				ft_listsort(t_ulist **t_mylist, char *flags);
void				freesplit(char **str);
char				*splitname(char *name);
void				ft_listclear(t_ulist *t_mylist);
int					ft_isflag(char c);
void				ft_swapx(char **name1, struct stat *buff1,
	char **name2, struct stat *buff2);
void				ft_showblck(int nbr);
void				ft_newline(char *flags, int i);
int					ft_getmyflag(char *flags);
void				ft_manglin(char *flags, t_ulist *r_content, int i);
void				ft_showacls(char *name);
#endif
