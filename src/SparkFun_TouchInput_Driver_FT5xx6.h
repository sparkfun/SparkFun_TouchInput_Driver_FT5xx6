



#ifndef SF_TOUCHINPUT_DRIVER_FT5xx6_H
#define SF_TOUCHINPUT_DRIVER_FT5xx6_H

#include "SparkFun_TouchInput.h"
#include "SparkFun_FT5xx6.h"


// FT5xx6
class sfti_driver_ft5xx6: public sfti_driver{
public:
  FT5xx6* plldrv;
  sfti_record getLastRecord( void );
  bool     hasNewTouch( void );
  sfti_driver_ft5xx6();
};



#endif /* SF_TOUCHINPUT_DRIVER_FT5xx6_H */