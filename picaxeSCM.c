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


/* HIGH */
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
/* LOW */
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


/* PAUSE */
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

pointer foreign_delayMicroseconds(scheme * sc, pointer args)
{
  pointer first_arg;
  long usec;
  int retcode;

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
  long msec, usec;
  int retcode;

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

pointer foreign_digitalRead(scheme * sc, pointer args)
{
  pointer first_arg;
  long pin, value;

  if(args == sc->NIL)
    return sc->F;

  first_arg = sc->vptr->pair_car(args);
  if(!sc->vptr->is_integer(first_arg)) {
    return sc->F;
  }


 
  pin = sc->vptr->ivalue(first_arg);
  

  return (sc->vptr->mk_integer(sc,digitalRead(pin)));

  
}

pointer foreign_digitalWrite(scheme * sc, pointer args)
{
  pointer first_arg;
  pointer second_arg;
  long pin, value;

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
  value = sc->vptr->ivalue(second_arg);
  digitalWrite( pin, value );

  return sc->T;
}

pointer foreign_freq(scheme * sc, pointer args)
{
  pointer first_arg;
  pointer second_arg;
  long pin, duration, Ton, i, Counter, lefreq;

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




  pinMode(pin, 1);
  lefreq=2000;
  Ton = 500000 / lefreq;
  Counter = 500*duration/Ton;
  printf("%d %d",Ton,Counter);
  for (i=0;i<Counter;i++) {
	digitalWrite(pin,1);
	delayMicroseconds(Ton);
	digitalWrite(pin, 0);
	delayMicroseconds(Ton);
}	
  
  return sc->T;
}


pointer foreign_millis(scheme * sc, pointer args)
{
  
  long ret;

  if(args != sc->NIL)
    return sc->F;

  
    return (sc->vptr->mk_integer(sc,millis()));
  }


pointer foreign_pause(scheme * sc, pointer args)
{
  pointer first_arg;
  long msec, usec;
  int retcode;

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


pointer foreign_pinMode(scheme * sc, pointer args)
{
  pointer first_arg;
  pointer second_arg;
  long pin, mode;

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
  mode = sc->vptr->ivalue(second_arg);
  pinMode( pin, mode );

  return sc->T;
}

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

void init_picaxeSCM (scheme * sc)
{

wiringPiSetup();

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
                               sc->vptr->mk_symbol(sc,"digitalread"),
                               sc->vptr->mk_foreign_func(sc, foreign_digitalRead));

sc->vptr->scheme_define(sc,sc->global_env,
                               sc->vptr->mk_symbol(sc,"high"),
                               sc->vptr->mk_foreign_func(sc, foreign_HIGH));

sc->vptr->scheme_define(sc,sc->global_env,
                               sc->vptr->mk_symbol(sc,"low"),
                               sc->vptr->mk_foreign_func(sc, foreign_LOW));

sc->vptr->scheme_define(sc,sc->global_env,
                               sc->vptr->mk_symbol(sc,"millis"),
                               sc->vptr->mk_foreign_func(sc, foreign_millis));

sc->vptr->scheme_define(sc,sc->global_env,
                               sc->vptr->mk_symbol(sc,"pause"),
                               sc->vptr->mk_foreign_func(sc, foreign_PAUSE));

sc->vptr->scheme_define(sc,sc->global_env,
                               sc->vptr->mk_symbol(sc,"freq"),
                               sc->vptr->mk_foreign_func(sc, foreign_freq));

sc->vptr->scheme_define(sc,sc->global_env,
                               sc->vptr->mk_symbol(sc,"pinmode"),
                               sc->vptr->mk_foreign_func(sc, foreign_pinMode));

sc->vptr->scheme_define(sc,sc->global_env,
                               sc->vptr->mk_symbol(sc,"wiringpisetup"),
                               sc->vptr->mk_foreign_func(sc, foreign_wiringPiSetup));

}
