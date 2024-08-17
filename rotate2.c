/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-ghaz <fel-ghaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:55:35 by fel-ghaz          #+#    #+#             */
/*   Updated: 2024/08/16 10:06:53 by fel-ghaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void rr(t_node **a, t_node **b)
{
    ra(1, a);
    rb(1, b);
    write(1, "rr\n", 3);
}
void rra(int flag, t_node **stack)
{
    reverse_rotate(stack);
    if (flag == 0)
        write(1, "rra\n", 4);
}
void rrb(int flag, t_node **stack)
{
    reverse_rotate(stack);
    if(flag == 0)
        write(1, "rrb\n", 4);
}
void rrr(t_node **a, t_node **b)
{
    rra(1, a);
    rrb(1, b);
    write(1, "rrr\n", 4);
}

// 4