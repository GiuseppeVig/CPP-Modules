NAME	= UnnecessaryViolence
SRCS	= main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
OBJS 	= $(SRC:.c=.o)
CC 		= c++
FLAGS	= -std=c++98 -Wall -Wextra -Werror

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

all: $(NAME) $(OBJS)

%.o: %.c
		$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
