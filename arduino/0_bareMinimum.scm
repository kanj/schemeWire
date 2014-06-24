


(load-extension "../arduinoSCM")

(define LED 1)
(pinMode LED 1)

(do ()
	(#f)
	(digitalWrite LED 1)
	(delayMilliseconds 1000)
	(digitalWrite LED 0)
	(delayMilliseconds 1000)
)