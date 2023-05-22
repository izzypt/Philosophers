NAME=philosophers
CFLAGS=-Wall -Wextra -g -pthread
CC=cc
SRC=main.c utils/*.c project_logic/*.c

all:$(NAME)

$(NAME): $(SRC)
	$(CC) $(SRC) $(CFLAGS) -o $(NAME) 

clean:
	rm -f $(NAME)