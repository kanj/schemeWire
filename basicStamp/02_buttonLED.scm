;01_pushButtonLED;
;	Reads a digital input on pin 4, and adjusts the LED accordingly 
; 	This example code is in the public domain.


(load-extension "../bstampSCM")

(define pushButton 4)
(define LED 1)




(do ()
	(#f)
	(if (= (IN pushButton) 1)
		(begin (HIGH LED) ) 	; This will be executed by default
		(LOW LED)		; This will be executed if button while button is pressed	
	)
	(PAUSE 100)
)