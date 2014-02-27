CC = g++
CFLAGS = -g -Wall -fPIC

OUTPUT := ../bin/reservoid

INCLUDE := ./ 
LIBS := 

SOURCE := $(wildcard  *.cpp)
OBJS := $(patsubst %.cpp, %.o, $(SOURCE))


%.o:%.cpp
	$(CC) $(CFLAGS) $(addprefix -I,$(INCLUDE)) -c $< -o $@

all:$(OUTPUT)

../bin/reservoid: $(OBJS)
	$(CC) $(CFLAGS) $(addprefix -I,$(INCLUDE)) -o $@ $^  $(LIBS)

clean:
	-rm -f $(OBJS)
