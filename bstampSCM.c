/* TinyScheme Extensions
 * (c) 2002 Visual Tools, S.A.
 * Manuel Heras-Gilsanz (manuel@heras-gilsanz.com)
 *
 * This software is subject to the terms stated in the
 * LICENSE file.
 */

#include <scheme-private.h>
#include <time.h>
#include <scheme.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>
#include <dirent.h>
#include "wiringPi.h"

/*FREQOUT	*/
pointer foreign_FREQOUT(scheme * sc, pointer args)
{
  pointer first_arg;
  pointer second_arg;
  pointer third_arg;

  long pin, duration, Ton, i, Counter, freq;

  if(args == sc->NIL)
    return sc->F;

  first_arg = sc->vptr->pair_car(args);
  if(!sc->vptr->is_integer(first_arg)) {
    return sc->F;
  }


 args = sc->vptr->pair_cdr(args);
  second_arg = sc->vptr->pair_car(args);
  if(!sc->vptr->is_integer(second_arg)) {
    return sc->F;
   }
  


 args = sc->vptr->pair_cdr(args);
  third_arg = sc->vptr->pair_car(args);
  if(!sc->vptr->is_integer(third_arg)) {
    return sc->F;
   }
	
  pin = sc->vptr->ivalue(first_arg);
  duration = sc->vptr->ivalue(second_arg);
  freq = sc->vptr->ivalue(third_arg);


	

  pinMode(pin, 1);
  
  Ton = 500000 / freq;
  Counter = 500*duration/Ton;
  
  for (i=0;i<Counter;i++) {
	digitalWrite(pin,1);
	delayMicroseconds(Ton);
	digitalWrite(pin, 0);
	delayMicroseconds(Ton);
}	
  
  return sc->T;
}


/*HIGH		*/
pointer foreign_HIGH(scheme * sc, pointer args)
{
  pointer first_arg;
  
  long pin;

  if(args == sc->NIL)
    return sc->F;

  first_arg = sc->vptr->pair_car(args);
  if(!sc->vptr->is_integer(first_arg)) {
    return sc->F;
  }



  pin = sc->vptr->ivalue(first_arg);
  pinMode(pin, 1);
  digitalWrite( pin, 1 );

  return sc->T;
}
/*IN		*/
pointer foreign_IN(scheme * sc, pointer args)
{
  pointer first_arg;
  long pin;

  if(args == sc->NIL)
    return sc->F;

  first_arg = sc->vptr->pair_car(args);
  if(!sc->vptr->is_integer(first_arg)) {
    return sc->F;
  }


 
  pin = sc->vptr->ivalue(first_arg);
  
  pinMode(pin , 0); 	
  return (sc->vptr->mk_integer(sc,digitalRead(pin)));

  
}


/*LOW		*/
pointer foreign_LOW(scheme * sc, pointer args)
{
  pointer first_arg;
  
  long pin;

  if(args == sc->NIL)
    return sc->F;

  first_arg = sc->vptr->pair_car(args);
  if(!sc->vptr->is_integer(first_arg)) {
    return sc->F;
  }



  pin = sc->vptr->ivalue(first_arg);
  pinMode(pin, 1);
  digitalWrite( pin, 0 );

  return sc->T;
}


/*PAUSE		*/
pointer foreign_PAUSE(scheme * sc, pointer args)
{
  pointer first_arg;
  long msec;
  
  if(args == sc->NIL)
    return sc->F;

  first_arg = sc->vptr->pair_car(args);
  if(!sc->vptr->is_integer(first_arg)) {
    return sc->F;
  }

  msec = sc->vptr->ivalue(first_arg);
  
  delay(msec);

  return sc->T;
}

/*PULSIN 	*/
pointer foreign_PULSIN(scheme * sc, pointer args)
{
  pointer first_arg;
  pointer second_arg;
  long pin, state, duration, Counter;

  if(args == sc->NIL)
    return sc->F;

  first_arg = sc->vptr->pair_car(args);
  if(!sc->vptr->is_integer(first_arg)) {
    return sc->F;
  }


  args = sc->vptr->pair_cdr(args);
  second_arg = sc->vptr->pair_car(args);
  if(!sc->vptr->is_integer(second_arg)) {
    return sc->F;
   }

  pin = sc->vptr->ivalue(first_arg);
  state = sc->vptr->ivalue(second_arg);

  pinMode( pin, 0);
  duration=0;
  Counter=0;

  do{
		
		Counter++;
		if (digitalRead(pin) == state) 
			break;
		delayMicroseconds(2);
		

	} while (Counter<65535) ;
	
	if (Counter == 65535) 
			return (sc->vptr->mk_integer(sc,duration));

	do{
		
		duration++;
		if (digitalRead(pin) != state) 
			break;
		delayMicroseconds(2);
		

	} while (duration<65535) ;
	

  return (sc->vptr->mk_integer(sc,duration));
}

/*PULSOUT	*/
pointer foreign_PULSOUT(scheme * sc, pointer args)
{
  pointer first_arg;
  pointer second_arg;
  long pin, duration;

  if(args == sc->NIL)
    return sc->F;

  first_arg = sc->vptr->pair_car(args);
  if(!sc->vptr->is_integer(first_arg)) {
    return sc->F;
  }


 args = sc->vptr->pair_cdr(args);
  second_arg = sc->vptr->pair_car(args);
  if(!sc->vptr->is_integer(second_arg)) {
    return sc->F;
   }

  pin = sc->vptr->ivalue(first_arg);
  duration = sc->vptr->ivalue(second_arg);

  pinMode( pin, 1 );
	digitalWrite(pin, 1);
	delayMicroseconds( 2*duration );
	digitalWrite(pin , 0);

  return sc->T;
}


/*RCTIME	*/

pointer foreign_RCTIME(scheme * sc, pointer args)
{
  pointer first_arg;
  pointer second_arg;
  

  long pin, duration, Counter, polarity;

  if(args == sc->NIL)
    return sc->F;

  first_arg = sc->vptr->pair_car(args);
  if(!sc->vptr->is_integer(first_arg)) {
    return sc->F;
  }


 args = sc->vptr->pair_cdr(args);
  second_arg = sc->vptr->pair_car(args);
  if(!sc->vptr->is_integer(second_arg)) {
    return sc->F;
   }
  
	
  pin = sc->vptr->ivalue(first_arg);
  polarity = sc->vptr->ivalue(second_arg);
  Counter=0;
  
  pinMode(pin,0);

	do{
		
		Counter++;
		if (digitalRead(pin) != polarity) 
			break;
		delayMicroseconds(1);
		

	} while (Counter<65535) ;
	


	

  
  return (sc->vptr->mk_integer(sc,Counter));
}

pointer foreign_delayMicroseconds(scheme * sc, pointer args)
{
  pointer first_arg;
  long usec;
  

  if(args == sc->NIL)
    return sc->F;

  first_arg = sc->vptr->pair_car(args);
  if(!sc->vptr->is_integer(first_arg)) {
    return sc->F;
  }

  usec = sc->vptr->ivalue(first_arg);
  
  delayMicroseconds(usec);

  return sc->T;
}


pointer foreign_delayMilliseconds(scheme * sc, pointer args)
{
  pointer first_arg;
  long msec;
  

  if(args == sc->NIL)
    return sc->F;

  first_arg = sc->vptr->pair_car(args);
  if(!sc->vptr->is_integer(first_arg)) {
    return sc->F;
  }

  msec = sc->vptr->ivalue(first_arg);
  
  delay(msec);

  return sc->T;
}







pointer foreign_micros(scheme * sc, pointer args)
{
  
  

  if(args != sc->NIL)
    return sc->F;

  
    return (sc->vptr->mk_integer(sc,micros()));
  }











pointer foreign_wiringPiSetup(scheme * sc, pointer args)
{

  if(args != sc->NIL)
    return sc->F;

  wiringPiSetup();

  return sc->T;
}






pointer foreign_system(scheme * sc, pointer args)
{
  pointer first_arg;
  char * command;
  int retcode;

  if(args == sc->NIL)
    return sc->F;

  first_arg = sc->vptr->pair_car(args);
  if(!sc->vptr->is_string(first_arg))
    return sc->F;
  
  command = sc->vptr->string_value(first_arg);
  if(0 == command)
    return sc->F;

  retcode = system(command);
  if( (127 == retcode) || (-1 == retcode) )
    return sc->F;

  return (sc->vptr->mk_integer(sc,retcode));
}


/* This function gets called when TinyScheme is loading the extension */

void init_bstampSCM (scheme * sc)
{


wiringPiSetup();



/* FREQOUT		*/
sc->vptr->scheme_define(sc,sc->global_env,
                               sc->vptr->mk_symbol(sc,"freqout"),
                               sc->vptr->mk_foreign_func(sc, foreign_FREQOUT));

/*HIGH			*/
sc->vptr->scheme_define(sc,sc->global_env,
                               sc->vptr->mk_symbol(sc,"high"),
                               sc->vptr->mk_foreign_func(sc, foreign_HIGH));

/*IN			*/
sc->vptr->scheme_define(sc,sc->global_env,
                               sc->vptr->mk_symbol(sc,"in"),
                               sc->vptr->mk_foreign_func(sc, foreign_IN));

/*LOW			*/
sc->vptr->scheme_define(sc,sc->global_env,
                               sc->vptr->mk_symbol(sc,"low"),
                               sc->vptr->mk_foreign_func(sc, foreign_LOW));

/*PAUSE			*/
sc->vptr->scheme_define(sc,sc->global_env,
                               sc->vptr->mk_symbol(sc,"pause"),
                               sc->vptr->mk_foreign_func(sc, foreign_PAUSE));
/*PULSIN		*/
sc->vptr->scheme_define(sc,sc->global_env,
                               sc->vptr->mk_symbol(sc,"pulsin"),
                               sc->vptr->mk_foreign_func(sc, foreign_PULSIN));

/*PULSOUT		*/
sc->vptr->scheme_define(sc,sc->global_env,
                               sc->vptr->mk_symbol(sc,"rctime"),
                               sc->vptr->mk_foreign_func(sc, foreign_RCTIME));

/*RCTIME		*/
sc->vptr->scheme_define(sc,sc->global_env,
                               sc->vptr->mk_symbol(sc,"pulsout"),
                               sc->vptr->mk_foreign_func(sc, foreign_PULSOUT));


sc->vptr->scheme_define(sc,sc->global_env,
                               sc->vptr->mk_symbol(sc,"delaymicroseconds"),
                               sc->vptr->mk_foreign_func(sc, foreign_delayMicroseconds));


sc->vptr->scheme_define(sc,sc->global_env,
                               sc->vptr->mk_symbol(sc,"delaymilliseconds"),
                               sc->vptr->mk_foreign_func(sc, foreign_delayMilliseconds));


sc->vptr->scheme_define(sc,sc->global_env,
                               sc->vptr->mk_symbol(sc,"system"),
                               sc->vptr->mk_foreign_func(sc, foreign_system));


sc->vptr->scheme_define(sc,sc->global_env,
                               sc->vptr->mk_symbol(sc,"micros"),
                               sc->vptr->mk_foreign_func(sc, foreign_micros));

sc->vptr->scheme_define(sc,sc->global_env,
                               sc->vptr->mk_symbol(sc,"wiringpisetup"),
                               sc->vptr->mk_foreign_func(sc, foreign_wiringPiSetup));

}
