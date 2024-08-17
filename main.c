/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-ghaz <fel-ghaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:08:45 by fel-ghaz          #+#    #+#             */
/*   Updated: 2024/08/16 14:55:43 by fel-ghaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int ft_atoi(char *str)
{
    int res = 0;
    int i = 0;
    int sign = 1;
    if (str[i] == '-' || str[i] == '+')
    {
        if(str[i+1] == '+' || str[i+1] == '-')
            return (0);
        else 
        {
            if(str[i] == '-')
                sign = -1;
        }
        i++;
    }
    while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
    {
        // if (sign == 1)
        // {
        //     if (res > (2147483647 - (str[i] - '0')) / 10)
        //         return 2147483647;
        // }
        // else
        // {
        //     if (res > (2147483647 - (str[i] - '0')) / 10)
        //         return -2147483648;
        // }
        res = res * 10 + (str[i] - '0');
        i++;
    }
    return res * sign;
}
void free_linkedlist(t_node *head)
{
    t_node *temp;
    temp = head;
    while(head != NULL)
    {
        temp = head -> next;
        free (head);
        head = temp;
    }
}
t_node *create_array(int ac, char **av)
{
    t_node *start;
    int i = 2;
    if(ac > 2)
    {
        int integer1 = ft_atoi(av[1]);
        t_node *head = create_node(integer1);
        head->previous = NULL;
        start = head;
        while (i < ac)
        {
            int integer = ft_atoi(av[i]);
            t_node *next_t_node = create_node(integer);
            head->next = next_t_node;
            next_t_node->previous = head;
            head = head->next;
            i++;
        }
        return start;
    }
    return NULL;
}
// int main(int ac, char **av)
// {

//     t_node *a = create_node(3);  
//     t_node *b = create_node(5);
    
//     // Manually chain the nodes if needed
//     a->next = create_node(7);
//     a->next->next = create_node(1);
//     a->next->next->next = create_node(6);
//     a->next->next->next->next = create_node(9);

//     b->next = create_node(2);
//     b->next->next = create_node(8);

//     // Now find the cheapest node in STACK_A to push to STACK_B
//     t_node *cheapest_node = find_cheapest_node(&a, &b);

//     if (cheapest_node) {
//         printf("Cheapest node to push: %d\n", cheapest_node->data);
//     } else {
//         printf("No cheapest node found.\n");
//     }

//     // Free the allocated memory
//     free_linkedlist(a);
//     free_linkedlist(b);

//     return 0;
// }


int main(int ac, char **av)
{
    t_node *a = create_array(ac, av);
    t_node *b = NULL;
 
    t_node *a2 = a;
     push_first_2_numbers(&a, &b);
       t_node *a1 = a;
    while(a1)
    {  
        t_node *target = set_target_node(a1, &b);
        // printf("\n%d is node a.", a1->data);
        // printf("\n%d is its target\n", target->data);
        int n = calculate_combined_cost(a1, target, &a, &b);
        // printf("\ncombined cost = %d\n", n);
        a1 = a1 -> next;
    }
   
    push_to_top(&a, &b);
    t_node *a3 = a;
    t_node *b3 = b;
    
    // printf("stack a is now: \n");
    // while(a3)
    // {
    //     printf("%d\n", a3->data);
    //     a3 = a3 -> next;
    // }
    sort_b(&b);
    move_b_to_a(&a, &b);
    sort_a (&a);
    //  printf("stack b is now: \n");
    // while(b3)
    // {
    //     printf("%d\n", b3->data);
    //     b3 = b3 -> next;
    // }
    //  push_to_top(&a1, &b);
    // while (current != NULL)
    // {
    //     printf("%d\n", current->data);
    //     current = current->next;
    // }
    // while(a2)
    // {
    //     printf("%d\n", a2-> data );
    //     a2 = a2->next;
    // }
    // int n;
    // while (a2 != NULL)
    // {
    //     n = cost_analysis_top(a2, &a);
    //     printf("%d\n", n );
    //     a2 = a2->next;
    // }
    // put_top(&a2, a1);
  
    // if(count_nodes(&a1) == 3)
    //     sort_3_nodes(&a1);
    // while (a1 != NULL)
    // {
    //     printf("%d\n", a1 ->data);
    //     a1  = a1 -> next;
    // }
                                                                                                                                        
    // int n = count_nodes(&a);
    // printf("%d", n);
    //set_target_node(&a, &b);
    // t_node *source = create_node(99);
    // b = create_node(8);
    // source -> next = b;
    // b -> previous = source;
    //  t_node *c = create_node(14);
    //  b-> next = c;
    // c -> previous = b;
    //  t_node *d = create_node(22);
    // c -> next = d;
    // d -> previous = c;
    // t_node *target = set_target_node(a1, &b);
    // printf(" the target of -3 is: %d\n", target -> data);
    // //t_node *target = set_target_node(a2, source);
    //   printf("Initial Stack A:\n");
    // t_node *current = b;
    // while (current != NULL) 
    // {
    //     printf("%d\n", current->data);
    //     current = current->next;
    // }
    // printf("Initial Stack B:\n");
    // current = b;
    // while (current != NULL) 
    // {
    //     printf("%d\n", current->data);
    //     current = current->next;
    // }
    // put_both_top(&a, &b, a1, target);
    // printf("\nAfter put_both_top:\n");

    // printf("Stack A:\n");
    // current = a;
    // while (current != NULL) {
    //     printf("%d\n", current->data);
    //     current = current->next;
    // }

    // printf("Stack B:\n");
    // if (start != NULL)
    // {
        // pa(1, &source, &start);
        // //push(&source, &start);
        // sa (0, &start);
        // rotate (&a1);
        // rotate (&a1);
        // reverse_rotate(&start);
        //sort_3_nodes(&start);
       // t_node *smallest = find_smallest(&start);
        
    // }
    // while (a1 != NULL)
    // {
    //     // printf("%d,b=%p\n",a1->data,b);
    //     t_node *node = set_target_node(&a1, &b);
    //     if (node)    
    //         printf("%d\n", node->data);
    //     else 
    //         printf("no target found.");
    //     a1 = a1 -> next;
    // }
    //set_target_nodes_for_a(&a, &b);
    // while(source != NULL)
    // {
    //     printf("%d\n", source -> data);
    //     source = source-> next;
    // }
    // //printf("%d", smallest -> data);
    // printf("\n\n");
    // while (a2 != NULL)
    // {
    //     printf("%d\n", a2 ->data);
    //     a2  = a2 -> next;
    // }
    // t_node *highest = find_highest (&a);
    // printf("%d", highest -> data);
    // free_linkedlist(a);
    free(b);
    // free_linkedlist(b);
}
// void print_stack(t_node *stack, char stack_name)
// {
//     printf("Stack %c: ", stack_name);
//     while (stack)
//     {
//         printf("%d -> ", stack->data);
//         stack = stack->next;
//     }
//     printf("NULL\n");
// }

// int main(int ac, char **av)
// {
//     t_node *a = create_array(ac, av);
//     t_node *b = NULL;

//     // Before any operation
//     print_stack(a, 'A');
//     print_stack(b, 'B');

//     push_first_2_numbers(&a, &b);

//     // After pushing first 2 numbers
//     print_stack(a, 'A');
//     print_stack(b, 'B');

//     t_node *a1 = a;
//     while (a1)
//     {  
//         t_node *target = set_target_node(a1, &b);
//         int n = calculate_combined_cost(a1, target, &a, &b);
//         printf("Combined cost: %d\n", n);
//         a1 = a1->next;
//     }

//     // Final state
//     print_stack(a, 'A');
//     print_stack(b, 'B');

//     return 0;
// }









// int main(int ac, char **av)
// {
//     t_node *a = create_array(ac, av);
//     t_node *b = NULL;
//     t_node *a1 = a;

//     printf("Initial Stack A:\n");
//     while (a1) {
//         printf("%d\n", a1->data);
//         a1 = a1->next;
//     }

//     t_node *a2 = a;

//     printf("\nInitial Stack B:\n");
//     t_node *current = b;
//     while (current != NULL) {
//         printf("%d\n", current->data);
//         current = current->next;
//     }

//     set_target_nodes_for_a(&a2, &b);

//     return 0;
// }
