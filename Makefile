#
CC = gcc -g

CFLAG= -Wall
INCLUDE = -I.
LIBS = 

EXECUTABLE=myDataBase

MYDATABASECFILES = myDataBase.c affair.c page_buffer.c
MYDATABASEOFILES = myDataBase.o affair.o page_buffer.o

.SUFFIXES: .S .c .o .s

all: $(EXECUTABLE)

myDataBase:$(MYDATABASEOFILES)
	$(CC) $(CFLAG) $(LIBS) $(MYDATABASEOFILES) -o $@

clean:
	rm -f *.o *~ $(EXECUTABLE)