NAME	= zombieHorde
SRCS	= Zombie.cpp zombieHorde.cpp main.cpp
CC 		= c++
FLAGS	= -std=c++98 -Wall -Wextra -Werror
OBJS 	= $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

all: $(NAME) $(OBJS)

%.o: %.c
		$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all
