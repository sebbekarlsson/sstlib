OS := $(shell uname)

$(info $(OS))

FLAGZ=-Wall -g -fPIC

SOURCES := $(wildcard src/*.c)
OBJECTS = $(SOURCES:.c=.o)

test:\
    $(OBJECTS) unit.o
	gcc\
	    $(OBJECTS) unit.o -o test.out -ldl -fPIC -lcmocka

unit.o: src/unit/unit.c
	gcc -g -Wall -c src/unit/unit.c -ldl -fPIC -lcmocka

%.o: %.c includes/%.h
	gcc -c $(FLAGZ) $< -o $@

libsst.so: $(OBJECTS)
	$(LINK.c) -shared $^ -o $@


install:
	-rm /usr/local/lib/sstlib.*
	-rm -rf /usr/local/include/sstlib
	make
	make libsst.so
	cp -r src/includes /usr/local/include/sstlib
	cp libsst.so /usr/local/lib/libsst.so

clean:
	-rm *.out
	-rm *.o
	-rm *.so
	-rm src/*.o
