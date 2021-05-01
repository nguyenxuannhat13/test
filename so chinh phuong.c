
/*-------------------
Kiem tra so chinh phuong
Ngay 5/1/2021


---------------------*/

#include <stdio.h>
#include <conio.h>

int main()
{
	int x,i;
	printf("\n Nhap x: ");
	scanf("%d",&x);
	for(i=1;i<=x;i++)
	{
		if(i*i==x)
		{
			printf("\n X la so chinh phuong");
			getch();
			return 0;
		}
	}
	printf("\n X khong phai so chinh phuong");
	getch();
	return 0;
}
