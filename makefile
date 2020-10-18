# variables
PATH = -I motorDrive/ -I Emulator/registors/ -I Emulator/sharedvars/  -I accTable/ -I ./

# 単体テスト
a.out: main.c itask_motor.o motorDrive.o registors.o accTable.o sharedvars.o
	gcc ${PATH} registors.o sharedvars.o accTable.o motorDrive.o itask_motor.o main.c

# 本体(itask_motor)
itask_motor.o: itask_motor.h itask_motor.c
	gcc -c ${PATH} itask_motor.c

motorDrive.o: motorDrive/motorDrive.h motorDrive/motorDrive.c
	gcc -c ${PATH} motorDrive/motorDrive.c

accTable.o: accTable/accTable.h accTable/accTable.c
	gcc -c ${PATH} accTable/accTable.c

# 実行環境エミュレータ
registors.o: Emulator/registors/registors.h Emulator/registors/registors.c
	gcc -c ${PATH} Emulator/registors/registors.c

sharedvars.o: Emulator/sharedvars/sharedvars.h Emulator/sharedvars/sharedvars.c
	gcc -c ${PATH} Emulator/sharedvars/sharedvars.c