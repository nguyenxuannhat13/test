
#include <regx51.h>

#define led7seg P2
#define led1 P3_0
#define led2 P3_1
#define led3 P3_2
#define led4 P3_3
#define led5 P3_4
#define led6 P3_5
#define start P1_0
#define stop P1_1
#define reset P1_2
#define button1 P1_3


const unsigned char led7[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
unsigned char count,gio,phut,giay;

void delay(long x)
{
	int i;
	while(x--)
	{

for(i=0;i<123;i++)
		{}
	}
}
void timer(void) interrupt 3 using 2
{
		TH1=0xd8;
		TL1=0xf0;
		TR1=1;
		count = count +1;

	if(count >=100)
	{
		count =0;
		giay++;
	}
	if(giay>=60)
	{
		giay=0;
		phut++;
	}
	if(phut>=60)
	{
		phut =0;
		gio++;
	}
	if(gio>=24)
	{
		gio=0;
	}
}
void hien_thi(unsigned char a, 
	unsigned char b, 
		unsigned char c, 
			
	unsigned char d, 
		unsigned char e,
		unsigned char f)
{
	
	led7seg = led7[a];
	led1 = 0;
	delay(1);
	led1=1;
	
	led7seg = led7[b];
	led2=0;
	delay(1);
	led2=1;
	
	led7seg = led7[c];
	led3=0;
	delay(1);
	led3=1;
	
	led7seg = led7[d];
	led4=0;
	delay(1);
	led4=1;
	
	led7seg = led7[e];
	led5=0;
	delay(1);
	led5=1;
	
	led7seg = led7[f];
	led6=0;
	delay(1);
	led6=1;
}

void dk()
{
	if(start==0)
		{TR1=1;}
	if(stop==0)
	{TR1=0;}
	if(reset==0)
	{TR1=0;count=0;giay=0;phut=0;gio=0;}
	if(button1==0)
	{while(button1==0);
	phut++;}
}
void main(void)
{
		TMOD = TMOD | 0x10;
		TH1=0x00;
		TL1=0x10;
		ET1=1;	
	EA=1;
	while(1)
	{
		
		hien_thi(gio/10,gio%10,phut/10,phut%10,giay/10,giay%10);
		dk();
	}
}