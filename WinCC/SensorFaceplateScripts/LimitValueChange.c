#include "apdefap.h"
void OnPropertyChanged(char* lpszPictureName, char* lpszObjectName, char* lpszPropertyName,  char*  value)
{
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
BOOL AlarmPermission = GetPropBOOL(lpszPictureName,lpszObjectName, "SelectedBoxes");

//Реальное значение используемое в AnalogAlarm
strcat(RLim, RPrefix);
strcat(RLim, AlarmType);	//Return-Type: char* 
strcat(RLim, RPostfix);

//Фиктивное, для отображения оператору
strcat(FLim, FPrefix);
strcat(FLim, AlarmType);	//Return-Type: char* 
strcat(FLim, FPostfix);

	if (AlarmPermission == ALARM_ON){
		SetTagFloat(RLim,GetTagFloat(FLim));
	}
}