#ifndef __LCD1602_H__
#define __LCD1602_H__

void LCD_Init(void);
void LCD_ShowString(unsigned char Line,unsigned char Column,unsigned char *String);

#endif
