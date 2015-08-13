CC = g++
CCFLAGS = -std=c++11 -pthread -march=native -Wall

EXEC = primus

all: $(EXEC)

$(EXEC):
	$(CC) main.cpp -o $(EXEC) $(CCFLAGS) -O0

O1:
	$(CC) main.cpp -o $(EXEC) $(CCFLAGS) -O1

O2:
	$(CC) main.cpp -o $(EXEC) $(CCFLAGS) -O2

O3:
	$(CC) main.cpp -o $(EXEC) $(CCFLAGS) -O3

Os:
	$(CC) main.cpp -o $(EXEC) $(CCFLAGS) -Os


