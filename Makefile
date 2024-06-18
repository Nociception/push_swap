# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/26 21:33:49 by tmongell          #+#    #+#              #
#    Updated: 2024/06/18 01:55:18 by nstoutze         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = push_swap

SRC = direct_neighbors/both_tops_dneighbors.c \
	  direct_neighbors/direct_neighbors.c \
	  direct_neighbors/second_second_ms_dneighbors.c \
	  direct_neighbors/top_bottom_dneighbors.c \
	  direct_neighbors/top_second_dneighbors.c \
	  direct_neighbors/top_second_ms_dneighbors.c \
	  index/get_element_index_in_stack.c \
	  index/get_nb_index_in_s.c \
	  index/index_max_in_stack.c \
	  index/index_min_in_stack.c \
	  index/index_on_a.c \
	  index/index_on_s.c \
	  index/index_stack.c \
	  little_length/final_stack.c \
	  little_length/length_five.c \
	  little_length/length_four.c \
	  little_length/length_six.c \
	  little_length/length_three.c \
	  little_length/peer.c \
	  part_one/last_purge.c \
	  part_one/only_six_seven_eight.c \
	  part_one/only_three_to_eight.c \
	  part_one/only_twelve_first.c \
	  part_one/part_one.c \
	  part_one/presort.c \
	  part_one/purge_after_twelve.c \
	  part_one/set_part_value.c \
	  part_one/six_seven_eight.c \
	  part_one/zero_to_five.c \
	  part_two/best_priority_choice.c \
	  part_two/harvest_score.c \
	  part_two/plug_priority.c \
	  part_two/define_threshold.c \
	  part_two/initialize_priority.c \
	  part_two/which_stack.c \
	  part_two/extraction_best_choice.c \
	  part_two/part_two.c \
	  stack/stack_basic_utils.c \
	  stack/stack_details.c \
	  stack/stack_top_bottom.c \
	  target/position_target_in_stack.c \
	  target/stargets_in_b.c \
	  ps_moves/reverse_rotate.c \
	  ps_moves/rotate.c \
	  ps_moves/push.c \
	  ps_moves/swap.c \
	  parse_and_get_data/feed_stacks.c \
	  parse_and_get_data/retrieve_data.c \
	  parse_and_get_data/valid_data.c \
	  parse_and_get_data/ft_atoi_push_swap.c \
      others/length_beyond_seven.c \
	  others/algo_length.c \
	  others/numbers_utils.c \
	  others/array_utils.c \
	  others/extraction.c \
	  others/in_order.c \
	  others/range_in_stack.c \
	  others/ft_error.c \
	  others/janitor.c \
	  push_swap.c \

BNAME = checker

BSRC = bonus/checker.c \
	   bonus/stack_details_bonus.c \
	   bonus/stack_basic_utils_bonus.c \
	   bonus/stack_top_bottom_bonus.c \
	   bonus/index_on_a_bonus.c \
	   bonus/index_on_s_bonus.c \
	   bonus/get_nb_index_in_s_bonus.c \
	   bonus/index_stack_bonus.c \
	   bonus/get_element_index_in_stack_bonus.c \
	   bonus/final_stack_bonus.c \
	   bonus/array_utils_bonus.c \
	   bonus/retrieve_data_bonus.c \
	   bonus/ft_atoi_push_swap_bonus.c \
	   bonus/numbers_utils_bonus.c \
	   bonus/valid_data_bonus.c \
	   bonus/swap_bonus.c \
	   bonus/push_bonus.c \
	   bonus/rotate_bonus.c \
	   bonus/reverse_rotate_bonus.c \
	   bonus/extraction_bonus.c \
	   bonus/feed_stacks_bonus.c \
	   bonus/ft_error_bonus.c \
	   bonus/janitor_bonus.c \

OBJ = $(SRC:.c=.o)

BOBJ = $(BSRC:.c=.o)

LIBFT = ./libft

LIBS = $(LIBFT)/libft.a

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

mandatory : $(NAME)

bonus :
	@make all
	@make $(BNAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)
	@echo project compiled

$(BNAME): $(BOBJ)
	@$(CC) $(CFLAGS) $(BOBJ) $(LIBS) -o $(BNAME)
	@echo bonus compiled

%.o:%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "compiling : $<                        \r"

clean :
	@rm -rf $(OBJ) $(BOBJ)
	@echo object files removed
	@make -C $(LIBFT) clean
	@echo printf cleaned

fclean : clean
	@rm -rf $(NAME) $(BNAME)
	@echo executable removed
	@make -C $(LIBFT) fclean

re : fclean all

.PHONY:	all bonus mandatory $(NAME) clean fclean re
