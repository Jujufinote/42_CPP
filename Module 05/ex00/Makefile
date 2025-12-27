.PHONY : all clean fclean re

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g

LDFLAGS =

INCLUDE = header.hpp

NAME = Mommy_when_I_grow_up_I_want_to_be_a_bureaucrat

SRC = main.cpp \
		Bureaucrat.cpp

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
