stat.o: stat.c
	gcc stat.c -o stat.o

run: stat.o
	./stat.o

clean:
	rm stat.o