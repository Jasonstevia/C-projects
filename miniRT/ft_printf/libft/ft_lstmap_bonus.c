/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslim <jslim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:05:10 by jslim             #+#    #+#             */
/*   Updated: 2025/06/18 13:52:35 by jslim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_del(void *str)
{
	if (!str)
		return ;
	free(str);
}

// void	*f(void *str)
// {
// 	char	*s;
// 	char	*copy;
// 	char	*p;

// 	s = (char *)str;
// 	copy = ft_strdup(s);
// 	if (!copy)
// 		return (NULL);
// 	p = copy;
// 	while (*p)
// 	{
// 		if (*p >= 'A' && *p <= 'Z')
// 			*p = *p + 32;
// 		p++;
// 	}
// 	return (copy);
// }

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*s;
	t_list	*node;
	void	*new_content;

	s = NULL;
	if (!lst)
		return (NULL);
	while (lst)
	{
		new_content = f(lst -> content);
		node = ft_lstnew(new_content);
		if (!node)
		{
			ft_del(new_content);
			ft_lstclear(&s, del);
			return (NULL);
		}
		ft_lstadd_back(&s, node);
		lst = lst -> next;
	}
	return (s);
}
