# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/22 16:31:49 by emmmilla          #+#    #+#              #
#    Updated: 2026/07/22 16:31:54 by emmmilla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a

INCLUDES    = -Iincludes -I$(LIBFT_DIR)

SRC_DIR     = src
OBJ_DIR     = obj
TEST_DIR    = tests

SRCS        = $(wildcard $(SRC_DIR)/*/*.c)
OBJS        = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

DEBUG_SRC   = debug/print_stack.c
PERM_SRC    = $(TEST_DIR)/common/permutation.c

# ---------- production ----------

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# ---------- tests ----------

test_algorithm: $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(DEBUG_SRC) $(PERM_SRC) \
		$(TEST_DIR)/algorithm/main_algorithm.c $(LIBFT) -o main_algorithm

test_small: $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(DEBUG_SRC) $(PERM_SRC) \
		$(TEST_DIR)/algorithm/main_algorithm_small.c $(LIBFT) -o main_small

test_chunk: $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(DEBUG_SRC) \
		$(TEST_DIR)/algorithm/main_chunk.c $(LIBFT) -o main_chunk

test_radix: $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(DEBUG_SRC) \
		$(TEST_DIR)/algorithm/main_radix.c $(LIBFT) -o main_radix

test_insertion: $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(DEBUG_SRC) \
		$(TEST_DIR)/algorithm/main_insertion.c $(LIBFT) -o main_insertion

tests: test_algorithm test_small test_chunk test_radix test_insertion

# ---------- baseline ----------

baseline: test_algorithm
	@echo "Caso   Ops"
	@for c in r8 rev8 r15 r20; do \
		printf "%-6s %s\n" "$$c" "$$(./main_algorithm $$c 2>/dev/null | wc -l)"; \
	done

# ---------- cleanup ----------

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) main_algorithm main_small main_chunk main_radix main_insertion
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re tests baseline \
	test_algorithm test_small test_chunk test_radix test_insertion
