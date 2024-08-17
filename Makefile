
CC = gcc
CFLAGS = -Wall -Wextra

evm: common.h instruction.h main.c
	$(CC) $(CFLAGS) common.h instruction.h main.c 
