/*
*	Name: Calling Extraterrestrial Intelligence Again
*	Copyright: 
*	Author: 
*	Date: 14/05/17 12:02
*	Description: failed 
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
bool prime[1050];
int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	
	int i,j,k;
	int m,a,b;
	memset(prime,true,sizeof(prime));
	for (i=2;i<=1000;i++)
	{
		if (prime[i])
			for (j=i+i;j<=1000;j=j+i)
				prime[j]=false;
	}
	int count=0;
	int p[200];
	for (i=2;i<=1000;i++)
	{
		if (prime[i])
		{
			p[count++]=i;
			//printf("%d->%d\n",count-1,p[count-1]);
		}
	} //count=0 to 167
	count--;
	
	int left,right,mid;
	int x,y,max; 
	while(scanf("%d%d%d",&m,&a,&b)!=EOF)
	{
		if (0==m && 0==a && 0==b) break;
		//cout<<"count="<<count<<endl;
		max=0; 
		for (i=count;i>=0;i--)
		{
			//denominator=i;
			for (j=i;j>=0;j--)
			if (p[i]*p[j]<=m && a*p[i]<=b*p[j])
			{
				//cout<<a<<"/"<<b<<" <= "<<p[j]<<"/"<<p[i]<<endl;
				//printf("%d %d\n",p[j],p[i]);
				if (p[i]*p[j]>max)
				{
					//refresh;
					x=p[j]; y=p[i]; max=p[i]*p[j]; 
				} 
			}
		}
		printf("%d %d\n",x,y);
	}
	
	//fclose(stdin); fclose(stdout);
	return 0;
}
