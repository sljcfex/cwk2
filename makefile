EXE = route_finding
SRC= main.c interface.c dij.c
CC=gcc
CFLAGS= -std=c99 -Wall
CLINK=
OBJ= $(SRC:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

$(EXE): $(OBJ)
	$(CC) $(OBJ) $(CLINK) -o $(EXE)

clean:
	del $(OBJ) $(EXE)

main.o:      main.c interface.h
interface.o:   interface.c interface.h dij.h
dij.o:	dij.c dij.h
clean : rm edit $(route_finding)


	