CC=gcc
CFLAGS=-ansi -Wall

currency: currency.c cJSON.c
	$(CC) $(CFLAGS) -o currency currency.c cJSON.c