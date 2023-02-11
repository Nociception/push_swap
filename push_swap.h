/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 23:59:07 by nstoutze          #+#    #+#             */
/*   Updated: 2023/02/11 23:59:07 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#  include <stdio.h>
#  include <stdlib.h>

typedef struct  s_move
{
    char	first;
	char	second;
	char	third;
    struct s_move   *next;
    struct s_move   *precedent;
} t_move;

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
    struct s_move   *move;
} t_stack;

typedef struct	s_target
{
	char stack;
	int	index;
	char	location;
	char	destination;
} t_target;

typedef struct s_stacks
{
	struct s_stack *a;
	struct s_stack *b;
} t_stacks;


/*-----Algo length-----*/
void                algo_length(t_stack **a, t_stack **b, t_stack *s, int len);


/*-----Array utils-----*/
int                 *retrieve_data(int len, char *av[]);
void                show_array(int *array, int len);
int                 *copy_array(int *array, int len);
int                 *sort_array(int *array, int len);
int                 index_nb_in_array(int nb, int *array, int len);
int	is_nb_in_array(int nb, int *array, int len_array);


/*-----Extraction-----*/
int	target_in_stack(int target, t_stack *stack);
void	extract_target_ontop(int target, t_stack **a, t_stack **b);


/*-----Index-----*/
void                index_on_s(t_stack *s, int len);
int                 get_nb_index_in_s(int a_nb, t_stack *s);
void                index_on_a(t_stack *a, t_stack *s);
t_stack *get_element_index_in_stack(t_stack *stack, int index);
t_stack	*index_stack(t_stack *a, t_stack *b, int index);
int	index_min_in_stack(t_stack *stack);
int	index_max_in_stack(t_stack *stack);

/*-----Length 3-----*/
void                algo_three(t_stack **a, t_stack *b);

/*-----Length 4-----*/

int sorted_final_stack(t_stack *a);
void	set_sorted_final_stack_ontop(t_stack **a, t_stack *b);
int	sorted_final_stack_ontop(t_stack *a);
int		sorted_stack(t_stack *a);
void	set_sorted_stack_ontop(t_stack **a, t_stack *b);
void	algo_four(t_stack **a, t_stack *b);
int	target_in_stack(int target, t_stack *stack);
int shortest_way_to_target(int target, t_stack *stack);


/*-----Length 5-----*/
void	ra_twice_if_necessary(t_stack **a, t_stack *b);
void	algo_five(t_stack **a, t_stack **b);

/*-----Length 6-----*/
void algo_six(t_stack **a, t_stack **b);
int	peer_in_order(t_stack *a, int x, int y);

/*-----Length under 7-----*/
int direct_neighbors(int x, int y, int len);
//char peer(t_stack *a, t_stack *b, int len);

/*-----Move struct-----*/
void	initialize_move(t_move *move);
t_move *new_struct_move(void);
t_move 		*add_back_move(t_move *move, char f, char s, char t);
void	print_moves(t_stack *a, t_stack *b);


/*-----Neighbors-----*/
int	direct_neighbors(int i, int j, int index_max);
int	both_tops_dneighbors(t_stack *a, t_stack *b);
int	top_second_dneighbors(t_stack *a);
int	top_bottom_dneighbors(t_stack *a);
int	top_second_in_order(t_stack *a);
int	top_bottom_in_order(t_stack *a);
int	both_tops_in_order(t_stack *a, t_stack *b);

/*-----Numbers utils-----*/
int                 ft_atoi(char *s);
int                 len_int(int nb);
void	swap_int(int *x, int *y);
int	abs_val(int n);
int	ft_max(int x, int y);
int	mean_two_positive_numbers(int x, int y);

/*-----Part One-----*/
void    part_one(t_stack **a, t_stack **b, t_stack *s);
void    part_two(t_stack **a, t_stack **b, t_stack *s);


/*-----Printer ABS-----*/
char                *spaces(int nb);
void                show_abs(t_stack *a, t_stack *b, t_stack *s, int len);
//fonction toujours trop longue

/*-----Push-----*/
void	push(t_stack **origin, t_stack **dest);
void	push_a(t_stack **a, t_stack **b);
void	push_b(t_stack **a, t_stack **b);

/*-----Reverse Rotate-----*/
void	reverserotate(t_stack **stack);
void	reverserotate_a(t_stack **a, t_stack *b);
void	reverserotate_b(t_stack *a, t_stack **b);
void	reverserotate_both(t_stack **a, t_stack **b);

/*-----Rotate-----*/
void	rotate(t_stack **stack);
void	rotate_a(t_stack **a, t_stack *b);
void	rotate_b(t_stack *a, t_stack **b);
void	rotate_both(t_stack **a, t_stack **b);

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
void	swap_a(t_stack **a, t_stack *b);
void	swap_b(t_stack *a, t_stack **b);
void	swap_both(t_stack **a, t_stack **b);

/*-----Target Basic Utils-----*/
t_target *new_target(void);
void initialize_target(t_target *target);
void	intel_target(int index, t_target *target, t_stack *a, t_stack *b);
void	show_target_details(t_target *target);
int	stargets_in_b(t_stack *b, int mean_left);
t_target	*best_target(t_stack *a, t_stack *b, int head, int tail);


/*-----Third Algo-----*/
int	only_twelve_first(t_stack *a);
void purge_after_twelve(t_stack **a, t_stack **b);
void    last_purge(t_stack **a, t_stack **b);
void    decrease_indexes(t_stack *a);
void	increase_indexes(t_stack *a);
int	a_sortedfrom_zero_to_eleven(t_stack *a);
void	algo_beyond_seven(t_stack **a, t_stack **b, t_stack *s);

#endif