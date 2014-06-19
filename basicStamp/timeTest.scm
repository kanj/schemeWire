;Testing timne functions

;setup
(load "wiring.scm")  

(define now (millis))
(delayMilliseconds 1500)
(display (- (- (millis) now) 1000)) ; s/c 0
