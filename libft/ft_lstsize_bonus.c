/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslim <jslim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 16:41:46 by jslim             #+#    #+#             */
/*   Updated: 2025/06/05 16:42:13 by jslim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*head;
	int		i;

	i = 0;
	head = lst;
	while (head)
	{
		head = head -> next;
		i++;
	}
	return (i);
}

// #include <stdio.h>
// int main()
// {
// 	t_list *head = NULL;
// 	t_list *new1 = ft_lstnew("second");
// 	t_list *new2 = ft_lstnew("first");
// 	ft_lstadd_front(&head, new1);
// 	ft_lstadd_front(&head, new2);
// 	printf("%d", ft_lstsize(head));
// 	return 0;
// }
