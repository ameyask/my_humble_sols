SRCS = tree_lvlwise.c
OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -I. -g

CC = gcc
 
all: $(OBJS)
	$(CC) -o tree_lvlwise $(CFLAGS) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	rm -f tree_lvlwise tree_lvlwise.o *~
 
