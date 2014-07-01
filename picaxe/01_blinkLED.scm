;01_blinkLED;
;	Sets LED on Pin 1 blinking 
; 	This example code is in the public domain.

(load-extension "../picaxeSCM")

(define LED 1)


(do ()
	(#f)
	(HIGH LED)
	(PAUSE 1000)
	(LOW LED)
	(PAUSE 1000)
)