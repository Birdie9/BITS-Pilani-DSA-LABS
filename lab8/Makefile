CC=gcc
CFLAGS= -I. -g

APP=fine

.c.o:
	${CC} ${CFLAGS}  -c -o $@ $<

OBJ= destroyHash.o destroyPoliceTree.o initializeHash.o insertByPoliceId.o \
		insertHash.o printBonusPolicemen.o printViolators.o reorderByFineAmount.o \
		fine.o printPoliceTree.o

all: ${APP}

${APP}: ${OBJ}
	${CC} ${CFLAGS} ${OBJ} -o ${APP}

clean:
	rm -vf *.o *~ ${APP} 

