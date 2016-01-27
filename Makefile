DBG = 1
CC=gcc
CFLAGS=-c -Wall
LDFLAGS=
ifeq ($(DBG), 1)
	CFLAGS += -g
	CFLAGS += -O0
endif

SOURCES=main.c dictionary.c

OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=dictionary

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm *o

