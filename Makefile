# Compiler-Flags
CC = cc
CFLAGS = -g -Wall -Werror -Wextra -pthread

# Name des Programms
PHILOSOPHERS = philo

# Quell- und Objektdateien
SRC_DIR = src
OBJ_DIR = obj

SRCS = error_message.c exit_functions.c \
       input_checks.c lst_functions.c main.c parsing.c \
       tasks.c utils.c
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

# Header-Dateien
HEADERS = philo.h

# Regel zur Erstellung des Binärprogramms
$(PHILOSOPHERS): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(PHILOSOPHERS)

# Regel zur Erstellung der .o-Dateien im obj-Ordner
$(OBJ_DIR)/%.o: %.c $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Standard-Build
all: $(PHILOSOPHERS)

# Aufräumen der Objektdateien
clean:
	@rm -rf $(OBJ_DIR)

# Komplettes Aufräumen inkl. Binary
fclean: clean
	@rm -f $(PHILOSOPHERS)

# Neu kompilieren
re: fclean all

.PHONY: all clean fclean re
