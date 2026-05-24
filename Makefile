CC = gcc
CFLAGS = -Wall
TARGET = tetris

all: $(TARGET)

$(TARGET): proiect.o hs_utils.o
	$(CC) $(CFLAGS) -o $(TARGET) proiect.o hs_utils.o

proiect.o: proiect.c hs_utils.h
	$(CC) $(CFLAGS) -c proiect.c

hs_utils.o: hs_utils.c hs_utils.h
	$(CC) $(CFLAGS) -c hs_utils.c

clean:
	rm -f *.o $(TARGET)