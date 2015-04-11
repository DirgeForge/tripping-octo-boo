SRC = src
INC = include
OBJ = obj
SRCS := $(shell echo $(SRC)/*.cpp)
INCS := $(shell echo $(INC)/*.h)
OBJS = $(SRCS:$(SRC)/%.cpp=$(OBJ)/%.o)

CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)
DEST = canary

$(OBJS):$(OBJ)/%.o: $(SRC)/%.cpp $(INC)/%.h
	$(CC) $(LFLAGS) -v $(SRCS)

#p1 : $(OBJS)
#	$(CC) $(LFLAGS) $(OBJS) -o p1

clean:
	\rm src/*.o tests/*.o bin/*


