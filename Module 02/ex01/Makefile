.PHONY : all clean fclean re

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g

LDFLAGS =

INCLUDE = header.hpp

NAME = FIRST_STEPS_TO_AN_USEFULL_CLASS

SRC = main.cpp \
		Fixed.cpp

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