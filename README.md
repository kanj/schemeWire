schemeWire is intended to provide access to the GPIO pins of a Raspberry Pi Scheme programs being run by the TinyScheme interperter. 
To do this one needs:
	* TinyScheme
	* the static library and header files from wiringPi.

Support is provided in two stages: an extension that serves as a wrapper that initializes the board, provides time based functions, 
sets the pinmodes and allows when to or write to a pin; the second stage is a scheme programe that loads the extension, calls the board initialization 
routinue, and provides aliases and additional functions. The aliases can make the program seem more like other micro-controllers. For example,
the Basic Stamp is meant to provide similar functionality. 

 