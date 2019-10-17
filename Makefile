CFLAGS := -O0

# rdynamic is needed to see symbols
LDFLAGS := -rdynamic

CC := gcc

main: main.o
	$(CC) $(LDFLAGS) -o main main.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o

main.s: main.o
	objdump --source -d -M intel main.o > main.$(CC).s

clean:
	rm -rf main *.o *.s
