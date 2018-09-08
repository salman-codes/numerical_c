#include<stdio.h>
#include<conio.h>
#include<math.h>
#define f(x) (x)*(x)+(x)-2
#define f(x) (x)*(x)-4*(x)-10
#define f(x) 0.2*(x)*(x)-(x)+0.8
#define g(x) 0.3*(x)*(y)*(y)-(y)+0.7
#define x(x,y) 0.2*(x)*(x)+0.8
#define y(x,y) 0.3*(x)*(y)*(y)+0.7
#define f1(x,y) 0.4*(x)
#define f2(x,y) 0
#define g1(x,y) 0.3*(y)*(y)
#define g2(x,y) 0.6*(x)*(y)
#define f(x) 3*x-cos(x)-1
#define df(x) 3+sin(x)
char item[][100]={"Bisection Method","Regular False Method","Newton-Raphson Method","Secant Method","Fixed Point Method","Newton-Raphson Method For Multiple Roots","Exit"};
void bisect();
void false();
void newton();
void secant();
void fixed();
void newton2();
void menu(int);
void main()
{
	int pos=0;
	char key;
	while(1)
	{
		clrscr();
		_setcursortype(_NOCURSOR);
		menu(pos);
		key=getch();
		if(key==72)		//check for up arrow key
			pos--;
		else if(key==80)	//check for down arrow key
			pos++;
		else if(key==27)	//check for Esc key
			break;
		else if(key==13)
		{
			_setcursortype(_NORMALCURSOR);
			if(pos==0)
				bisect();
			else if(pos==1)
				false();
			else if(pos==2)
				newton();
			else if(pos==3)
				secant();
			else if(pos==4)
				fixed();
			else if(pos==5)
				newton2();
			else if(pos==6)
			{
				clrscr();
				printf("\n Exiting from program");
				getche();
				break;
			}
		}
		if(pos>6)
			pos=0;
		if(pos<0)
			pos=6;
		menu(pos);
	}
}
////////////////////
void menu(int pos)
{
	int x=25, y=5,i;
	clrscr();
	textcolor(GREEN);
	gotoxy(x,y);
	cprintf("****MENU****");
	for(i=0;i<7;i++)
	{
		gotoxy(x,y+=2);
		if(i==pos)
		{
			textbackground(RED);
			textcolor(BLUE);
		}
		else
		{
			textbackground(BLACK);
			textcolor(RED);
		}
		cprintf("%s",item[i]);
	}
	textbackground(BLACK);
	textcolor(WHITE);
	gotoxy(x,++y);
	cprintf(" ");
}
/////////////
void bisect()
{
	int count=0;
	float fx,fa,fb,a,b,r1,root;
	clrscr();
	printf("Enter starting values:");
	scanf("%f%f",&a,&b);
	fa=f(a);
	fb=f(b);
	if(f(a)*f(b)>0)
		printf("Starting points do not have any root");
	else
	{
		do
		{
			printf("\nIteration=%d\tRoot=%6.4f\tf(root)=%6.4f",count,root,f(root));
			count+=1;
			r1=root;
			root=(a+b)*0.5;		//formula for bisection method
			fx=f(root);
			if(fx==0)
				break;
			else if(fa*fx<0)
				b=root;
			else
			{
				a=root;
				fa=fx;
			}
		}
		while(fabs(r1-root)>0.0001);
	}
	getch();
}
//////////////
void false()

{
	int count=0;
	float fx,fa,fb,a,b,r1,root;
	clrscr();
	printf("Enter starting values:");
	scanf("%f%f",&a,&b);
	fa=f(a);
	fb=f(b);
	if(f(a)*f(b)>0)
		printf("Starting points do not have any root");
	else
	{
		do
		{
			printf("\nIteration=%d\tRoot=%6.4f\tf(root)=%6.4f",count,root,f(root));
			count+=1;
			r1=root;
			root=a-f(a)*(b-a)/(fb-fa);		//formula for false method
			fx=f(root);
			if(fx==0)
				break;
			else if(fa*fx<0)
				b=root;
			else
			{
				a=root;
				fa=fx;
			}
		}
		while(fabs(r1-root)>0.0001);
	}
	getch();
}
///////////////
void newton()
{
	int n;
	float x1,x0,f1,f0,df0,EPS,error;
	int i=1,itr;
	clrscr();
	printf("\n\n\n\t\t==============================\n");
	printf("Solution by NEWTON RAPHSON METHOD\n");
	printf("Equation is 3*x-cos(x)-1=0\n");
	printf("Enter the no. of iterations:\n");
	scanf("%d",&n);

	for(x1=0.0;;x1+=0.01)
	{
		f1=f(x1);
		if(f1>0)
			break;
	}
	itr=n;
	x0=x1-0.01;
	f0=f(x0);
	printf("Enter the maximum possible error:\n");
	scanf("%f",&EPS);
	if(fabs(f0)>f1)
		printf("\t\tThe root is near to %.4f\n\n\n",x1);
	if(f1>fabs(x0))
		printf("\t\tThe root is near to %.4f\n\n\n",x0);
	x0=(x0+x1)/2;
	for(;i<=itr;i++)
	{
		f0=f(x0);
		df0=df(x0);
		x1=x0-(f0/df0);
		printf("\t\tThe %d approximation to the root is :%f\n",i,x1);
		error=fabs(x1-x0);
		if(error<EPS)
			break;
		x0=x1;
	}
	if(error>EPS)
		printf("The no. of iterations are not sufficient");
	printf("\n\n\n\t\t==============================\n");
	printf("\t\tROOT=%.4f",x1);
	getch();
}
///////////////
void secant()
{
	float x1,x2,x3,f1,f2,t;
	clrscr();
	printf("Enter starting values:");
	scanf("%f%f",&x1,&x2);
	do
	{
		f1=f(x1);
		f2=f(x2);
		x3=x2-((f2*(x2-x1))/(f2-f1));
		printf("\nx1=%6.4f\tx2=%6.4f\tx3=%6.4f\tf(x1)=%6.4f\tf(x2)=%6.4f",x1,x2,x3,f(x1),f(x2));
		x1=x2;
		x2=x3;
		if(f2<0)
			t=fabs(f2);
		else
			t=f2;
	}
	while(t>0.0001);
	printf("\nApp.root=%f",x3);
	getch();
}
///////////////
void fixed()
{
	float x1,y1,y2,x2,x,y;
	int i=1;
	clrscr();
	do
	{
		printf("Enter starting values:");
		scanf("%f%f",&x,&y);
	}
	while(fabs(f1(x,y)+f2(x,y))>1 && fabs(g1(x,y)+g2(x,y))>1);
	x1=x(x,y);
	y1=y(x,y);
	printf("\nx=%f",x1);
	printf("\ny=%f",y1);
	printf("\n\n");
	do
	{
		x2=x(x1,y1);
		y2=y(x1,y1);
		if(fabs(x1-x2))
		{
			printf("\n\nReal Root1=%6.4f",x1);
			printf("\n\nReal Root2=%6.4f",y1);
			i=0;
		}
		else
		{
			x1=x2;
			y1=y2;
		}
		if(i==1)
		{
			printf("\nx=%f",x1);
			printf("\ny=%f",y1);
			printf("\n\n");
		}
	}
	while(i!=0);
	getch();
}