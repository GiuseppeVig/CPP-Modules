NAME = Phonebook
SRCS = Contact.cpp PhoneBook.cpp main.cpp
FLAGS= -std=c++98 -Wall -Wextra -Werror
OBJS 	= $(SRCS:.cpp=.o)
CC = c++


all: $(NAME) 

$(NAME):
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
