CC = gcc
CFLAGS = -Wall -Wextra -g -fno-stack-protector
LDFLAGS = -Wl,--stack,16777216
EXEC = programa
SRCS = bolha.o bolhaParada.o bucketsort.o geradorSequencia.o heapsort.o insercaoBinaria.o insercaoDireta.o main.o mergesort.o quicksortIni.o quicksortCentro.o quicksortMediana.o radixsort.o selecaoDireta.o shellsort.o
OBJS = $(SRCS:.c=.o)

all: $(EXEC)
	./$(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(EXEC) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	del /f /q *.o $(EXEC)