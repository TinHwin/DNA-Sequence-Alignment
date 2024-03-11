CC = g++
CFLAGS = -g --std=c++17 -Wall -Werror -pedantic
LIB = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lboost_unit_test_framework
DEPS = EDistance.hpp

.PHONY: all clean lint

all: EDistance test

EDistance: main.o EDistance.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

test: test.o EDistance.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)
	
%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $<

clean:
	rm *.o EDistance test

lint:
	cpplint *.cpp *.hpp
