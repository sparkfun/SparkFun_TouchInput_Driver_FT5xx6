


#include "SparkFun_TouchInput_Driver_FT5xx6.h"

sfti_driver_ft5xx6::sfti_driver_ft5xx6( void ) : sfti_driver()
{
  plldrv = NULL;
}

sfti_record sfti_driver_ft5xx6::getLastRecord( void )
{
//  SERIAL_PORT.println("returning a record");

  FT5xx6_TouchRecord_TypeDef llrecord = plldrv->read();

  uint8_t numTouches = llrecord.numTouches;
  retRecord.numTouches = numTouches;
  switch(numTouches)
  {
    case 5 : 
      (retRecord.pcoords + 4)->x = (float)llrecord.t5x;
      (retRecord.pcoords + 4)->y = (float)llrecord.t5y;
    case 4 :
      (retRecord.pcoords + 3)->x = (float)llrecord.t4x;
      (retRecord.pcoords + 3)->y = (float)llrecord.t4y;
    case 3 :
      (retRecord.pcoords + 2)->x = (float)llrecord.t3x;
      (retRecord.pcoords + 2)->y = (float)llrecord.t3y;
    case 2 :
      (retRecord.pcoords + 1)->x = (float)llrecord.t2x;
      (retRecord.pcoords + 1)->y = (float)llrecord.t2y;
    case 1 :
      (retRecord.pcoords + 0)->x = (float)llrecord.t1x;
      (retRecord.pcoords + 0)->y = (float)llrecord.t1y;
      break;
    default :
      break;
  }
  retRecord.timestamp = llrecord.timestamp;

//  SERIAL_PORT.print(retRecord.timestamp);
  
  return retRecord;
}