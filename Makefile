#target
TARGET = LazerAlarm
#compiler
COMPILER =g++
CFLAGS =-c
#projectFiles
LIB_CPP =$(wildcard ./lib/*.cpp)
SRC_CPP =$(wildcard ./src/*.cpp)
INCLUDE_H =$(wildcard ./include/*.h)
LIB_OBJ =$(subst .cpp,.o,$(LIB_CPP))
SRC_OBJ =$(subst .cpp,.o,$(SRC_CPP))

#included file directories
IFLAGS =-Iinclude
#linked file directories
LFLAGS =-lwiringPi -lpthread

$(TARGET):$(SRC_OBJ) $(LIB_OBJ)
	$(COMPILER) $(LFLAGS) $(LIB_OBJ) $(SRC_OBJ) -o $(TARGET)

%.o:%.cpp
	$(COMPILER) $(IFLAGS) $(CFLAGS) $(LFLAGS) $< -o $@

$(LIB_OBJ):$(LIB_CPP)
$(SRC_OBJ:$(SRC_CPP)

.PHONY:all
all:$(TARGET)

.PHONY:clean
clean:
	rm -f $(TARGET) ./*.o ./lib/*.o ./src/*.o

.PHONY:run
run:$(TARGET)
	sudo ./$(TARGET)

.PHONY:vim
vim:
	vim $(SRC_CPP) $(LIB_CPP) $(INCLUDE_H)
