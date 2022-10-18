# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astaroth </var/spool/mail/astaroth>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/14 20:21:02 by astaroth          #+#    #+#              #
#    Updated: 2022/10/18 18:10:04 by astaroth         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fractol
VERBOSE := TRUE
VPATH := src lib
lib = libftprintf.a
SOURCES	:= ft_atoi.c ft_calloc.c ft_bzero.c ft_isalnum.c \
					ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
					ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
					ft_memset.c ft_strchr.c ft_strdup.c ft_strlcat.c \
					ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c \
					ft_strrchr.c ft_tolower.c ft_toupper.c ft_substr.c \
					ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
					ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
					ft_putendl_fd.c ft_putnbr_fd.c
SOURCES += utils.c events.c init.c main.c parse.c mandelbrot.c
BUILDDIR := ./objs/
INCLUDE := /include
CC := cc
CFLAGS =
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
