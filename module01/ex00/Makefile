NAME	= Zombie
FLAGS	= -std=c++98 -Wall -Wextra -Werror
SRC	= main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
OBJS 	= $(SRC:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

all: $(NAME) $(OBJS)

%.o: %.c
		$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all
