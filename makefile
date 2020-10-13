PATH = -I motorDrive/ -I ./

a.out: main.c motorDrive.o
	gcc ${PATH} main.c motorDrive.o

motorDrive.o: motorDrive/motorDrive.h motorDrive/motorDrive.c
	gcc -c ${PATH} motorDrive/motorDrive.c