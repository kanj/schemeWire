;01_bareMinimum;
;	This program does nothing other than load an extension and excercise an infinite loop.
; 	This example code is in the public domain.


(load-extension "../picaxeSCM")  ; This extension allows acces to the GPIO pins on the Raspberry Pi



; This is an infinite do-loop. It would be populated with commands that excercise the GPIO pins
(do ()
	(#f)
)