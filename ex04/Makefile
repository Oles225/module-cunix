
CC					:= gcc

RM					:= rm -rf

LDFLAGS			+= -Llib -ggdb

CFLAGS		    	+= -Iinclude -Wall -Wextra -Werror -g

SRCS				:= $(wildcard src/*.c)

OBJS				:= $(SRCS:.c=.o)

NAME				:= atoi_test

all:				$(NAME)

$(NAME):			$(OBJS)
						$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
						$(RM) $(OBJS)

fclean: 			clean
						$(RM) $(NAME)

re: 				fclean all

test:				re
						@(./$(NAME) && echo "Test success" || echo "Test Fails")

debug:              $(NAME)
					valgrind -v --leak-check=full --track-origins=yes ./$(NAME)

