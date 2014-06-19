;The blink program is the physical computing equivalent of the hello world program

;setup
(load "stamp.scm")  

;loop
(display "Counterclockwise 10 O'Clock")
(newline)
(define t0 (millis))
(do ((counter 1 (+ counter 1)))
  ((> counter 100))  
  
  
;  (delayMicroseconds 0)
)	
(display (- (millis) t0))
	(newline)

;loop
(display "Counterclockwise 10 O'Clock")
(newline)
(define t0 (millis))
(do ((counter 1 (+ counter 1)))
  ((> counter 200))  
  
  (PULSOUT 1 1000)
  (delayMilliseconds 15)
	

)
(display (- (millis) t0))
	(newline)
(do ((counter 1 (+ counter 1)))
  ((> counter 150))  
  (PULSOUT 1 500)
  (PAUSE 15)
)
(do ((counter 1 (+ counter 1)))
  ((> counter 150))  
  (PULSOUT 1 750)
  (PAUSE 15)  
)  

