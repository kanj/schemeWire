


(load-extension "../picaxeSCM")

(define LED 1)


(do ()
	(#f)
	(HIGH LED)
	(PAUSE 1000)
	(LOW LED)
	(PAUSE 1000)
)