/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-ghaz <fel-ghaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:52:34 by fel-ghaz          #+#    #+#             */
/*   Updated: 2024/08/14 08:40:40 by fel-ghaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void swap(t_node **head)
{
    t_node *temp;
    temp = (*head);
    temp = (*head)->next;
    (*head)->next = temp->next;
    (*head)->previous = temp;
    temp->next = (*head);
    (*head) = temp;
}
void sa(int flag, t_node **stack)
{
    swap(stack);
    if(flag == 0)
        write (1, "sa\n", 3);
}
void sb(int flag, t_node **stack)
{
    swap(stack);
    if(flag == 0)
        write(1, "sb\n", 3);
}
void ss(t_node **a, t_node **b)
{
   sa(1, a);
   sb(1, b);
    write(1, "ss\n", 1);
}
//4