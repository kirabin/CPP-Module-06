NAME	=	identify
COMPILER=	clang++
FLAGS	=	-Wall -Wextra #-Werror
SRC		=	identify.cpp Base.cpp
INC		=	A.hpp B.hpp Base.hpp C.hpp
OBJ		=	$(SRC:.cpp=.o)

all: $(NAME)

%.o: %.cpp $(INC)
	$(COMPILER) $(FLAGS) -o $@ -c $<

$(NAME): $(OBJ)
	$(COMPILER) $(FLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f */*.o
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
