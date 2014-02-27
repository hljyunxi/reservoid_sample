CC = g++
CFLAGS = -g -Wall -fPIC

OUTPUT := ../bin/lottery

INCLUDE := ./ 

SOURCE := $(wildcard  *.cpp)
OBJS := $(patsubst %.cpp, %.o, $(SOURCE))


%.o:%.cpp
	$(CC) $(CFLAGS) $(addprefix -I,$(INCLUDE)) -c $< -o $@

all:$(OUTPUT)

./bin/lottery: $(OBJS)
	$(CC) $(CFLAGS) $(addprefix -I,$(INCLUDE)) -o $@ $^  

clean:
	-rm -f $(OBJS)
