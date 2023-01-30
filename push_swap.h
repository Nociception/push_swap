#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#  include <stdio.h>
#  include <stdlib.h>

typedef struct  s_stack
{
    int             nb;
    int             index;
    int             index_max;
    int             initial_index_max;
    int             spaces;
	char			a_or_b;
    struct s_stack  *precedent;
    struct s_stack  *next;
} t_stack;

/*-----Algo length-----*/
void                algo_length(t_stack **A, t_stack **B, int len);


/*-----Array utils-----*/
int                 *retrieve_data(int len, char *av[]);
void                show_array(int *array, int len);
int                 *copy_array(int *array, int len);
int                 *sort_array(int *array, int len);
int                 index_nb_in_array(int nb, int *array, int len);

/*-----Index-----*/
void                index_on_S(t_stack *S, int len);
int                 get_nb_index_in_S(int Anb, t_stack *S);
void                index_on_A(t_stack *A, t_stack *S);

/*-----Length 3-----*/
void                algo_three(t_stack **A);

/*-----Length 4-----*/

int sorted_final_stack(t_stack *A);
void	set_sorted_final_stack_ontop(t_stack **A);
int	sorted_final_stack_ontop(t_stack *A);
int		sorted_stack(t_stack *A);
void	set_sorted_stack_ontop(t_stack **A);
void	algo_four(t_stack **A);
int	target_in_stack(int target, t_stack *stack);
int shortest_way_to_target(int target, t_stack *stack);
void	extract_target_ontop(int target, t_stack **stack);


/*-----Length 5-----*/
void	ra_twice_if_necessary(t_stack **A);
void	algo_five(t_stack **A, t_stack **B);

/*-----Length under 7-----*/
int are_directneighbors(int x, int y, int len);
//char peer(t_stack *A, t_stack *B, int len);

/*-----Neighbors-----*/
int	direct_neighbors(int i, int j, int index_max);
int	both_tops_dneighbors(t_stack *A, t_stack *B);
int	top_second_dneighbors(t_stack *A);
int	top_bottom_dneighbors(t_stack *A);
int	top_second_in_order(t_stack *A);
int	top_bottom_in_order(t_stack *A);
int	both_tops_in_order(t_stack *A, t_stack *B);

/*-----Numbers utils-----*/
int                 ft_atoi(char *s);
int                 len_int(int nb);
void	swap_int(int *x, int *y);
int	abs_value(int n);



/*-----Printer ABS-----*/
char                *spaces(int nb);
void                showABS(t_stack *A, t_stack *B, t_stack *S, int len);
//fonction toujours trop longue

/*-----Push-----*/
void	push(t_stack **origin, t_stack **dest);
void	push_a(t_stack **A, t_stack **B);
void	push_b(t_stack **A, t_stack **B);

/*-----Reverse Rotate-----*/
void	reverserotate(t_stack **stack);
void	reverserotate_a(t_stack **A);
void	reverserotate_b(t_stack **B);
void	reverserotate_both(t_stack **A, t_stack **B);

/*-----Rotate-----*/
void	rotate(t_stack **stack);
void	rotate_a(t_stack **A);
void	rotate_b(t_stack **B);
void	rotate_both(t_stack **A, t_stack **B);

/*-----Stack basic utils-----*/
t_stack             *new_stack_element(void);
void                initialize_stack_element(t_stack *element);
t_stack             *add_front(t_stack *stack, int nb);
void                show_stack(t_stack *stack);
t_stack             *array_to_stack(int *array, int len);
int                 len_stack(t_stack *stack);

/*-----Stack details-----*/
void                add_stack_backlinks(t_stack *stack);
void                show_stack_details(t_stack *stack);

/*-----Stack top bottom-----*/
t_stack *bottom_stack(t_stack *stack);
t_stack *top_stack(t_stack *stack);

/*-----Swap-----*/
void	swap(t_stack **stack);
void	swap_a(t_stack **A);
void	swap_b(t_stack **B);
void	swap_both(t_stack **A, t_stack **B);

#endif