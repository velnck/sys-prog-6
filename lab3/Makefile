CC = gcc
CFLAGS = -Wall
SOURCEFILES = main.c invert.c
OBJFILES = $(SOURCEFILES:.c=.o)
HEADERS = invert.h
EXECUTABLE = main

all: build clean test

build: $(OBJFILES)
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(OBJFILES)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm *.o

test: test1 test2 test3

test1: build
	@> output-1.txt; \
	./$(EXECUTABLE) input.txt output-1.txt; \
	cmp -s output-1.txt expected_output.txt; \
	if [ $$? -ne 0 ]; then \
		echo "Test 1 failed."; \
	else \
		echo "Test 1 passed."; \
	fi

test2: build
	@> output.txt; \
	./$(EXECUTABLE) input.txt; \
	cmp -s output.txt expected_output.txt; \
	if [ $$? -ne 0 ]; then \
		echo "Test 2 failed."; \
	else \
		echo "Test 2 passed."; \
	fi

test3: build
	@output="$$(./$(EXECUTABLE))"; \
    if [ "$$output" = "Wrong number of arguments." ]; then \
        echo "Test 3 passed."; \
    else \
        echo "Test 3 failed."; \
    fi