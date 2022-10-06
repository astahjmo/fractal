TARGET := fractal
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
SOURCES += utils.c events.c init.c main.c parse.c
BUILDDIR := ./objs/
INCLUDE := ./include
CC := cc
CFLAGS = 
OBJS := $(addprefix $(BUILDDIR), $(SOURCES:.c=.o))

ifdef DEBUG
    CFLAGS += -g3
endif

all:	$(TARGET)

$(TARGET): $(OBJS) $(BUILDDIR)
	$(CC) $(OBJS) $(CFLAGS) $(lib) -lmlx_Linux -Imlx_linux -lXext -lX11 -lm -lz -O3 -o $(TARGET)

$(BUILDDIR)%.o: %.c
	@test -d $(BUILDDIR) || mkdir $(BUILDDIR)
	$(CC) $(CFLAGS) -I$(INCLUDE) -I/usr/include -c $< -o $@

clean:
	rm -rf $(BUILDDIR)

fclean: clean
	rm -f $(TARGET)

re: fclean all
