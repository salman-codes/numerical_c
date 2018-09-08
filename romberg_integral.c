// Romberg Integral-

#include <stdio.h>
#include <conio.h>
#include <math.h>
typedef enum { false, true} boolean;
float f(float x)
{
	return (x*x+2.0*x);
}
void main()
{
	int i=1,j,k,m=1,n;
	float r[20][20],a,b,h,x,eps,sum,temp;
	boolean flag;
	clrscr();
	printf("Enter lower limit of integration: ");
	scanf("%f",&a);
	printf("Enter upper limit of integration: ");
	scanf("%f",&b);
	printf("Enter allowed precision: ");
	scanf("%d",&n);
	h=b-a;
	sum=(f(a)+f(b))/2;
	r[i][1]=h * sum;
	flag=false;
	while(flag==false)
	{
		m*=2;
		h/=2;
		i++;;
		for(j=1; j<n; j+=2)
		{
			x=a+j*h;
			sum=sum+f(x);
		}
		r[i][1]=h * sum;
		for(k=2; k<n; k++)
		{
			temp=pow((double)4, (double)k-1);
			r[i][k]=(temp * r[i][k-1]-r[i-1][k-1])/(temp-1);
		}
		if(fabs(r[i][i]-r[i][i-1])<=eps)
		{
			printf("\nElements of Romberg table are\n\n");
			for(k=1; k<=i; k++)
			{
				for(j=1; j<=k; j++)
					printf("%6.4f  ",r[k][j]);
				printf("\n");
			}
			flag=true;
		}
	}
	printf("\nvalue of the integral=%10.4f",r[i][i]);
getch();
}
