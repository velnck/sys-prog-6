# CC = gcc
# CFLAGS = -Wall
# SOURCEFILES = main.c
# OBJFILES = $(SOURCEFILES:.c=.o)
# EXECUTABLE = main

# all: build clean

# build: $(OBJFILES)
# 	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(OBJFILES)

# %.o: %.c
# 	$(CC) $(CFLAGS) -c $< -o $@

# clean:
# 	rm *.o

CC = gcc
CFLAGS = -Wall
SOURCEFILES = main.c
OBJFILES = $(SOURCEFILES:.c=.o)
EXECUTABLE = main
TESTFILES = test.c
TESTEXECUTABLE = test


all: build clean test

build: $(OBJFILES)
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(OBJFILES)

%.o: $(SOURCEFILES)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm *.o

test: $(EXECUTABLE) $(TESTFILES)
	$(CC) $(CFLAGS) -o $(TESTEXECUTABLE) $(TESTFILES)
	./$(TESTEXECUTABLE)

