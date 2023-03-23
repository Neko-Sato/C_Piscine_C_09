CFLAGS = -Wall -Wextra -Werror
NAME = libft.a

SRCS_DIR = ./srcs
INCLUDES_DIR = ./includes

SRCS = \
	$(SRCS_DIR)/ft_putchar.c \
	$(SRCS_DIR)/ft_swap.c \
	$(SRCS_DIR)/ft_putstr.c \
	$(SRCS_DIR)/ft_strlen.c \
	$(SRCS_DIR)/ft_strcmp.c \

OBJECTS = $(SRCS:.c=.o)

$(NAME): $(OBJECTS)
	$(AR) rc $(NAME) $(OBJECTS)
	
.c.o:
	$(CC) -c $(CFLAGS) -I $(INCLUDES_DIR) $< -o $@

clean:
	$(RM) -f $(OBJECTS)

fclean:
	make clean
	$(RM) -f $(NAME)

re:
	make fclean
	make all

all:
	make