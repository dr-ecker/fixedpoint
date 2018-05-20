CC=gcc

.PHONY: all
all: filter impulse rand
filter:
	$(CC) -o filter main.c fixedpoint.c
impulse:
	$(CC) -o impulsegen ImpulseSig.c
rand:
	$(CC) -o randgen RandSig.c
