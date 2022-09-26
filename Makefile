NAME	= fractal
VPATH 	= src
SRCS	= utils.c events.c init.c main.c mandelbrot.c
ODIR	= ./objs/
INCLUDE	= ./include
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
OBJS 	= $(addprefix $(ODIR), $(SRCS:.c=.o))

ifdef DEBUG
    CFLAGS += -g3
endif

all:	$(NAME)

$(NAME): $(ODIR) $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -lmlx_Linux -Imlx_linux -lXext -lX11 -lm -lz -O3 -o $(NAME)
$(ODIR)%.o: %.c
	@$(CC) $(CFLAGS) -I$(INCLUDE) -I/usr/include -c $< -o $@

$(ODIR):
	@test -d $(ODIR) || mkdir $(ODIR)

clean:
	@rm -rf $(ODIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all
