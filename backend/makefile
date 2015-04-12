SRCDIR = src
INCDIR = include
TESTDIR = tests
DESTF = bin/canary
SRCS = $(wildcard $(SRCDIR)/*.cpp)
INCS = $(wildcard $(INCDIR)/*.h)
OBJS = $(SRCS:$(SRCDIR)/%.cpp=$(SRCDIR)/%.o)


CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

all: $(OBJS) main.o
	$(CC) $(LFLAGS) tests/main.cpp -o $(DESTF)

$(SRCS):%.o: $(SRCDIR)/%.cpp $(INCDIR)/%.h
	$(CC) $(CFLAGS) $< -o $@

main.o: tests/main.cpp $(INCS)
	$(CC) $(CFLAGS) tests/main.cpp -o ./tests/main.o

clean:
	\rm src/*.o tests/*.o bin/* *.o


