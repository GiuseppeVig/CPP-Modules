NAME	= Harl
SRCS	= Harl.cpp main.cpp
OBJS 	= $(SRC:.c=.o)
CC 		= c++
FLAGS	= -std=c++98 -Wall -Wextra -Werror

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

all: $(NAME) $(OBJS)

%.o: %.c
		$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all
