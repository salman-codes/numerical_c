// Simpson’s 3/8 Rule Method

#include <stdio.h>
#include <conio.h>
float y(float x)
{
	return 1/(1+x*x);
}
void main()
{
	float x0,xn,h,s;
	int i,n,j,flag;
	clrscr();
	printf("Enter x0, xn, no. of subintervals:\n");
	scanf("%f%f%d",&x0,&xn,&n);
	h=(xn-x0)/n;
	s=y(x0)+y(xn);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i==3*j)
			{
				flag=1;
				break;
			}
			else
				flag=0;
		}
		if(flag==0)
			s+=3*y(x0+i*h);
		else
			s+=2*y(x0+i*h);
	}
	printf("Value of integral is:%6.4f",(3*h/8)*s);
	getch();
}