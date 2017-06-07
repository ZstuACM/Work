#include <cstdio>
#include <iostream>
using namespace std;
int x[50];
int back(int n)
{
	int i;
	for (i=0;i<31;i++)
	{
		if (n<=x[i])
			return (n-x[i-1]);  
	}
	return 0;
}
int f(int n)
{
	if (n==1) return 0;
	return (1-f(back(n)));
}
int main()
{
	int i,num1,num2,l,r;
	x[0]=1;
	for (i=1;i<31;i++)
		x[i]=2*x[i-1];
	
	
	for (i=0;i<31;i++)
	{
		//printf("%d\n",x[i]);
	}
	num1=0; num2=0;
	for (i=1;i<30;i++)
	{
		if (f(i)) num1++;
		printf("%d %d %d\n",i,f(i),num1);
	}
	num1=0; num2=0;
	while (scanf("%d%d",&l,&r)!=EOF)
	{
		num1=l/2;
		if (l%2 && f(l)) num1++;
		num2=r/2;
		if (r%2 && f(r)) num2++;
		printf("%d\n",num2-num1);
	}
	return 0;
} 
