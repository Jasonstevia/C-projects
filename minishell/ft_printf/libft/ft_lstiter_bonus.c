/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslim <jslim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 11:19:33 by jslim             #+#    #+#             */
/*   Updated: 2025/06/18 13:50:51 by jslim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	f(void *s)
// {
// 	char	*str;

// 	str = (char *)s;
// 	while (*str)
// 	{
// 		if (*str >= 'A' && *str <= 'Z')
// 			*str = *str + 32;
// 		str++;
// 	}
// }

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst -> content);
		lst = lst -> next;
	}
}

// #include <stdio.h>
// int main()
// {
//     t_list *head = NULL;
//     t_list *new = ft_lstnew(ft_strdup("hello"));
//     t_list *new1 = ft_lstnew(ft_strdup("world"));
//     ft_lstadd_front(&head, new);
//     ft_lstadd_front(&head, new1);
//     ft_lstiter(head, f);

//     t_list *tmp = head;
//     while (tmp)
//     {
//         printf("%s\n", (char *)tmp -> content);
//         tmp = tmp -> next;
//     }
//     ft_lstclear(&head, free);
//     return 0;
// }
