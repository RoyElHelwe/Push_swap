/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-ghaz <fel-ghaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 13:02:05 by fel-ghaz          #+#    #+#             */
/*   Updated: 2024/08/16 04:02:26 by fel-ghaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_node *create_node(int data)
{
    t_node *created = (t_node *)malloc(sizeof(t_node));
    created->data = data;
    created->next = NULL;
    created->previous = NULL;
    return created;
}
t_node *find_last_node(t_node *head)
{
    if(head == NULL)
        return NULL;
    while (head -> next != NULL)
        head = head -> next;
    return (head);
}
void append_node(t_node **stack, int data)
{
    if(stack == NULL)
        return ;
    t_node *node = create_node(data);
    t_node *last_node;
    if (node == NULL)
        return;
    node ->next = NULL;
    node -> data = data;
    if (*stack == NULL)
    {
        *stack = node;
        node -> previous = NULL;
    }
    else
    {
        last_node = find_last_node(*stack);
        last_node -> next = node;
        node -> previous = last_node;
    }
}
int count_nodes(t_node **a)
{
    int count = 0;
    t_node *current;
    
    current = (*a);
    while(current != NULL)
    {
        count++;
        current = current -> next;
    }
    return count;
}
int position(t_node *node, t_node **stack)
{
    int count = 0;
    t_node *current = (*stack);
    while(current != NULL)
    {
        count++;
        if(current -> data == node -> data)
            return count;
        current = current -> next;
        
    }
    return count;
}

//5 functions