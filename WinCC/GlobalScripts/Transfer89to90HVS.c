#include "apdefap.h"

int gscAction( void )
{

#define LT01_89  "089-LT01"
#define LT02_89  "089-LT02"
#define LT03_89  "089-LT03"
#define LT04_89  "089-LT04"

#define LT01_90 "090-HVS-089LT1"
#define LT02_90 "090-HVS-089LT2"
#define LT03_90 "090-HVS-089LT3"
#define LT04_90 "090-HVS-089LT4"

float LT1, LT2, LT3, LT4; 

LT1 = GetTagFloat(LT01_89)*100;
SetTagWord(LT01_90, (WORD)LT1);

LT2 = GetTagFloat(LT02_89)*100;
SetTagWord(LT02_90, (WORD)LT2);

LT3 = GetTagFloat(LT03_89)*100;
SetTagWord(LT03_90, (WORD)LT3);

LT4 = GetTagFloat(LT04_89)*100;
SetTagWord(LT04_90, (WORD)LT4);

return 0; 
}
