
DEBUG=
SCHEME_H_DIR=..
CC=gcc
CFLAGS=-DUSE_DL=1 -I $(SCHEME_H_DIR)


all:	arduino	basicStamp  picaxe	

arduino: arduinoSCM.c
	$(CC) -shared -Wall -fPIC $(CFLAGS) -o arduinoSCM.so $(DEBUG) arduinoSCM.c libwiringPi.a
	strip arduinoSCM.so
	ls -l arduinoSCM.so

basicStamp: bstampSCM.c 
	$(CC) -shared -Wall -fPIC $(CFLAGS) -o bstampSCM.so $(DEBUG) bstampSCM.c libwiringPi.a
	strip bstampSCM.so
	ls -l bstampSCM.so

picaxe:	picaxeSCM.c
	$(CC) -shared -Wall -fPIC $(CFLAGS) -o picaxeSCM.so $(DEBUG) picaxeSCM.c libwiringPi.a
	strip picaxeSCM.so
	ls -l picaxeSCM.so


.PHONY : clean
.PHONY : all
clean:
	rm -f *.o
	rm -f *.so
	rm -f *~

