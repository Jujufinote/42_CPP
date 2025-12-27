.PHONY : all clean fclean re

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g

LDFLAGS =

INCLUDE = header.hpp

NAME = At_least_this_beats_coffee-making

SRC = main.cpp \
		Bureaucrat.cpp \
		AForm.cpp \
		ShrubberyCreationForm.cpp \
		RobotomyRequestForm.cpp \
		PresidentialPardonForm.cpp \
		Intern.cpp

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
