#include <REGX52.H>
 
 // Giao tiep 8051 voi LCD1602
 
//Khai bao chan giao tiep LCD16x2 4bit
#define LCD_RS P2_0
#define LCD_RW P2_1
#define LCD_EN P2_2
#define LCD_D4 P2_4            //Truyen du lieu qua 4 chan
#define LCD_D5 P2_5
#define LCD_D6 P2_6
#define LCD_D7 P2_7


/*Ham delay*/
void delay_us(unsigned int t)
{
	unsigned int i;
	for(i=0;i<t;i++);
}
void delay_ms(unsigned int t)	
{
	unsigned int i,j;
	for(i=0;i<t;i++)
		for(j=0;j<123;j++);
}


/*Chuong trình giao tiep LCD 16x2 4bit*/
void LCD_Enable(void)
{
	LCD_EN =1;
	delay_us(3);
	LCD_EN=0;
	delay_us(50);
}
void LCD_Send4Bit(unsigned char Data)
{
	LCD_D4=Data & 0x01;
	LCD_D5=(Data>>1)&1;
	LCD_D6=(Data>>2)&1;
	LCD_D7=(Data>>3)&1;
}
void LCD_SendCommand(unsigned char command)
{
	LCD_Send4Bit(command >>4);
	LCD_Enable();
	LCD_Send4Bit(command);
	LCD_Enable();
}
void LCD_Clear()
{
	LCD_SendCommand(0x01);
	delay_us(10);
}
void LCD_Init()
{
	LCD_Send4Bit(0x00);
	delay_ms(20);
	LCD_RS=0;
	LCD_RW=0;
	LCD_Send4Bit(0x03);
	LCD_Enable();
	delay_ms(5);
	LCD_Enable();
	delay_us(100);
	LCD_Enable();
	LCD_Send4Bit(0x02);
	LCD_Enable();
	LCD_SendCommand( 0x28 );
	LCD_SendCommand( 0x0c);
	LCD_SendCommand( 0x06 );
	LCD_SendCommand(0x01);
}
void LCD_Gotoxy(unsigned char x, unsigned char y)
{
	unsigned char address;
	if(!y) 
		address=(0x80+x);
	else 
		address=(0xc0+x);
		delay_us(1000);
		LCD_SendCommand(address);
		delay_us(50);
}
void LCD_PutChar(unsigned char Data)
{
	LCD_RS=1;
	LCD_SendCommand(Data);
	LCD_RS=0 ;
}
void LCD_Puts(char *s)
{
	while (*s)
	{
		LCD_PutChar(*s);
		s++;
	}
}

void num_dsp( float number)// Hien thi 1 so luon thay doi
{
    unsigned char str[5];
	sprintf(str,"%3.0f",number);
	LCD_Puts(str);
}
 
 int i;
 
void main()
{
	LCD_Init();
	while(1)
	{
	LCD_Gotoxy(0,0);
	LCD_Puts("ngay: 13/3/2021");
	LCD_Clear();
	for(i=0;i<=100;i++)
	{
		LCD_Gotoxy(5,0);
		num_dsp(i);
		delay_ms(100);
	}
	}
}
