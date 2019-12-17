CC = gcc
OBJS = main.o sum.o
HDRS = sum.h

prog: $(OBJS)
	$(CC) -o prog main.o sum.o

$(OBJS): $(HDRS)

clean:
	rm *.o prog
