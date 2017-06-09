#include <cstdio>
#include <iostream>
using namespace std;

int x[32]={1};
int Back(int n)
{
	int i;
	for (i=0;i<31;i++)
		if (n<=x[i])
			return (n-x[i-1]);
}

int Find(int n)
{
	if (n==1) return 1;
	return(1-Find(Back(n)));
}

int Count(int n)
{
	if (n%2==0) return (n/2);
	return (Find(n)+n/2);
}

int main()
{
	int T; cin>>T;
	int i,j,l,r;
	for (i=0;i<31;i++)
		x[i+1]=2*x[i];
	while (T--)
	{
		scanf("%d%d",&l,&r);
		printf("%d\n",Count(r)-Count(l-1));
	}
	return 0;
}
