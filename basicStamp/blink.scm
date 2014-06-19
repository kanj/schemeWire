;The blink program is the physical computing equivalent of the hellow world program

;setup
(load "wiring.scm")  

(define LED 1)

(pinMode LED OUT)

;loop

(do ()
  ((= 1 2))  ; Never satisfied therefore infinite loop
  (digitalWrite LED HIGH)
  (delayMilliseconds 1000)
  (digitalWrite LED LOW)
  (delayMilliseconds 500)
)