/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-ghaz <fel-ghaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:03:58 by fel-ghaz          #+#    #+#             */
/*   Updated: 2024/08/16 14:53:47 by fel-ghaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct nodee
{
    int data;
    struct nodee *next;
    struct nodee *previous;
    struct nodee *target;
} t_node;

t_node *create_node(int data);
t_node *find_last_node(t_node *head);
void append_node(t_node **stack, int data);
int ft_atoi(char *str);
void free_linkedlist(t_node *head);
t_node *create_array(int ac, char **av);
void push(t_node **source, t_node **destination);
void pa(int flag, t_node **a, t_node **b);
void pb(int flag, t_node **b, t_node **a);
void rotate(t_node **head);
void reverse_rotate(t_node **stack);
void ra(int flag, t_node **head);
void rb(int flag, t_node **head);
void rr(t_node **a, t_node **b);
void rra(int flag, t_node **stack);
void rrb(int flag, t_node **stack);
void rrr(t_node **a, t_node **b);
void swap(t_node **head);
void sa(int flag, t_node **stack);
void sb(int flag, t_node **stack);
void ss(t_node **a, t_node **b);
void sort_3_nodes(t_node **stack);
t_node *find_smallest(t_node **stack);
t_node *set_target_node(t_node *node_a, t_node **b);
t_node *find_highest(t_node **stack);
void push_first_2_numbers(t_node **a, t_node **b);
void set_target_nodes_for_a(t_node **a, t_node **b);
int count_nodes(t_node **a);
int position(t_node *node, t_node **stack);
int cost_analysis_top(t_node *node, t_node **a);
void put_top(t_node **stack, t_node *node);
void    put_both_top(t_node **a, t_node **b, t_node *node, t_node *target);
int calculate_combined_cost(t_node *node, t_node *target, t_node **a, t_node **b);
t_node *find_cheapest_node(t_node **a, t_node **b);
void push_to_top(t_node **a, t_node **b);
void rotate_both_simultaneously(t_node **a, t_node **b, int p1, int p2, int count_a, int count_b);
void rotate_stack_b(t_node **b, int p2, int count_b);
void rotate_stack_a(t_node **a, int p1, int count_a);
void sort_b(t_node **stack_b);
void print_stack(t_node *stack) ;
void move_b_to_a(t_node **a, t_node **b);
void sort_a (t_node **a);

#endif