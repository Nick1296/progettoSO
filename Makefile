CCOPTS= -Wall -ggdb -std=gnu99 -Wstrict-prototypes
LIBS=
CC=gcc
AR=ar


BINS= simplefs_test shell

OBJS = simplefs_test.c simplefs.c simplefs_aux.c bitmap.c disk_driver.c
OSHELL= shell.c bitmap.c disk_driver.c simplefs.c simplefs_aux.c simplefs_apis.c simplefs_shell_apis.c users.c list.c

HEADERS=simplefs.h\
        disk_driver.h\
        bitmap.h\

%.o:	%.c $(HEADERS)
	$(CC) $(CCOPTS) -c -o $@  $<

.phony: clean all


all:	$(BINS)

simplefs_test: $(OBJS)
		$(CC) $(CCOPTS)  -o $@ $^ $(LIBS)

valgrind:
	valgrind --leak-check=full ./simplefs_test

shell: $(OSHELL)
	$(CC) $(CCOPTS)  -o $@ $^ $(LIBS)
clean:
	rm -rf *.o *~  $(BINS) shell

test:
	./simplefs_test
