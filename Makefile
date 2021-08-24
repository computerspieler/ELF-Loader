CC=gcc
CCFLAGS=-c -Wall -Wextra -Iinclude

LD=gcc
LDFLAGS=

DEL=@rm
DELFLAGS=-frdv

MKDIR=mkdir
MKDIRFLAGS=-p

OBJS=$(patsubst %.o,bin/%.o,\
	main.o elf_loader.o \
)

.PHONY: all clear debug release run

all:
	@echo "You need to add one of the following target :) : build / clean / run"


run: build
	gdb --args ./build test/test.elf

clean:
	$(DEL) $(DELFLAGS) bin
	$(DEL) $(DELFLAGS) build

build: bin $(OBJS)
	$(LD) $(LDFLAGS) -g -o $@ $(OBJS)

bin:
	$(MKDIR) $(MKDIRFLAGS) bin/

bin/%.o: src/%.c src/*.h
	$(CC) $(CCFLAGS) -g -o $@ $<
