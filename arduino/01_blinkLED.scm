;01_blinkLED;
;	Sets LED on Pin 1 blinking 
; 	This example code is in the public domain.

;Setup
(load-extension "../arduinoSCM")
(define LED 1)
(pinMode LED 1)

;Loop
(do ()
	(#f)
	(digitalWrite LED 1)
	(delayMilliseconds 1000)
	(digitalWrite LED 0)
	(delayMilliseconds 1000)
)