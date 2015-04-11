SRC = src
INC = include
TEST = tests/main.cpp
DEST = bin/canary
SRCS := $(shell echo $(SRC)/*.cpp)
INCS := $(shell echo $(INC)/*.h)
OBJS = $(SRCS:$(SRC)/%.cpp=%.o)


CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

all: $(OBJS)

test: $(OBJS) $(TEST)
	$(CC) $(LFLAGS) $(TEST) -o $(DEST)

$(OBJS):%.o: $(SRC)/%.cpp $(INC)/%.h
	$(CC) $(CFLAGS) $< -o $@

clean:
	\rm src/*.o tests/*.o bin/* *.o


