OUTPUT = solver

CC = g++
WARNING = -Wall -Wshadow --pedantic
ERROR =  -Wvla -Werror
FLAGS = -g $(WARNING) $(ERROR) 
OFLAGS = $(FLAGS) -c
OBJS = main.o elimination.o matrix.o
run: $(OUTPUT)
	./$(OUTPUT)
$(OUTPUT): $(OBJS) 
	$(CC) $(OBJS) $(FLAGS) -o $(OUTPUT)
debug: solver
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./solver
gdb: solver
	gdb ./$(OUTPUT)
main.o: main.cpp
	$(CC) main.cpp $(OFLAGS) 
elimination.o: elimination.cpp elimination.h
	$(CC)  elimination.cpp $(OFLAGS) 
matrix.o: matrix.cpp matrix.h
	$(CC) matrix.cpp $(OFLAGS)
clean:
	rm -f $(OUTPUT) *.o
