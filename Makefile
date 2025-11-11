CC = g++
TARGETS = 1 2 3 4 5 6 7

all: $(TARGETS)

%: %.cpp
	$(CC) $< -o $@.exe

clean:
	rm -f *.o *.exe
