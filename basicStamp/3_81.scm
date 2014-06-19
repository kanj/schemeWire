;The blink program is the physical computing equivalent of the hello world program

;setup
(load "stamp.scm")  




;loop

(do ()
  ((= 1 2))  ; Never satisfied therefore infinite loop
  (if (= (IN 1) 1) 
	(begin 
	(HIGH 4)
	(PAUSE 50)
	(LOW 4)
	(PAUSE 50)); then  branch
	(PAUSE 100) ; else branch
  )	
)