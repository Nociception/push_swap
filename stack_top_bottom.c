#include "push_swap.h"

t_stack *bottom_stack(t_stack *stack)
{
    while (stack && stack->next)
        stack = stack->next;
    return (stack);
}

t_stack *top_stack(t_stack *stack)
{
    while (stack && stack->precedent)
        stack = stack->precedent;
    return (stack);
}
