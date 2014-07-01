;01_digitalRead;
;	Reads a digital input on pin 4, displays the result 
; 	This example code is in the public domain.


(load-extension "../bstampSCM")

(define pushButton 4)




(do ()
	(#f)
	(display (IN pushButton))
	(newline)
	(PAUSE 1000)
)