#Zachary Talarick
#I pledge my honor that I have abided by the Stevens Honor System.

CC = gcc
OBJS = cs392_shell.o cs392_exec.o cs392_signal.o cs392_log.o
HDRS = cs392_exec.h cs392_signal.h cs392_log.h

cs392_shell: $(OBJS)
	$(CC) -o cs392_shell cs392_shell.o cs392_exec.o cs392_signal.o cs392_log.o

$(OBJS): $(HDRS)

clean:
	rm *.o cs392_shell
