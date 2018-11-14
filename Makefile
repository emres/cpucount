CC=gcc
CFLAGS=-Wall -std=c99 -pedantic
LDFLAGS=-ldl
SHAREDLIBFLAGS=-fPIC -shared -nostartfiles

call_cpucount_lib: call_cpucount_lib.o cpucount_lib.so
	$(CC) -o call_cpucount_lib call_cpucount_lib.c $(CFLAGS) $(LDFLAGS)

cpucount_lib.so: cpucount_lib.c
	$(CC) -o cpucount_lib.so cpucount_lib.c $(SHAREDLIBFLAGS) 

.PHONY: clean
clean:
	rm -f *.o
	rm -f *.so
	rm -f call_cpucount_lib 
