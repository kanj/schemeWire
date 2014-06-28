;06_ping;
;	Reads a ping sensor 
; 	This example code is in the public domain.


(load-extension "../bstampSCM")

(define ping 1)





(do ()
	(#f)
	(pulsout ping 5)
	(display (/ (pulsin ping 1) 70.7))
	(newline)
	(PAUSE 300)
)