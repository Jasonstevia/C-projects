/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslim <jslim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 16:13:03 by jslim             #+#    #+#             */
/*   Updated: 2025/06/05 16:13:20 by jslim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new -> next = *lst;
	*lst = new;
}

// #include <stdio.h>
// int main()
// {
// 	t_list *head = NULL;
// 	t_list *new1 = ft_lstnew("Hello");
// 	t_list *new2 = ft_lstnew("World");
// 	ft_lstadd_front(&head, new1);
// 	ft_lstadd_front(&head, new2);
// 	while(head)
// 	{
// 		printf("%s\n", (char *)head -> content);
// 		head = head -> next;
// 	}
// 	return 0;

// }
