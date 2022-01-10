/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 10:40:08 by adrossig          #+#    #+#             */
/*   Updated: 2021/01/14 12:02:48 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include "libft.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

int		ft_lstsize(t_list *lst);
void	ft_lst_putstr(t_list *elem);
void	ft_lst_putendl(t_list *elem);
void	ft_lst_putstr_fd(t_list *elem, int fd);
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstadd_front(t_list **alst, t_list *new);
size_t	ft_lstlenght(t_list *list);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(void *content);
t_list	*ft_lstappend(t_list *head, t_list *last);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
