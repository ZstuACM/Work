#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
int main()
{
	int T,i;
	int x,y;
	cin>>T;
	for (i=1;i<=T;i++)
	{
		scanf("%d%d",&x,&y);
		printf("Scenario #%d:\n",i);
		if ((x%2==1) && (y%2==1))
			printf("%.2lf\n",(double)x*y+sqrt(2)-1);
		else printf("%.2lf\n",(double)x*y);
		printf("\n");
	}
	return 0;
}
