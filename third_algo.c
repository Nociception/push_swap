#include "push_swap.h"

int first_intruder_among_initial_stack(t_stack *A)
{
    int position;
    if (*A)
    {
        A = top_stack(A);
        while (*A)
        {
            if (A->index > 11)
                return (shortest_way_to_target(A->index, A));
            A = A->next;
        }
    }
    return (42000);
}

void first_or_second_half_on_B(t_stack **B)
{
    if (*B && (*B)->next)
    {
        *B = top_stack(*B);
        if ((*B)->index > ((*B)->initial_index_max - 12) / 2)
            rotate_b(B);
    }
}

void    purge_after_twelve(t_stack **A, t_stack **B)
{
    int intruder;

    intruder = first_intruder_among_first_twelve(*A);
    if (*A && *B)
    {
        while (intruder != 42000)
        {
            intruder = first_intruder_among_first_twelve(*A);
            extract_target_ontop(intruder, A);
            push_b(A, B);
            first_or_second_half_on_B(B);
        }
    }
}

void    soft_six_sorting(t_stack **A, t_stack **B)
{
    //objectif principal : purger les 3 précédents et suivants sur B
    //objectif secondaire opportuniste : swap deux nb faisant partie des 6 si nécessaire
}

void    decrease_indexes(t_stack *A)
{
    //les 6 voient leur index respectifs réduits de 1, et leur index max ajusté à 6 (ou 5, ou 7 je ne sais plus)
}

void    increase_indexes(t_stack *A)
{

}

void    six_lucky(t_stack **A, t_stack **B)
{

}

void    part_one(t_stack **A, t_stack **B)
{
    purge_after_twelve(A, B);
    soft_six_sorting(A, B);
    decrease_indexes(*A);
    algo_six(A, B);
    increase_indexes(*A);
    six_lucky(A, B);
}

int *initialize_priority(int *priority, t_stack *B)
{

}


int *initialize_secondary(int *secondary, t_stack *B)
{

}

int priority_empty(int *priority)
{

}

void    lists_update_part_two(int *prio[], int *sec[], t_stack *A, t_stack *B)
{

}

void    part_two(t_stack **A, t_stack **B, int *priority, int)
{
    int priority[3];
    int *secondary;
    int best_choice;

    initialize_priority(priority, *B);
    initialize_secondary(secondary,*B);
    while (!priority_empty(priority))
    {
        best_choice = best_priority_choice(priority, secondary, *A, *B);
        extract_priority_ontop(best_choice, secondary, A, B);
        send_and_plug_priority(best_choice, A, B);
        lists_update_part_two
        (&priority, &secondary, *A, *B);
    }
}

void    part_three(t_stack **A, t_stack **B)
{

}

void    part_four(t_stack **A, t_stack **B)
{

}

void    part_five(t_stack **A, t_stack **B)
{

}

void    algo_beyond_seven(t_stack **A, t_stack **B)
{
    while (!sorted_final_stack(*A))
    {
        part_one(A, B);
        part_two(A, B);
        part_three(A, B);
        part_four(A, B);
        part_five(A, B);
    }
}