

/*----------------------

Kiem tra so nguyen to
Ngay 5/1/2021

-----------------------*/

#include <stdio.h>
#include <conio.h>
#include <math.h>

int main()
{
	int i,x,dem=0;
	printf("\n Nhap x: ");
	scanf("%d",&x);
	for(i=1;i<=x;i++)
	{
		if(x%i==0)
		{
			dem++;
		}
	}
	if(dem==2)
	{
		printf("\n X la so nguyen to");
	}
	else
	{
		printf("\n X khong la so nguyen to");
	}
	getch();
	return 0;
}

