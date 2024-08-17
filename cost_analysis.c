/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_analysis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-ghaz <fel-ghaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:03:40 by fel-ghaz          #+#    #+#             */
/*   Updated: 2024/08/16 01:14:12 by fel-ghaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int cost_analysis_top(t_node *node, t_node **a)
{
    int count = count_nodes(a);
    int pos = position(node, a);
    int operation_nbr;
    if (pos <= count / 2 + 1)
        operation_nbr = pos - 1;
    else
        operation_nbr = count - pos + 1;
    return operation_nbr;
}
int calculate_combined_cost(t_node *node, t_node *target, t_node **a, t_node **b) 
{
    int cost_a = cost_analysis_top(node, a);
    int cost_b = cost_analysis_top(target, b);

    return cost_a + cost_b;
}
t_node *find_cheapest_node(t_node **a, t_node **b) 
{
    t_node *current = *a;
    t_node *cheapest_node = NULL;
    int min_cost = 2147483647;

    while (current)
    {
        t_node *target = set_target_node(current, b); 
        int cost = calculate_combined_cost(current, target, a, b);
        // printf("cost: %d \n", cost);
        if (cost < min_cost)
        {
            min_cost = cost;
            cheapest_node = current;
        }
        current = current->next;
    }
    return cheapest_node;
}


// int cost_analysis_b(t_node *node_a, t_node **b)
// {
//     int count = count_nodes(b);
//     int pos = position(node_a, b);
   
//     int operation_nbr;
//     t_node *highest_in_b = find_highest(b);
//      int cost = cost_analysis_top(highest_in_b, b);
//     if (node_a -> data > highest_in_b -> data)
//     {
//         if (position(highest_in_b, b) != 1)
             
            
//     }
//     // if (pos <= count / 2 + 1)
//     //     operation_nbr = pos - 1;
//     // else
//     //     operation_nbr = count - pos + 1;
//     // return operation_nbr;
// }
// void put_top(t_node **stack, t_node *node)
// {
//     int count = count_nodes(stack);
//     int nbr = cost_analysis_top(node, stack);
//     int positionn = position(node, stack);
//     // printf("%d\n%d\n%d\n\n", count, nbr, positionn);        
//         // while(nbr != 0)
//         // {
//         //     if (positionn <=  count / 2 + 1)
//         //     {
//         //             ra(0, stack);
//         //     }
//         //     else 
//         //         rra(0, stack);
//         //     nbr--;
//         // }  
// }
