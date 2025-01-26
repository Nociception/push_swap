/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:10:33 by nstoutze          #+#    #+#             */
/*   Updated: 2023/02/23 15:10:33 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	int				nb;
	int				index;
	int				index_max;
	int				spaces;
	char			a_or_b;
	struct s_stack	*precedent;
	struct s_stack	*next;
	struct s_move	*move;
}	t_stack;

int		both_tops_dneighbors(t_stack *a, t_stack *b);
int		direct_neighbors(int i, int j, int index_max);
int		second_second_ms_dneighbors(t_stack *a, t_stack *b);
int		top_bottom_dneighbors(t_stack *a);
int		top_second_dneighbors(t_stack *a);
int		top_second_ms_dneighbors(t_stack *a, t_stack *b);
void	moves_tt_dneighbors(t_stack **a, t_stack **b);
void	moves_ts_direct_neighbors(t_stack **a, t_stack *b);
void	moves_tb_direct_neighbors(t_stack **a);
void	moves_ts_ms_dneighbors(t_stack **b);
void	moves_ss_ms_dneighbors(t_stack **a, t_stack **b);

t_stack	*get_element_index_in_stack(t_stack *stack, int index);
int		get_nb_index_in_s(int a_nb, t_stack *s);
int		index_max_in_stack(t_stack *stack);
int		index_min_in_stack(t_stack *stack);
void	index_on_a(t_stack *a, t_stack *s);
void	index_on_s(t_stack *s, int len);
t_stack	*index_stack(t_stack *a, t_stack *b, int index);

int		sorted_final_stack(t_stack *a);
void	set_sorted_final_stack_ontop(t_stack **a, t_stack *b);
int		sorted_final_stack_ontop(t_stack *a);

void	ra_twice_if_necessary(t_stack **a);
void	algo_five(t_stack **a, t_stack **b);
void	algo_four(t_stack **a, t_stack *b);
void	third_fct(t_stack **first, t_stack **second, t_stack **third);
void	algo_six(t_stack **a, t_stack **b);
void	algo_three(t_stack **a);
int		peer_in_order(t_stack *a, int x, int y);
int		peer_peer_peer(t_stack *a);
void	moves_ppp(t_stack **a, t_stack **b);

t_stack	*new_stack_element(void);
t_stack	*add_front(t_stack *stack, int nb);
t_stack	*array_to_stack(int *array, int len);
int		len_stack(t_stack *stack);
int		pos_index_in_stack(int index, t_stack *stack);
void	add_stack_backlinks(t_stack *stack);
t_stack	*bottom_stack(t_stack *stack);
t_stack	*top_stack(t_stack *stack);

int		position_target_in_stack(int target, t_stack *stack);
int		stargets_in_b(t_stack *b, int mean_left);
int		shortest_way_to_target(int target, t_stack *stack);
void	extraction(int nb_rotate, t_stack **a, t_stack **b, char stack);
void	extract_target_ontop(int target, t_stack **a, t_stack **b);
int		target_in_stack(int target, t_stack *stack);

void	algo_length(t_stack **a, t_stack **b, t_stack *s, int len);
int		are_numbers_unique(int *array, int len);
int		*copy_array(int *array, int len);
int		*sort_array(int *array, int len);
int		index_nb_in_array(int nb, int *array, int len);
int		is_nb_in_array(int nb, int *array, int len_array);

int		both_tops_in_order(t_stack *a, t_stack *b);
int		top_second_in_order(t_stack *a);
int		top_bottom_in_order(t_stack *a);

void	algo_beyond_seven(t_stack **a, t_stack **b, t_stack *s);

int		abs_val(int n);
void	swap_int(int *x, int *y);
int		ft_max(int x, int y);
int		mean_two_positive_numbers(int x, int y);

int		only_twelve_first(t_stack *a);
void	purge_after_twelve(t_stack **a, t_stack **b);
int		only_three_to_eight(t_stack *a);
int		only_six_seven_eight(t_stack *a);
void	last_purge(t_stack **a, t_stack **b);
void	six_seven_eight(t_stack **a);
void	zero_to_five(t_stack **a, t_stack **b);
void	presort(t_stack **a, t_stack **b, int min, int max);
void	part_one(t_stack **a, t_stack **b);

void	initialize_priority(int *priority, t_stack *a, t_stack *b);
int		define_threshold(t_stack *b, int index_max);
t_stack	*which_stack(int target, t_stack *a, t_stack *b);
int		harvest_score(t_stack *stack, int target, int threshold);
int		best_priority_choice(t_stack *a, t_stack *b, int *priority, int thr);
void	extraction_best_choice(int bc, t_stack **a, t_stack **b, int threshold);
int		range_in_stack(t_stack *stack, int min, int max);
void	plug_priority(t_stack **a, t_stack **b, int *priority, int *threshold);
void	set_part_value(t_stack *a, int *part);
void	part_two(t_stack **a, t_stack **b, t_stack *s);

void	push(t_stack **origin, t_stack **dest);
void	push_a(t_stack **a, t_stack **b);
void	push_b(t_stack **a, t_stack **b);
void	reverserotate(t_stack **stack);
void	reverserotate_a(t_stack **a);
void	reverserotate_b(t_stack **b);
void	reverserotate_both(t_stack **a, t_stack **b);
void	real_rotate(t_stack **top, t_stack **second, t_stack **bottom);
void	rotate(t_stack **stack);
void	rotate_a(t_stack **a);
void	rotate_b(t_stack **b);
void	rotate_both(t_stack **a, t_stack **b);
void	swap(t_stack **stack);
void	swap_a(t_stack **a);
void	swap_b(t_stack **b);
void	swap_both(t_stack **a, t_stack **b);

int		ft_atoi_push_swap(char *s);
int		simple_atoi(char *s);
int		valid_data(int len, char *av[]);
int		*fill_array_with_valid_data(int len, char *av[]);
void	feed_stacks(int len, char *av[], t_stack **a, t_stack **s);

void	janitor(void *dust);
void	stack_janitor(t_stack **a, t_stack **b, t_stack **s);
void	ft_error(char *str);

#endif
/*
typedef struct s_move
{
	char			first;
	char			second;
	char			third;
	struct s_move	*next;
	struct s_move	*precedent;
}	t_move;
t_move	*new_struct_move(void);
t_move	*bottom_move(t_move *move);
t_move	*top_move(t_move *move);
t_move	*add_back_move(t_move *move, char first, char second, char third);
void	show_stack_details(t_stack *stack);
void	show_stack(t_stack *stack);
void	show_abs(t_stack *a, t_stack *b, t_stack *s, int len);

void	del_first_move(t_move **move);
void	del_last_move(t_move **move);
void	del_middle_move(t_move **move);
void	del_elt_in_moves(t_move **move, int index);
char	*spaces(int nb);
void	show_array(int *array, int len);
int		len_int(int nb);
void	print_moves(t_stack *a, t_stack *b);
int		nb_moves(t_move *move);
t_move	*new_struct_move(void)
{
	t_move	*move;

	move = malloc(sizeof(*move));
	if (!move)
		return (NULL);
	move->first = ' ';
	move->second = ' ';
	move->third = ' ';
	move->precedent = NULL;
	move->next = NULL;
	return (move);
}

t_move	*bottom_move(t_move *move)
{
	while (move->next)
		move = move->next;
	return (move);
}

t_move	*top_move(t_move *move)
{
	while (move)
		move = move->precedent;
	return (move);
}

t_move	*add_back_move(t_move *move, char first, char second, char third)
{
	t_move	*new_move;

	new_move = new_struct_move();
	new_move->first = first;
	new_move->second = second;
	new_move->third = third;
	new_move->next = move;
	move = bottom_move(move);
	move->next = new_move;
	new_move->precedent = move;
	new_move->next = NULL;
	return (move);
}
void	print_moves(t_stack *a, t_stack *b)
{
	t_stack	*index_zero;
	t_move	*moves;
	int		n;

	printf("print_moves : Entree\n");
	index_zero = index_stack(a, b, 0);
	moves = index_zero->move;
	//printf("Here are the raw moves :\n");
	n = 0;
	while (moves)
	{
		//printf("print_moves(boucle) : debut iteration\n");
		printf("%c", moves->first);
		printf("%c", moves->second);
		if (moves->third != ' ')
			printf("%c", moves->third);
		printf("\n");
		moves = moves->next;
		n++;
	}
	printf("print_moves DONE ; %d moves\n", n-1);
}

int	nb_moves(t_move *move)
{
	int	nb;

	nb = 0;
	while (move)
	{
		nb++;
		move = move->next;
	}
	return (nb);
}
*/