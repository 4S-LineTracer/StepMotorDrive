PATH = -I motorDrive/ -I registors/ -I sharedvars/  -I accTable/ -I ./

a.out: main.c motorDrive.o registors.o accTable.o sharedvars.o
	gcc ${PATH} registors.o sharedvars.o accTable.o motorDrive.o main.c

motorDrive.o: motorDrive/motorDrive.h motorDrive/motorDrive.c
	gcc -c ${PATH} motorDrive/motorDrive.c

registors.o: registors/registors.h registors/registors.c
	gcc -c ${PATH} registors/registors.c

sharedvars.o: sharedvars/sharedvars.h sharedvars/sharedvars.c
	gcc -c ${PATH} sharedvars/sharedvars.c

accTable.o: accTable/accTable.h accTable/accTable.c
	gcc -c ${PATH} accTable/accTable.c

