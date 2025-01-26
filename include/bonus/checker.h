/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:07:00 by nstoutze          #+#    #+#             */
/*   Updated: 2023/03/02 19:26:11 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"

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

void	push(t_stack **origin, t_stack **dest);
void	push_a(t_stack **a, t_stack **b);
void	push_b(t_stack **a, t_stack **b);
void	swap(t_stack **stack);
void	swap_a(t_stack **a);
void	swap_b(t_stack **b);
void	swap_both(t_stack **a, t_stack **b);
void	rotate(t_stack **stack);
void	rotate_a(t_stack **a);
void	rotate_b(t_stack **b);
void	rotate_both(t_stack **a, t_stack **b);
void	reverserotate(t_stack **stack);
void	reverserotate_a(t_stack **a);
void	reverserotate_b(t_stack **b);
void	reverserotate_both(t_stack **a, t_stack **b);

t_stack	*top_stack(t_stack *stack);
t_stack	*bottom_stack(t_stack *stack);
int		len_stack(t_stack *stack);
void	add_stack_backlinks(t_stack *stack);
t_stack	*array_to_stack(int *array, int len);
int		*sort_array(int *array, int len);

void	janitor(void *dust);
void	stack_janitor(t_stack **a, t_stack **b, t_stack **s);
void	ft_error(char *str);
void	feed_stacks(int len, char *av[], t_stack **a, t_stack **s);

int		sorted_final_stack(t_stack *a);
int		sorted_final_stack_ontop(t_stack *a);

int		valid_data(int len, char *av[]);
int		are_numbers_unique(int *array, int len);
int		ft_atoi_push_swap(char *s);
int		*fill_array_with_valid_data(int len, char *av[]);

void	swap_int(int *x, int *y);

int		get_nb_index_in_s(int a_nb, t_stack *s);
int		target_in_stack(int target, t_stack *stack);
t_stack	*get_element_index_in_stack(t_stack *stack, int index);
void	extract_target_ontop(int target, t_stack **a, t_stack **b);

void	index_on_a(t_stack *a, t_stack *s);
void	index_on_s(t_stack *s, int len);

#endif