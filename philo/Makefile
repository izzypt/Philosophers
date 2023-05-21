NAME=philosophers
CFLAGS=-Wall -Wextra -g -pthread
CC=cc
SRC=main.c

all:$(NAME)

$(NAME): $(SRC)
	$(CC) $(SRC) $(CFLAGS) -o $(NAME) 

clean:
	rm -f $(NAME)