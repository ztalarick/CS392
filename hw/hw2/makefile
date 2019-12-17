CC = gcc
OBJS = cs392_strlen.o cs392_memcpy.o
HDRS = cs392_string.h 

libcs392string.so: $(OBJS)
		$(CC) *.c -shared -o libcs392string.so
$(OBJS): $(HDRS)
clean:
	rm *.o libcs392string.so
