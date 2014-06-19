; Add basic stamp like functionality to Tinyscheme

(load-extension "../wiringSCM")

(wiringPiSetup)

(define (HIGH pin)
	(pinMode pin 1)
	(digitalWrite pin 1)
)

(define (IN pin)
	(pinMode pin 0)
	(digitalRead pin )
)


(define (LOW pin)
	(pinMode pin 1)
	(digitalWrite pin 0)
)

(define (PAUSE msec)
	(delayMilliseconds msec)
)

(define (PULSOUT pin duration)
	(pinMode pin 1)
	(digitalWrite pin 1)
	(delayMicroseconds (* 2 duration))
	(digitalWrite pin 0)
)
