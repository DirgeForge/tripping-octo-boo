SRC = src
INC = include
TEST = tests
DEST = bin/canary
SRCS := $(shell echo $(SRC)/*.cpp)
INCS := $(shell echo $(INC)/*.h)
OBJS = $(SRCS:$(SRC)/%.cpp=$(SRC)/%.o)


CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

all: $(OBJS) main.o
	$(CC) $(LFLAGS) tests/main.cpp -o $(DEST)

#$(OBJS):%.o: $(SRC)/%.cpp $(INC)/%.h
$(OBJS):%.o: $(SRCS) $(INCS)
	$(CC) $(CFLAGS) $< -o $@

main.o: tests/main.cpp $(INCS)
	$(CC) $(CFLAGS) tests/main.cpp -o ./tests/main.o

clean:
	\rm src/*.o tests/*.o bin/* *.o


