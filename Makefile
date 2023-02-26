# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmongell <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/26 21:33:49 by tmongell          #+#    #+#              #
#    Updated: 2023/02/26 21:33:51 by tmongell         ###   ########.fr        #
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
      length_beyond_seven.c \
	  push_swap.c \
	  move_struct.c \
	  algo_length.c \
	  numbers_utils.c \
	  retrieve_data.c \
	  array_utils.c \
	  reverse_rotate.c \
	  rotate.c \
	  extraction.c \
	  ft_atoi_push_swap.c \
	  swap.c \
	  in_order.c \
	  push.c \
	  range_in_stack.c \
	  valid_data.c \

OBJ = $(SRC:.c=.o)

LIBFT = ./libft

LIBS = $(LIBFT)/libft.a $(LIBFT)/ft_printf/libftprintf.a

CFLAGS = -Wall -Wextra -Werror

BDIR = ./bonus/

all : $(NAME) bonus

bonus :
	make -C $(BDIR)

mandatory : $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)
	@echo project compiled

%.o:%.c
	@$(CC) $(FCLAGS) -c $< -o $@
	@printf "compiling : $<                        \r"

clean :
	@rm -rf $(OBJ)
	@echo object files removed
	@make -C $(LIBFT) clean
	@echo printf cleaned

fclean : clean
	@rm -rf $(NAME)
	@echo executable removed
	@make -C $(LIBFT) fclean

re : fclean all

.PHONY:	all bonus mandatory $(NAME) clean fclean re
