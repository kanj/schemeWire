;01_pushButtonLED;
;	Reads a digital input on pin 4, and adjusts the LED accordingly 
; 	This example code is in the public domain.


(load-extension "../arduinoSCM")

(define pushButton 4)
(pinMode pushButton 0)
(define LED 1)
(pinMode LED 1)




(do ()
	(#f)
	(digitalWrite LED (digitalRead pushButton))
	(delayMilliseconds 100)
)