SRC = src
INC = include
TEST = tests
DEST = bin/canary
SRCS = $(wildcard $(SRC)/*.cpp)
INCS = $(wildcard $(INC)/*.h)
OBJS = $(SRCS:$(SRC)/%.cpp=$(SRC)/%.o) $(TEST)/main.o


CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

all: $(OBJS)
	$(CC) $(LFLAGS) $(TEST)/main.cpp -o $(DEST)

$(OBJS):%.o: %.cpp $(INCS)
	$(CC) $(CFLAGS) $< -o $@

clean:
	\rm src/*.o tests/*.o bin/* *.o


