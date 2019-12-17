#Zachary Talarick
#I pledge my honor that I have abided by the Stevens Honor System.

CXX      = gcc
CXX_FILE = $(wildcard *.c)
TARGET   = $(patsubst %.c,%,$(CXX_FILE))

all:
	$(CXX) -pthread $(CXX_FILE) -o $(TARGET)
clean:
	rm -f $(TARGET) $(TARGET).exe
