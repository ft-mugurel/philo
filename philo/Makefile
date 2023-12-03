NAME = philo
CC = gcc
RM = rm -rf
CFLAGS = -Wall -Werror -Wextra -pthread 

SRCS = main.c check_print.c eat_sleep_think.c  creat_free.c utils.c

FLAGS_DATARACE = -g -fsanitize=thread

RED=\033[31m
YELLOW=\033[33m
GREEN=\033[32m
CYAN=\033[36m
BLUE=\033[34m
MAGENTA=\033[35m
RESET=\033[0m

all: title  $(NAME)

$(NAME): $(SRCS)
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME)
	@rm -rf *.dSYM

title:
	@clear
	@echo "$(RED)    ____  __    _ __                       __                  ";
	@echo "   / __ \/ /_  (_) /___  _________  ____  / /_  ___  __________";
	@echo "  / /_/ / __ \/ / / __ \/ ___/ __ \/ __ \/ __ \/ _ \/ ___/ ___/";
	@echo " / ____/ / / / / / /_/ (__  ) /_/ / /_/ / / / /  __/ /  (__  ) ";
	@echo "/_/   /_/ /_/_/_/\____/____/\____/ .___/_/ /_/\___/_/  /____/  ";
	@echo "                                /_/                            $(CYAN)By mugurel$(RESET)";
	@echo "";
	@echo "";	

tittle:
	@clear
	@echo "$(GREEN)****** Cleaned ******$(RESET)"
data_race:
	@$(CC) $(FLAGS_DATARACE) $(CFLAGS) $(SRCS) -o $(NAME)	

clean:
	@$(RM) $(NAME) *.dSYM

fclean: tittle clean
	@$(RM) $(NAME) 

re: fclean all

.PHONY: all clean fclean re