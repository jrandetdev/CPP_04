NAME		=	executable
DIR_SRC		=	./
DIR_BUILD	=	./build
RM			=	rm -rf
CXX			=	c++
CXXFLAGS	=	-std=c++98 -g -Wall -Werror -Wextra -pedantic
LDINCLUDE	=	-I$(DIR_SRC)

SRCS		=	main.cpp \
				AMateria.cpp \
				Character.cpp \
				Cure.cpp \
				Ice.cpp \
				Floor.cpp \
				MateriaSource.cpp


SRCS_NAME	=	$(basename $(SRCS))
OBJS		=	$(addsuffix .o, $(addprefix $(DIR_BUILD)/, $(SRCS_NAME)))

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(OBJS) $(CXXFLAGS) -o $@

$(DIR_BUILD)/%.o: $(DIR_SRC)/%.cpp
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) $(LDINCLUDE) -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@$(RM) $(DIR_BUILD)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re