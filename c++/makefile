CFLAGS = -O
CC = g++
pro: main.o fs.o path.o
	$(CC) $(CFLAGS) -o pro main.o fs.o path.o
main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp
fs.o: fs.cpp
	$(CC) $(CFLAGS) -c fs.cpp
path.o: path.cpp
	$(CC) $(CFLAGS) -c path.cpp
clean:
	rm -f core *.o
