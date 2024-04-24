CC = gcc
CFLAGS = -Wall
SOURCEFILES = main.c
OBJFILES = $(SOURCEFILES:.c=.o)
EXECUTABLE = main
TESTFILES = test.c
TESTEXECUTABLE = test


build: $(OBJFILES)
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(OBJFILES)

%.o: $(SOURCEFILES)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm *.o

run_test: $(EXECUTABLE) $(TESTFILES)
	$(CC) $(CFLAGS) -o $(TESTEXECUTABLE) $(TESTFILES)
	./$(TESTEXECUTABLE)

