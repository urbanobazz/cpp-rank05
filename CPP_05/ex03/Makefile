NAME = bureaucrat
CXX = c++
CXXFLAGS  = -Wall -Wextra -Werror -std=c++98 -g #-Wshadow -Wno-shadow
OBJDIR = obj
OBJ = $(SRC:%.cpp=$(OBJDIR)/%.o)
SRC =	Bureaucrat.cpp \
		main.cpp \
		AForm.cpp \
		ShrubberyCreationForm.cpp \
		RobotomyRequestForm.cpp \
		PresidentialPardonForm.cpp \
		Intern.cpp

all: $(NAME)

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(OBJDIR)
	@$(CXX) $(CXXFLAGS) -o $@ -c $< && printf "Compiling: $(notdir $<)\n"

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	@rm -rf $(OBJDIR)
	@-rm *_shrubbery

fclean: clean
	@-rm $(NAME)

re: clean all

.PHONY: all clean fclean re
