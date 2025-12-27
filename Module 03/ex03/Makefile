.PHONY : all clean fclean re

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g

LDFLAGS =

INCLUDE = header.hpp

NAME = Now_it_s_weird

SRC = main.cpp \
		ClapTrap.cpp \
		ScavTrap.cpp \
		FragTrap.cpp \
		DiamondTrap.cpp

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
