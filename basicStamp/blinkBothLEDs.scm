;The blink program is the physical computing equivalent of the hello world program

;setup
(load-extension "../bstampSCM")  


;loop

(do ()
  ((= 1 2))  ; Never satisfied therefore infinite loop
  (HIGH 1)
  (HIGH 4)	
  (PAUSE 1000)
  (LOW 1)
  (LOW 4)
  (PAUSE 500)
)