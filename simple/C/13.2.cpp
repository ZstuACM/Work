#include <cstdio>
#include <iostream>
using namespace std;
#define max 10
int main()
{
	//freopen("13.2.in","r",stdin);
	//freopen("13.2.out","w",stdout);
	int x[100];
	int *p; int n,i,j,flag=0;
	for (i=0;i<max;i++)
		scanf("%d",&x[i]);
	p=&x[0];
	while (scanf("%d",&n)!=EOF)
	{
		for (i=0;i<max;i++)
			if (*(p+i)==n)
			{
				flag++;
				for (j=i;j<max;j++)
					x[j]=x[j+1];
				break;
			}
	}
	if (!flag) printf("查无此数\n");
	else 
		for (int i=0;i<max-flag;i++)
			printf("%d ",*(p+i));
		
	//fclose(stdin); fclose(stdout);
	return 0;
}
