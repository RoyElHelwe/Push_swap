/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-ghaz <fel-ghaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 10:07:50 by fel-ghaz          #+#    #+#             */
/*   Updated: 2024/08/16 15:18:01 by fel-ghaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void move_b_to_a(t_node **a, t_node **b)
{
    t_node *head;
    
    head = *b;
    while(*b != NULL)
    {
        head = head->next;
        pa(0, a, b);
        *b = head;
    }
    // print_stack(*a);
}
void sort_a(t_node **a)
{
    t_node *head;

    head = *a;
    while (head != NULL)
    {
        printf("Current node: %d\n", head -> data);  // Debug print
        ra(0, &head);  // Assuming this function modifies the list
        if (head != NULL) {
            head = head->next;
        }
    }
    print_stack(*a);  // Print the original list
}
