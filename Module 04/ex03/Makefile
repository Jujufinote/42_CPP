.PHONY : all clean fclean re

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g

LDFLAGS =

INCLUDE = header.hpp

NAME = Interface_and_recap

SRC = main.cpp \
	AMateria.cpp \
	Character.cpp \
	Cure.cpp \
	Ice.cpp \
	MateriaSource.cpp \
	Ground.cpp

OBJ = ${SRC:.cpp=.o}

%.o : %.c
	c++ $(CFLAGS) $(INCLUDE) -c %< -o %@

$(NAME) : $(OBJ)
	c++ $(CFLAGS) $(OBJ) $(LDFLAGS) -o $(NAME)

all : $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
