;01_pushButton;
;	Reads a digital input on pin 4, displays the result 
; 	This example code is in the public domain.

;Setup
(load-extension "../arduinoSCM")

(define pushButton 4)
(pinMode pushButton 0)



(do ()
	(#f)
	(display (digitalRead pushButton))
	(newline)
	(delayMilliseconds 1000)
)