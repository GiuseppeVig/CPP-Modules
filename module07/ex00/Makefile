NAME = Polymorphism
CC = c++
FLAGS = -std=c++98 -Wall -Werror -Wextra -g 
SRCS = main.cpp Animal.cpp Dog.cpp Cat.cpp
OBJS = $(SRCS:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)

%.o : %.cpp
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	rm -fr $(OBJS)

fclean: clean
	rm -fr $(NAME)

re: fclean all