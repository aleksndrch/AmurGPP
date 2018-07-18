#include "apdefap.h"
void OnPropertyChanged(char* lpszPictureName, char* lpszObjectName, char* lpszPropertyName,  double  value)
{
#define grey "-2147483444"
#define red "-2147483410"
#define yellow "-2147483413"
#define white "-2147483432"

char *AHPostfix = ".PV_AH_Lim";
char *WHPostfix = ".PV_WH_Lim";
char *WLPostfix = ".PV_WL_Lim";
char *ALPostfix = ".PV_AL_Lim";
char *TagQCPostfix = ".TagQC";

char *TagPrefix = NULL;
char *Color = NULL;
char AH_Tag[_MAX_PATH+1] = "";
char WH_Tag[_MAX_PATH+1] = "";
char WL_Tag[_MAX_PATH+1] = "";
char AL_Tag[_MAX_PATH+1] = "";
char AL_Tag[_MAX_PATH+1] = "";
char QC_Tag[_MAX_PATH+1] = "";

float AHValue, WHValue, WLValue, ALValue;
BOOL TagQC;

// Получаем префикс тега, так как в родительском объекте требуется полное обращение к его имени
TagPrefix = GetPropChar(lpszPictureName,lpszObjectName,"tagname");	//Return-Type: char* 

// Формиуем полные имена тегов со значенями уровней
// Верхний аварийный:
strcpy(AH_Tag, TagPrefix);		//Return-Type: char* 
strcat(AH_Tag,AHPostfix);
AHValue = GetTagFloat(AH_Tag);	//Return-Type: float 
// Верхний предупредительный:
strcpy(WH_Tag, TagPrefix);		//Return-Type: char* 
strcat(WH_Tag,WHPostfix);
WHValue = GetTagFloat(WH_Tag);	//Return-Type: float 
// Нижний предупредительный:
strcpy(WL_Tag, TagPrefix);		//Return-Type: char* 
strcat(WL_Tag,WLPostfix);
WLValue = GetTagFloat(WL_Tag);	//Return-Type: float 
// Нижний аварийный:
strcpy(AL_Tag, TagPrefix);		//Return-Type: char* 
strcat(AL_Tag ,ALPostfix);
ALValue = GetTagFloat(AL_Tag);	//Return-Type: float 

// Качество переменной:
strcpy(QC_Tag, TagPrefix);		//Return-Type: char* 
strcat(QC_Tag ,TagQCPostfix);
TagQC = GetTagBit(QC_Tag);		//Return-Type: float 

//printf("\n%d\n", TagQC);

	if (TagQC){
		SetPropChar(lpszPictureName,lpszObjectName, "Value1BackColor", grey);	//Return-Type: BOOL 
	}
	else if (value > AHValue){
		SetPropChar(lpszPictureName,lpszObjectName, "Value1BackColor", red);	//Return-Type: BOOL 
	}
	else if (value > WHValue){
		SetPropChar(lpszPictureName,lpszObjectName, "Value1BackColor", yellow);	//Return-Type: BOOL 
	}
	else if (value < ALValue){
		SetPropChar(lpszPictureName,lpszObjectName, "Value1BackColor" , red);	//Return-Type: BOOL 
	} 
	else if (value < WLValue){
		SetPropChar(lpszPictureName,lpszObjectName, "Value1BackColor", yellow);	//Return-Type: BOOL 
	}
	else{
		SetPropChar(lpszPictureName,lpszObjectName, "Value1BackColor", white);	//Return-Type: BOOL 
	}
}