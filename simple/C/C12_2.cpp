#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	char str[200];
	gets(str);
	int n,x,i,j,len;
	while (scanf("%d%d",&n,&x)!=EOF)
	{
		for (i=n;i<n+x;i++)
		{
			//cout<<n<<"  "<<n+x<<endl;
			for (j=n;j<strlen(str);j++)
			{
				str[j]=str[j+1];
				//printf("%s\n",str);
			}
		}
		printf("%s\n",str);
	}
	return 0;
}
