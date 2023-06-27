CC = gcc
CFLAGS = -Wall -Wextra -g

SRCS = cheack_arg.c error.c philosophers.c utils.c value_arg.c
OBJS = $(SRCS:.c=.o)
TARGET = philosophers

# Colors for terminal output
RED = \033[0;31m
BLUE = \033[0;34m
GOLD = \033[0;33m
NC = \033[0m

# Line styles for terminal output
LINE_STYLE = \033[1;4m
LINE_RESET = \033[0m


all: $(TARGET)

$(TARGET): $(OBJS)
	@echo "$(BLUE)$(LINE_STYLE)Linking object files:$(LINE_RESET)$(NC)"
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "$(GOLD)Build complete!$(NC)"

%.o: %.c philo.h
	@echo "$(RED)$(LINE_STYLE)Compiling: $<$(LINE_RESET)$(NC)"
	@$(CC) $(CFLAGS) -c $< -o $@ && echo "$(GOLD)Compiled: $<$(NC)"

clean:
	@echo "$(BLUE)$(LINE_STYLE)Cleaning up...$(LINE_RESET)$(NC)"
	@rm -f $(OBJS)
	@echo "$(GOLD)Cleanup complete!$(NC)"

fclean: clean
	@echo "$(BLUE)$(LINE_STYLE)Removing executable:$(LINE_RESET)$(NC)"
	@rm -f $(TARGET)
	@echo "$(GOLD)Full cleanup complete!$(NC)"

re: fclean all

.PHONY: all clean fclean re