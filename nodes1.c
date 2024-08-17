/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-ghaz <fel-ghaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 08:00:57 by fel-ghaz          #+#    #+#             */
/*   Updated: 2024/08/16 04:23:43 by fel-ghaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_node *find_highest(t_node **b)
{
    if (b == NULL && *b == NULL)
        return NULL;
    t_node *stack = *b;   
    t_node *highest = (*b);
    while ((stack) != NULL)
    {
        if((stack) -> data > highest -> data)
            highest = (stack);
        (stack) = (stack) -> next;
    }
    return (highest);
}
t_node *find_smallest(t_node **stack)
{
    t_node *smallest;
    if(stack == NULL || *stack == NULL)
        return NULL;
    t_node *current = (*stack) -> next;
    smallest = *stack;
    while (current != NULL)
    {
        if(current -> data < smallest -> data)
            smallest = current;
        current = current -> next;
    }
    return smallest;
}
void push_first_2_numbers(t_node **a, t_node **b)
{
    pb(0, b, a);
    pb(0, b, a);
}

t_node *set_target_node(t_node *node_a, t_node **b)
{
    int eee;
    t_node *temp;
    t_node *current;
    temp = NULL;
    
    eee = -2147483648;
    current = (*b);
    while(current)
    {
        if ((node_a) -> data > current -> data && current -> data > eee)
        {
            eee = current -> data;
            temp = current;
        }
        current = current -> next;
     }
    if (temp == NULL)
        temp = find_highest(b);
    return (temp);
}
void set_target_nodes_for_a(t_node **a, t_node **b)
{
    t_node *current_target;
    t_node *current_a;
    if(*b == NULL)
        push_first_2_numbers(a, b);
    current_a = (*a);
    while(current_a != NULL)
    {
        current_target = set_target_node(current_a, b);
        //printf("%d\n", current_target -> data);
        current_a = current_a -> next;
       //free(current_target);
    }
    if (current_target == NULL)
        return;
}
// saro 5 functions!!!!!