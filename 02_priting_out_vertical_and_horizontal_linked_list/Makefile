SRCS = vertical_ll.c
OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -I. -g

CC = gcc
 
all: $(OBJS)
	$(CC) -o vertical_ll $(CFLAGS) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	rm -f vertical_ll vertical_ll.o *~
 
