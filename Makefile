# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: raida <raida@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/30 18:49:04 by raida             #+#    #+#              #
#    Updated: 2021/07/10 22:16:49 by raida            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

MANDS	=	srcs/ft_printf.c				\
			srcs/ft_printf_utilities.c		\
			srcs/ft_eval.c					\
			srcs/ft_eval_flags.c			\
			srcs/ft_print_chars.c			\
			srcs/ft_print_int.c				\
			srcs/ft_print_unsinged_int.c	\
			srcs/ft_print_hexa_int.c		\
			srcs/ft_print_pointer.c			\
			srcs/ft_print_percent.c			\

BONUS	=	bonus_srcs/ft_printf_bonus.c				\
			bonus_srcs/ft_printf_utilities_bonus.c		\
			bonus_srcs/ft_eval_bonus.c					\
			bonus_srcs/ft_eval_flags_bonus.c			\
			bonus_srcs/ft_print_chars_bonus.c			\
			bonus_srcs/ft_print_int_bonus.c				\
			bonus_srcs/ft_print_unsinged_int_bonus.c	\
			bonus_srcs/ft_print_hexa_int_bonus.c		\
			bonus_srcs/ft_print_pointer_bonus.c			\
			bonus_srcs/ft_print_percent_bonus.c			\

CFLAGS	=	-Wall -Wextra -Werror
MHEADER	=	ft_printf.h
BHEADER	=	ft_printf_bonus.h

MANDS_OBJS =	$(MANDS:.c=.o)
BONUS_OBJS =	$(BONUS:.c=.o)

ifdef WITH_BONUS
OBJS	=	$(MANDS_OBJS) $(BONUS_OBJS)
HEADER	=	$(BHEADER)
else
OBJS = $(MANDS_OBJS)
HEADER = $(MHEADER)
endif

.c.o:
		gcc $(CFLAGS) -c $< -o $(<:.c=.o) -I $(HEADER)
$(NAME):$(OBJS)
		ar rcs $(NAME) $(OBJS)
all:	$(NAME)

clean:
		rm -f $(OBJS) $(BONUS_OBJS)
fclean:	clean
		rm -f $(NAME)
re: fclean all

bonus:
		@$(MAKE) WITH_BONUS=1 all

.PHONY:	all clean fclean re