/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslim <jslim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 17:34:29 by jslim             #+#    #+#             */
/*   Updated: 2025/06/18 14:40:20 by jslim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst -> content);
	free(lst);
}

// #include <stdio.h>
// int main()
// {
// 	t_list	*node = ft_lstnew(ft_strdup("HEllo"));
// 	printf("%s", (char *)node -> content);
// 	ft_lstdelone(node, del);
// 	return 0;
// }
