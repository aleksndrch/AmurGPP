#include "apdefap.h"
void OnPropertyChanged(char* lpszPictureName, char* lpszObjectName, char* lpszPropertyName,  long  value)
{
#define NOALARM_MAX	 65536
#define NOALARM_MIN	 -65536
#define ALARM_ON	1
#define ALARM_OFF	0

// Соберем переменные аварий:
char RLim[_MAX_PATH+1]  = "";
char RPrefix[] = ".PV_";
char RPostfix[] = "_Lim";

char FLim[_MAX_PATH+1]  = "";
char FPrefix[] = ".PV_";
char FPostfix[] = "_FakeLim";

char* AlarmType = GetPropChar(lpszPictureName,lpszObjectName, "AlarmType");

// Реальное значение используемое в AnalogAlarm
strcat(RLim, RPrefix);
strcat(RLim, AlarmType);	//Return-Type: char* 
strcat(RLim, RPostfix);

//Фиктивное, для отображения оператору
strcat(FLim, FPrefix);
strcat(FLim, AlarmType);	//Return-Type: char* 
strcat(FLim, FPostfix);

	if (value == ALARM_ON){
		SetTagFloat(RLim,GetTagFloat(FLim));
	}
	else{
		if(strcmp(AlarmType,"AH") == 0 || strcmp(AlarmType,"WH") == 0){
			SetTagFloat(RLim, NOALARM_MAX);
		}
		else{
			SetTagFloat(RLim, NOALARM_MIN);
		}
	}
}