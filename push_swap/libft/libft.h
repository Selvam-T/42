/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:21:06 by sthiagar          #+#    #+#             */
/*   Updated: 2024/01/31 15:55:29 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_list
{
	int						num;
	int						rank;
	int						bcrank;
	int						rot_cost;
	struct s_list			*next;
}	t_list;

int			ft_isdigit(int c);
int			ft_is_strdigit(const char *nptr);
long		ft_atoi(const char *nptr);
size_t		ft_strlen(const char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
t_list		*ft_lstnew(int num);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstadd_front(t_list **lst, t_list *new);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstbeforelast(t_list *lst);
t_list		*ft_lst_extlast(t_list *lst);
char		**ft_split(char const *s, char c);
char		*ft_strchr(const char *s, int c);
void		*ft_calloc(size_t nmemb, size_t size);
char		*ft_substr(char const *s, unsigned int start, size_t len);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);

#endif
