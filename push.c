/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-ghaz <fel-ghaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:56:52 by fel-ghaz          #+#    #+#             */
/*   Updated: 2024/08/16 04:09:33 by fel-ghaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void push(t_node **source, t_node **destination)
{ 
    t_node *top_source = *source;
    if(*source == NULL)
        return;
    (*source) = (*source) -> next;
    if (*source != NULL)
        (*source)->previous = NULL;
    top_source -> next = (*destination);
    if (*destination != NULL)
        (*destination)->previous = top_source;
    top_source -> previous = NULL;
    (*destination) = top_source;
}

void pa (int flag, t_node **a, t_node **b)
{
    push(b, a);
    if(flag == 0)
        write (1, "pa\n", 3);
}

void pb(int flag, t_node **b, t_node **a)
{
    push(a, b);
    if (flag == 0)
        write(1, "pb\n", 3);
}
// void pb(int flag, t_node **b, t_node **a)
// {
//     if (*a == NULL)
//         return;

//     t_node *node_to_push = *a;  // Node to move from 'a' to 'b'
//     *a = (*a)->next;            // Update the head of 'a' to the next node

//     if (*a != NULL)
//         (*a)->previous = NULL;

//     node_to_push->next = *b;    // Place the node on top of 'b'
//     if (*b != NULL)
//         (*b)->previous = node_to_push;

//     *b = node_to_push;

//     if (flag == 0)
//         write(1, "pb\n", 3);
// }