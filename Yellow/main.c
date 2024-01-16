#include <REGX52.H>
#include "Delay.h"
#include "Timer0.h"
#include "LCD1602.h"

sbit Buzzer=P2^5;

#define SPEED	500

#define P	0
#define L1	1
#define L1_	2
#define L2	3
#define L2_	4
#define L3	5
#define L4	6
#define L4_	7
#define L5	8
#define L5_	9
#define L6	10
#define L6_	11
#define L7	12
#define M1	13
#define M1_	14
#define M2	15
#define M2_	16
#define M3	17
#define M4	18
#define M4_	19
#define M5	20
#define M5_	21
#define M6	22
#define M6_	23
#define M7	24
#define H1	25
#define H1_	26
#define H2	27
#define H2_	28
#define H3	29
#define H4	30
#define H4_	31
#define H5	32
#define H5_	33
#define H6	34
#define H6_	35
#define H7	36

unsigned int FreqTable[]={
	0,
	63628,63731,63835,63928,64021,64103,64185,64260,64331,64400,64463,64528,
	64580,64633,64684,64732,64777,64820,64860,64898,64934,64968,65000,65030,
	65058,65085,65110,65134,65157,65178,65198,65217,65235,65252,65268,65283,
};

//Yellow - Coldplay
unsigned char code Music0[]={
	
	M3,	4,	M3,	4+2,	M3, 2,	M3,	4,
	M3,	4,	M3,	4+2,	M3, 2,	M3,	4,
	M3,	2,	M3,	2,	M3,	2,	M3,	2,	M3,	2,	M3,	2,	M3,	2,	M3,	2,	
	M3,	2,	M3,	2,	M3,	2,	M3,	2,	M3,	2,	M3,	2,	M3,	2,	P,	2,
	0xFF
};
//Recomposed by Stella
unsigned char code Music1[]={
	
	M5,	2,	M5,	2,	M5,	2,	M5,	2,	M5,	2,	M5,	2,	M5,	2,	M5,	2,	
	M5,	2,	M4,	2,	M4,	2,	M4,	2,	M4,	2,	M4,	2,	M4,	2,	M4,	2,	
	M7,	2,	M7,	2,	M7,	2,	M7,	2,	M7,	2,	M7,	2,	M7,	2,	M7,	2,	
	M7,	2,	M6,	2,	M6,	2,	M6,	2,	M6,	2,	M6,	2,	M6,	2,	P,	2,
	0xFF
};
//This is a song for my love.
unsigned char code Music2[]={
	M2,	2,	M2,	2,	M2,	2,	M2,	2,	M2,	2,	M2,	2,	M2,	2,	M2,	2,		
	M2,	2,	M1,	2,	M1,	2,	M1,	2,	M1,	2,	M1,	2,	M1,	2,	M1,	2,		
	M5,	2,	M5,	2,	M5,	2,	M5,	2,	M5,	2,	M5,	2,	M5,	2,	M5,	2,	
	M5,	2,	M4,	2,	M4,	2,	M4,	2,	M4,	2,	M4,	2,	M4,	2,	M4,	2,
	P,	2,
	0xFF
};
//Look at the stars | I came along
unsigned char code Music3[]={
	H2,	2,	H3,	2,	H2,	2,	H3,	4,	P,	4,	
	0xFF
};
//Look how they shine for you | I wrote a song for you | So then I took my turn
unsigned char code Music4[]={
	P,	2,	H2,	2,	H3,	2,	H2,	2,	H3,	4,	H5,	4+2, 
	H2,	4+2,	P,	4+4,
	0xFF
};
//And everything you do | And all the things you do | Oh, what a thing to have done
unsigned char code Music5[]={
	P,	2,	H1,	2,	H2,	2,	H1,	2,	H2,	4,	H5,	2,	H1, 2+4,
	P,	4+4+4,
	0xFF
};
//Yeah, they were all yellow | And it was called yellow | And it was all yellow
unsigned char code Music6[]={
	P,	2+1,	M6, 1,	H1,	1,	M6,	1,	H1,	2+2,	H1,	1,	M6,	1,	M5,	4,
	P,	2,
	0xFF
};
//before "So then I took my turn"
unsigned char code Music7[]={
	M3,	2,	M3,	2,	M3,	2,	M3,	2,	M3,	2,	M3,	2,	M3,	2,	P, 2,
	0xFF
};
//[interlude]
unsigned char code Music8[]={
	M3,	2,	M3,	2,	M3,	2,	M3,	2,	M3,	2,	M3,	2,	M3,	2,		
	M4,	2,	M4,	2,	M4,	2,	M4,	2,	M3,	2,	M3,	2,	M3,	2,	M3,	2,	
	P,	4,	
	0xFF
};
//Your skin
unsigned char code Music9[]={
	H1,	4,	H6,	4+2,	H5,	2,	P,	2,	
	0xFF
};
//Oh yeah, your skin and bones
unsigned char code Music10[]={
	H1,	2,	H1,	2,	H5,	2,	H5,	2,	H3,	2,	H3, 4,	P,	4,	
	0xFF
};
//Turn into
unsigned char code Music11_1[]={
	H1, 2,	H6,	2,	H6,	4+2,	H5,	2,
	P,	2,
	0xFF
};
//something beautiful
unsigned char code Music11_2[]={
	H1,	2,	H1,	2,	H5,	2,	H5,	2,	H3,	2,	H3, 4,	P,	4,	
	0xFF
};
//Do you know
unsigned char code Music12[]={
	H1, 2,	H6,	2,	H6,	4+2,	H5,	2,	P,	2,	
	0xFF
};
//You know I love you so - 1
unsigned char code Music13[]={
	H1,	2,	H1,	2,	H5,	2,	H5,	2,	H3,	2,	H3, 4,
	M6,	4+4,	P,	4+4,
	0xFF
};
//You know I love you so - 2
unsigned char code Music14[]={
	P,	2,	H1,	2,	H1,	2,	H5,	2,	H5,	2,	H3,	2,	H3, 4,
	M5,	4+4,	P,	4+4,
	0xFF
};

char *code Lyrics0 = "Yellow-Coldplay";

char *code Lyrics1_1 = "Recomposed";
char *code Lyrics1_2 = "By Stella030";

char *code Lyrics2_1 = "\"This is a song";
char *code Lyrics2_2 = "for my love.\"";

char *code Lyrics3_1 = "Look at the";
char *code Lyrics3_2 = "stars";

char *code Lyrics4_1 = "Look how they";
char *code Lyrics4_2 = "shine for you";

char *code Lyrics5_1 = "And everything";
char *code Lyrics5_2 = "you do";

char *code Lyrics6_1 = "Yeah, they were";
char *code Lyrics6_2 = "all yellow";

char *code Lyrics7 = "I came along";

char *code Lyrics8_1 = "I wrote a song";
char *code Lyrics8_2 = "for you";

char *code Lyrics9_1 = "And all the";
char *code Lyrics9_2 = "things you do";

char *code Lyrics10_1 = "And it was";
char *code Lyrics10_2 = "called yellow";

char *code Lyrics11_1 = "So then I took";
char *code Lyrics11_2 = "my turn";

char *code Lyrics12_1 = "Oh, what a thing";
char *code Lyrics12_2 = "to have done";

char *code Lyrics13_1 = "And it was all";
char *code Lyrics13_2 = "yellow";

char *code Lyrics14 = "Your skin";

char *Lyrics15_1 = "Oh yeah, your";
char *Lyrics15_2 = "skin and bones";

char *code Lyrics16_1 = "Turn into";
char *code Lyrics16_2 = "something";
char *code Lyrics16_3 = "beautiful";

char *Lyrics17 = "Do you know";

char *code Lyrics18_1 = "You know I love";
char *code Lyrics18_2 = "you so";

unsigned char FreqSelect,MusicSelect[23];
int i;

void Broadcast(int i, unsigned char Music[])
{
	while(Music[MusicSelect[i]]!=0xFF)
	{
		FreqSelect=Music[MusicSelect[i]];
		MusicSelect[i]++;
		Delay(SPEED/4*Music[MusicSelect[i]]);
		MusicSelect[i]++;
		TR0=0;
		Delay(5);
		TR0=1;
	}
	LCD_Init();
}

void main()
{
	Timer0Init();
	
	LCD_Init();
	LCD_ShowString(1,1,Lyrics0);
	Broadcast(0,Music0);	
	
	LCD_ShowString(1,1,Lyrics1_1);	LCD_ShowString(2,5,Lyrics1_2);
	Broadcast(1,Music1);
	
	LCD_ShowString(1,1,Lyrics2_1);	LCD_ShowString(2,4,Lyrics2_2);
	Broadcast(2,Music2);

	LCD_ShowString(1,1,Lyrics3_1);	LCD_ShowString(2,1,Lyrics3_2);
	Broadcast(3,Music3);
	
	LCD_ShowString(1,1,Lyrics4_1);	LCD_ShowString(2,1,Lyrics4_2);
	Broadcast(4,Music4);
	
	LCD_ShowString(1,1,Lyrics5_1);	LCD_ShowString(2,1,Lyrics5_2);
	Broadcast(5,Music5);
	
	LCD_ShowString(1,1,Lyrics6_1);	LCD_ShowString(2,1,Lyrics6_2);
	Broadcast(6,Music6);
	
	LCD_ShowString(1,1,Lyrics7);
	Broadcast(7,Music3);
	
	LCD_ShowString(1,1,Lyrics8_1);	LCD_ShowString(2,1,Lyrics8_2);
	Broadcast(8,Music4);

	LCD_ShowString(1,1,Lyrics9_1);	LCD_ShowString(2,1,Lyrics9_2);
	Broadcast(9,Music5);
	
	LCD_ShowString(1,1,Lyrics10_1);	LCD_ShowString(2,1,Lyrics10_2);
	Broadcast(10,Music6);
	
	Broadcast(11,Music7);
	
	LCD_ShowString(1,1,Lyrics11_1);	LCD_ShowString(2,1,Lyrics11_2);
	Broadcast(12,Music4);
	
	LCD_ShowString(1,1,Lyrics12_1);	LCD_ShowString(2,1,Lyrics12_2);
	Broadcast(13,Music5);
	
	LCD_ShowString(1,1,Lyrics13_1);	LCD_ShowString(2,1,Lyrics13_2);
	Broadcast(14,Music6);
	
	Broadcast(15,Music8);
	
	LCD_ShowString(1,1,Lyrics14);
	Broadcast(16,Music9);
	
	LCD_ShowString(1,1,Lyrics15_1);	LCD_ShowString(2,1,Lyrics15_2);
	Broadcast(17,Music10);
	
	LCD_ShowString(1,1,Lyrics16_1);
	Broadcast(18,Music11_1);
	
	LCD_ShowString(1,1,Lyrics16_2);	LCD_ShowString(2,8,Lyrics16_3);
	Broadcast(22,Music11_2);
	
	LCD_ShowString(1,1,Lyrics17);
	Broadcast(19,Music12);
	
	LCD_ShowString(1,1,Lyrics18_1);	LCD_ShowString(2,1,Lyrics18_2);
	Broadcast(20,Music13);
	
	LCD_ShowString(1,1,Lyrics18_1);	LCD_ShowString(2,1,Lyrics18_2);
	Broadcast(21,Music14);
	
	TR0=0;
	while(1);
}

void Timer0_Routine() interrupt 1
{
	if(FreqTable[FreqSelect])	
	{
		TL0 = FreqTable[FreqSelect]%256;		
		TH0 = FreqTable[FreqSelect]/256;		
		Buzzer=!Buzzer;	
	}
}
