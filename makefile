all: main

main: sqlist.o main.o 
	$(CC) $^ -o $@

clean:
	rm *.o main -rf
