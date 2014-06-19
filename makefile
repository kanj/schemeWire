
DEBUG=
SCHEME_H_DIR=..
CC=gcc
CFLAGS=-DUSE_DL=1 -I $(SCHEME_H_DIR)

wiringSCM.so : wiringSCM.c 
	$(CC) -shared -Wall -fPIC $(CFLAGS) -o wiringSCM.so $(DEBUG) wiringSCM.c libwiringPi.a
	strip wiringSCM.so
	ls -l wiringSCM.so

.PHONY : clean
clean:
	rm -f *.o
	rm -f wiringSCM.so
	rm -f *~