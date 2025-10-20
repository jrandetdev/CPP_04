NAME		=	materia
DIR_SRC		=	./src
DIR_BUILD	=	./build
CXX			=	c++
CXXFLAGS	=	-std=c++98 -Wall -Werror -Wextra -pedantic
LDINCLUDE	= -I($DIR_SRC)

SRCS		=	main.cpp \
				AMateria.cpp \
				Cure.cpp \
				Ice.cpp
SRC_NAME	=	$(basename $(SRC))
OBJS		=	$(addsuffix .o, $(addprefix $(DIR_BUILD)/, $(SRC_NAME)))

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) -o $@

$(DIR_BUILD)/%.o: $(DIR_SRC)/%.cpp
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) $(LDINCLUDE) -c $< -o $@

clean:
	@rm -rf $(OBJS)
	@rm -rf $(DIR_BUILD)

fclean:
	@rm -rf $(NAME)

re:
	fclean all

.PHONY: all clean fclean re