CC = gcc
CFLAGS = -Wall -Iinclude
LDFLAGS = -lcurl -ljson-c
SRC = main.c src/http_client.c src/card_reader.c src/config.c
TARGET = pos_terminal

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(TARGET)