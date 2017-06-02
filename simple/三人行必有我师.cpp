#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;
int is_prime(int n)
{
	if (n<=1) return 0;
	int flag=1,i;
	for (i=2;i<=sqrt(n);i++)
	{
		if (n % i==0)
		{
			flag=0;
			break;
		}
	}
	return flag;
}
int main()
{
	int i,ans;
	int a,b,c;
	while (scanf("%d%d%d",&a,&b,&c)!=EOF)
	{
		ans=is_prime(a)+is_prime(b)+is_prime(c);
		if (ans>=2)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}
