# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aistok <aistok@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/29 20:26:54 by aistok            #+#    #+#              #
#    Updated: 2024/08/06 11:17:09 by aistok           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB_DIR		= ./lib
OBJS_DIR	= ./obj

NAME = $(addprefix $(LIB_DIR)/, libft.a)

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

FILES =		ft_atoi \
		ft_bzero \
		ft_calloc \
		ft_isalnum \
		ft_isalpha \
		ft_isascii \
		ft_isdigit \
		ft_isprint \
		ft_itoa \
		ft_memchr \
		ft_memcmp \
		ft_memcpy \
		ft_memmove \
		ft_memset \
		ft_putchar_fd \
		ft_putendl_fd \
		ft_putnbr_fd \
		ft_putstr_fd \
		ft_split \
		ft_strchr \
		ft_strdup \
		ft_striteri \
		ft_strjoin \
		ft_strlcat \
		ft_strlcpy \
		ft_strlen \
		ft_strmapi \
		ft_strncmp \
		ft_strnstr \
		ft_strrchr \
		ft_strtrim \
		ft_substr \
		ft_tolower \
		ft_toupper \
		ft_libft_version

FILES_B =	ft_lstadd_back_bonus \
		ft_lstadd_front_bonus \
		ft_lstclear_bonus \
		ft_lstdelone_bonus \
		ft_lstiter_bonus \
		ft_lstlast_bonus \
		ft_lstmap_bonus \
		ft_lstnew_bonus \
		ft_lstsize_bonus

SRCS_DIR = .
SRCS = $(addprefix $(SRCS_DIR)/, $(addsuffix .c, $(FILES)))
SRCS_B = $(addprefix $(SRCS_DIR)/, $(addsuffix .c, $(FILES_B)))

OBJS = $(addprefix $(OBJS_DIR)/, $(addsuffix .o, $(FILES)))
OBJS_B = $(addprefix $(OBJS_DIR)/, $(addsuffix .o, $(FILES_B)))

FILES_FT_PRINTF =	ft_printf.c \
			ft_printf_utils.c \
			ft_printf_char.c \
			ft_printf_nbr.c \
			ft_printf_hex.c \
			ft_printf_ptr.c \
			ft_printf_str.c

SRCS_FTPF = $(addprefix $(SRCS_DIR)/, $(FILES_FT_PRINTF))
OBJS_FTPF = $(addprefix $(OBJS_DIR)/, $(FILES_FT_PRINTF:.c=.o)) 

FILES_GNL_BONUS	=	get_next_line_bonus.c \
			get_next_line_utils_bonus.c

SRCS_GNL_BONUS	= $(addprefix $(SRCS_DIR)/, $(FILES_GNL_BONUS))
OBJS_GNL_BONUS	= $(addprefix $(OBJS_DIR)/, $(FILES_GNL_BONUS:.c=.o))

$(OBJS_DIR)/%.o: %.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# this is now replaced by the bonus rule, so that everything is added to
# the libft.a file
#$(NAME): $(OBJS) $(OBJS_FTPF) $(OBJS_GNL_BONUS) | $(LIB_DIR)
#	$(AR) $@ $^
#$(NAME): bonus
# with $(NAME): bonus, the project gor re-archived every time make was
# executed!!! NOT GOOD! "make" only needs to act, if there was some change
# int the dependency files?!?!!!!!
$(NAME): $(OBJS) $(OBJS_B) $(OBJS_FTPF) $(OBJS_GNL_BONUS) | $(LIB_DIR)
	$(AR) $(NAME) $^

$(LIB_DIR):
	mkdir -p $(LIB_DIR)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

all: $(NAME)
#all: bonus

# bonus rule de-activated, since it archived the project each time it was
# called!!! Which is not desirable!
#bonus: $(OBJS) $(OBJS_B) $(OBJS_FTPF) $(OBJS_GNL_BONUS) | $(LIB_DIR)
#	$(AR) $(NAME) $^

clean:
	$(RM) $(OBJS) $(OBJS_B) $(OBJS_FTPF) $(OBJS_GNL_BONUS)
	rm -rf $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME) $(TEST_SO)
	rm -rf $(LIB_DIR)

re: fclean all

TEST_SO = libft.so
# this rule is required by the unit-tester (by inyancat)
# https://github.com/alelievr/libft-unit-test
so:
	gcc -fPIC -shared -o $(TEST_SO) $(SRCS) $(SRCS_B)

#.PHONY: all bonus clean fclean re so
.PHONY: all clean fclean re so
