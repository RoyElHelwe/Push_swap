/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-ghaz <fel-ghaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:54:21 by fel-ghaz          #+#    #+#             */
/*   Updated: 2024/08/14 08:34:19 by fel-ghaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void rotate(t_node **head)
{
    t_node *new_tail = (*head);
    t_node *last = (*head);
    while (last->next != NULL)
        last = last->next;
    (*head) = new_tail -> next;
    (*head) -> previous = NULL;
    last -> next = new_tail;
    new_tail -> previous = last;
    new_tail -> next = NULL;
}
void reverse_rotate(t_node **stack)
{
    t_node *old_head = (*stack);
    t_node *new_tail = NULL;
    while((*stack) -> next != NULL)
        (*stack) = (*stack) -> next;
    new_tail = (*stack) -> previous;
    new_tail -> next = NULL;
    old_head -> previous = (*stack);
    (*stack) -> next = old_head;
}
void ra(int flag, t_node **head)
{
    rotate(head);
    if (flag == 0)
        write(1, "ra\n", 3);
}
void rb(int flag, t_node **head)
{
    rotate(head);
    if (flag == 0)
        write(1, "rb\n", 3);
}
//4 

