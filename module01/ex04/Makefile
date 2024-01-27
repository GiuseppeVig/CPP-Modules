NAME	= Sed
SRCS	= Sed.cpp
OBJS 	= $(SRCS:.c=.o)
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
