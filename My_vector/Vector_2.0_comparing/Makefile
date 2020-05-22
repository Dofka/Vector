 CC = g++
 CFLAGS = 

main: vector_main.o vector_header.o
	$(CC) $(CFLAGS) -o main vector_main.o vector_header.o

test_unit: test_unit.o vector_header.o
	$(CC) $(CFLAGS) -o test_unit test_unit.o vector_header.o

vector_header: vector_header.h vector_header.cpp
	$(CC) $(CFLAGS) -c vector_header.cpp

clean:
	rm *.o *.txt main test_unit

