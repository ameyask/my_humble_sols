SRCS = tryrev.c
OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -I. -g

CC = gcc
 
all: $(OBJS)
	$(CC) -o tryrev $(CFLAGS) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	rm -f tryrev  tryrev.o *~
 
