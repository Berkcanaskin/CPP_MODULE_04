NAME	= polymorphism

CC		= c++

FLAGS	= -Wall -Wextra -Werror -std=c++98

RM		= rm -rf

SRC		= main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp

OBJ		= $(SRC:.cpp=.o)

all 	: $(NAME)

clean	:
		$(RM) $(OBJ)

fclean	: clean
		$(RM) $(NAME)

re		: fclean all

$(NAME) :
	$(CC) $(FLAGS) -c $(SRC)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

.PHONY: all clean fclean re