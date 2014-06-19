;The blink program is the physical computing equivalent of the hello world program

;setup
(load "stamp.scm")  

(define LED 1)


;loop

(do ()
  ((= 1 2))  ; Never satisfied therefore infinite loop
  (HIGH LED)
  (PAUSE 1000)
  (LOW LED)
  (PAUSE 500)
)