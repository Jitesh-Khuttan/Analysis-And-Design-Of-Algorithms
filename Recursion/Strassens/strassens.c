#include<stdio.h>
int i,j;
void strassen(int x[2][2],int y[2][2])
{
	int z[2][2],a,b,c,d,e,f,g,h;
	a=x[0][0];
	b=x[0][1];
	c=x[1][0];
	d=x[1][1];
	e=y[0][0];
	f=y[0][1];
	g=y[1][0];
	h=y[1][1];
	int p1,p2,p3,p4,p5,p6,p7;
	p1=a*(f-h);
	p2=h*(a+b);
	p3=e*(c+d);
	p4=d*(g-e);
	p5=(a+d)*(e+h);
	p6=(c-a)*(e+f);
	p7=(b-d)*(g+h);
	z[0][0]=p4+p5-p2+p7;
	z[0][1]=p1+p2;
	z[1][0]=p3+p4;
	z[1][1]=p1+p5-p3+p6;
	printf("\nResultant matrix after multiplication\n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
			printf("%d ",z[i][j]);
		printf("\n");
	}
}
int main()
{
	printf("\t\tSTRASSEN'S MATRIX MULTIPLICATION\n");
	int x[2][2],y[2][2];
	printf("Enter the first 2x2 matrix\n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
			scanf("%d",&x[i][j]);
	}
	printf("Enter the second 2x2 matrix\n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
			scanf("%d",&y[i][j]);
	}
	strassen(x,y);
	return 0;
}
