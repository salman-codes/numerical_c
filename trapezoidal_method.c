// WAP to find the roots of non-linear equations using following methods-

// WAP to find out numerical integration using following methods-
// Trapezoidal Method

#include <stdio.h>
#include <conio.h>
#include <math.h>
float f(float x)
{
	return(1/(1+x*x));
}
void main()
{
	char c;
	int n,i;
	float t,sum,x[100],y[100],a,b,h;
	clrscr();
	printf("Enter lower limit to integrate 1/(1+x^2):\n");
	scanf("%f",&a);
	printf("Enter upper limit to integrate 1/(1+x^2):\n");
	scanf("%f",&b);
	do
	{
		printf("Enter number of parts <100 into which the interval (%f,%f)is to be divided:\n",a,b);
		scanf("%d",&n);
		x[0]=a;
		h=(b-a)/n;
		y[0]=f(x[0]);
		for(i=1;i<=n;i++)
		{
			x[i]=x[0]+i*h;
			y[i]=f(x[i]);
		}
		printf("Data points (xi,yi);\n");
		for(i=0;i<=n;i++)
			printf("x[%d]=%f\t,y[%d]=%f\n",i,x[i],i,y[i]);
		sum=0;
		for(i=1;i<n;i++)
			sum=sum+y[i];
		t=h*(y[0]+y[n]+2*sum)/2;
		printf("\nIntegration of 1/(1+x^2) from %f to %f by %d parts=%f\n",a,b,n,t);
		printf("Actual answer is %f\n",atan(b)-atan(a));
		printf("Do you want to change no of parts (y/n)?\n");
		c=getch();
	}
	while(c=='Y'||c=='y');
}