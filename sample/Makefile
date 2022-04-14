NAME		= mystr

INC_DIR		= ./
SRC_DIR		= ./
SRC_NAME	= MyString.cpp \
			  main.cpp
SRCS		= $(addprefix $(SRC_DIR), $(SRC_NAME))
OBJS		= $(SRCS:.cpp=.o)

CC			= g++
CFLAGS		= -std=c++98
ifdef LEAK
	CFLAGS	+= -g -fsanitize=leak
endif

RM			= rm -f

.cpp.o:
			$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $(<:.cpp=.o)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

leak:
			@make fclean
			@make LEAK=1
clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

.PHONY:		leak clean clean fclean