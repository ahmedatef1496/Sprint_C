/*
 * IncFile1.h
 *
 * Created: 4/1/2023 3:55:25 PM
 *  Author: atef
 */ 


#ifndef INCFILE1_H_
#define INCFILE1_H_

 



 
#include "../../MCAL/dio/dio.h"
 #include "LCD_Interface.h"
 #include "LCD_Cfg.h"
 
 
 
 void LCD_Init(void);


 void LCD_WriteChar(u8 ch);
 void LCD_WriteString(u8*str);
 void LCD_WriteNumber(i32 num);
 void LCD_WriteBinary(u8 num);
 void LCD_WriteHex(u8 num);
 void LCD_SetCursor(u8 line,u8 cell);
 void LCD_Clear(void);
 void LCD_ClearLoc(u8 line ,u8 cell,u8 num);
  void LCD_WriteNumber_3D(u16 num);
  void LCD_CustomChar(u8 loc,u8*pattern);



#endif /* INCFILE1_H_ */