# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hpehliva <hpehliva@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/12 09:35:53 by hpehliva          #+#    #+#              #
#    Updated: 2025/06/18 15:44:23 by hpehliva         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out

CXX = c++

CXXFLAG = -Wall -Wextra -Werror -std=c++98

SRCS= main.cpp Fixed.cpp bsp.cpp Point.cpp

OBJ = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAG) $(OBJ) -o $(NAME)

%.o:%.cpp
	$(CXX) $(CXXFLAG) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all 

.PHONY: all clean fclean re