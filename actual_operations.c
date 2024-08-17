/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actual_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-ghaz <fel-ghaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 13:15:45 by fel-ghaz          #+#    #+#             */
/*   Updated: 2024/08/16 12:36:27 by fel-ghaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void rotate_stack_a(t_node **a, int p1, int count_a)
{
    if (p1 <= count_a / 2 + 1)
        ra(0, a);
    else
        rra(0, a);
}

void rotate_stack_b(t_node **b, int p2, int count_b)
{
    if (p2 <= count_b / 2 + 1)
        rb(0, b);
    else
        rrb(0, b);
}

void rotate_both_simultaneously(t_node **a, t_node **b, int p1, int p2, int count_a, int count_b)
{
    if (p1 <= count_a / 2 + 1 && p2 <= count_b / 2 + 1)
        rr(a, b);
    else if (p1 <= count_a / 2 + 1 && p2 > count_b / 2 + 1)
    {
        ra(0, a);
        rrb(0, b);
    }
    else if (p2 <= count_b / 2 + 1 && p1 > count_a / 2 + 1)
    {
        rra(0, a);
        rb(0, b);
    }
    else
        rrr(a, b);
}

void put_both_top(t_node **a, t_node **b, t_node *node, t_node *target)
{
    int count_a = count_nodes(a);
    int count_b = count_nodes(b);
    int n1 = cost_analysis_top(node, a);
    int n2 = cost_analysis_top(target, b);
    int p1 = position(node, a);
    int p2 = position(target, b);

    if (n1 == n2)
    {
        while (n1 > 0)
        {
            rotate_both_simultaneously(a, b, p1, p2, count_a, count_b);
            n1--;
        }
    }
    else
    {
        while (n1 > 0)
        {
            rotate_stack_a(a, p1, count_a);
            n1--;
        }
        while (n2 > 0)
        {
            rotate_stack_b(b, p2, count_b);
            n2--;
        }
    }
}
// void    put_both_top(t_node **a, t_node **b, t_node *node, t_node *target)
// {
//     int count_a = count_nodes(a);
//     int count_b = count_nodes(b);
//     int n1 = cost_analysis_top(node, a);
//     int n2 = cost_analysis_top(target, b);
//     int p1 = position(node, a);
//     int p2 = position(target,b);

//     if (n1 == n2)
//     {
//         while (n1 > 0)
//         {
//             if (p1 <= count_a / 2 + 1 && p2 <= count_b / 2 + 1)
//                 rr(a, b);
//             else if (p1 <= count_a / 2 + 1 && p2 > count_b / 2 +1)
//             {
//                 ra(0, a);
//                 rrb(0, b);
//             }
//             else if (p2 <= count_b / 2 + 1 && p1 > count_a / 2 +1)
//             {
//                 rra(0, a);
//                 rb(0, b);
//             }
//             else
//                 rrr(a, b);
//             n1--;
//         }
//     }
//     else 
//     {
//         while (n1 > 0)
//         {
//             if (p1 <= count_a / 2 + 1)
//                  ra(0, a);
//             else 
//                 rra(0, a);
//             n1--;
//         }
//         while (n2 > 0) 
//         {
//             if (p2 <= count_b / 2 + 1) 
//                 rb(0, b);
//             else 
//                 rrb(0, b);
//             n2--;
//         }
//     }
// }
// void push_to_top(t_node **a, t_node **b)
// {
//     t_node *head = *a;
//     while(*a != NULL)
//     {
//         t_node *target = set_target_node(head, b);
//         t_node *cheapest = find_cheapest_node(a, b);
//         put_both_top (a, b, cheapest, target);
//         (*a) = (*a) -> next;
//         pb(0, a, b);
//     }
// }
void push_to_top(t_node **a, t_node **b)
{
    while (*a != NULL)
    {
        t_node *cheapest = find_cheapest_node(a, b);
        t_node *target = set_target_node(cheapest, b);
    
        // printf("Processing node: %d\n", cheapest->data);
        // printf("Target node: %d\n", target->data);

        put_both_top(a, b, cheapest, target);
        
        pb(0, b, a); // Move from 'a' to 'b'

        // printf("Node %d moved to stack b\n", cheapest->data);
    }
}
void print_stack(t_node *stack) 
{
    while (stack)
    {
        printf("%d \n", stack->data);
        stack = stack->next;
    }
    printf("\n");
}

void sort_b(t_node **stack_b)
{
    t_node *max = find_highest(stack_b);
    int pos = position(max, stack_b);
    int size = count_nodes(stack_b);
    if (pos <= size / 2)
    {
        while (*stack_b != max) 
            rb(0, stack_b);
    }
    else
    {
        while (*stack_b != max)
            rrb(0, stack_b);
    }
    // printf("Stack B after sorting: \n");
    // print_stack(*stack_b);
}
