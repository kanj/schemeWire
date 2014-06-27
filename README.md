Description:
schemeWire is intended to provide access to the GPIO pins of a Raspberry Pi Scheme to programs being run by the TinyScheme interperter. 
This projects provides extensions so that the one can access commands similar to usage with other micro-controller environments. 
The three styles (Dialects) being explored are : arduino, Basic Stamp and the Picaxe. 

Installation Instructions:

To use this you will need the following:
	* A Raspberry Pi running a Raspbian image
	* Tinyscheme. The source code is available at "http://tinyscheme.sourceforge.net/". It compiled without modification.
	* Wiring Pi. The source code is available at http://wiringpi.com/download-and-install/. You will need the static library and header files.
	* To run projects a breadboard and miscelaneous parts will be of use. The adafruit pi cobbler makes a good interface between Pi and breadboard.
	

Download the source code, copy the static library and header files from wiringPi, and run make. 

Change to the directory for the microcontroller dialect of interest. Put a copy of init.scm in the directory.

Wire a project.

To run it type "sudo scheme 01_blink.scm", or other program as desired.


Where to go to get Help:

Explanation of micro-controller commands:
	Basic Stamp: http://uttermatter.com/bs2/S_PBASIC.php
	
Scheme Programming:
	http://www.ccs.neu.edu/home/dorai/t-y-scheme/t-y-scheme.html

Credits Inspirations Alternatives:

Credit goes to the Tinyscheme, wiringPi and Raspbian projects, and so on. I used the arduino examples as the basis for the examples given here.

 		