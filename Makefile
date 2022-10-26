# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/26 15:21:29 by johmatos          #+#    #+#              #
#    Updated: 2022/10/26 15:21:36 by johmatos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fractol
VERBOSE := TRUE
VPATH := src lib
SOURCES	:= ft_atoi.c ft_calloc.c ft_bzero.c ft_isalnum.c \
		ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
		ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
		ft_memset.c ft_strchr.c ft_strdup.c ft_strlcat.c \
		ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c \
		ft_strrchr.c ft_tolower.c ft_toupper.c ft_substr.c \
		ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
		ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c ft_atof.c
SOURCES	+= utils.c events.c init.c main.c parse.c mandelbrot.c julia.c exit.c


BUILDDIR := ./objs/
INCLUDE := /include
CC := cc
CFLAGS = -Wall -Werror -Wextra -o3
OBJS := $(addprefix $(BUILDDIR), $(SOURCES:.c=.o))

ifdef DEBUG
    CFLAGS += -g3
endif

all:	$(NAME)

$(NAME): $(OBJS) $(BUILDDIR)
	$(CC) $(OBJS) -I$(INCLUDE) -Lminilibx-linux -lmlx -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
$(BUILDDIR)%.o: %.c
	@test -d $(BUILDDIR) || mkdir $(BUILDDIR)
	$(CC) $(CFLAGS) -I./include -c $< -o $@

clean:
	rm -rf $(BUILDDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
