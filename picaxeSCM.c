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


pointer foreign_wiringPiSetup(scheme * sc, pointer args)
{

  if(args != sc->NIL)
    return sc->F;

  wiringPiSetup();

  return sc->T;
}









/* This function gets called when TinyScheme is loading the extension */

void init_picaxeSCM (scheme * sc)
{

wiringPiSetup();

sc->vptr->scheme_define(sc,sc->global_env,
                               sc->vptr->mk_symbol(sc,"high"),
                               sc->vptr->mk_foreign_func(sc, foreign_HIGH));

sc->vptr->scheme_define(sc,sc->global_env,
                               sc->vptr->mk_symbol(sc,"low"),
                               sc->vptr->mk_foreign_func(sc, foreign_LOW));


sc->vptr->scheme_define(sc,sc->global_env,
                               sc->vptr->mk_symbol(sc,"pause"),
                               sc->vptr->mk_foreign_func(sc, foreign_PAUSE));

sc->vptr->scheme_define(sc,sc->global_env,
                               sc->vptr->mk_symbol(sc,"wiringpisetup"),
                               sc->vptr->mk_foreign_func(sc, foreign_wiringPiSetup));

}
