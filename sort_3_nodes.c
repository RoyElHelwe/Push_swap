/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-ghaz <fel-ghaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 13:06:16 by fel-ghaz          #+#    #+#             */
/*   Updated: 2024/08/14 11:48:12 by fel-ghaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void sort_3_nodes(t_node **stack)
{
    t_node *largest = find_highest(stack);
    if (*stack == largest)
        ra(0, stack);
    else if ((*stack) -> next == largest)
        rra(0, stack);
    if ((*stack) -> data > (*stack) -> next -> data)
        sa (0, stack);
}
