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
	(if (= (digitalRead pushButton) 1)
		(begin (digitalWrite LED 1) ) 	; This will be executed by default
		(digitalWrite LED 0)		; This will be executed if button while button is pressed	
	)
	(delayMilliseconds 100)
)