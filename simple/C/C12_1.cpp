#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	char str[200],aim[200],fin[200];
	int n,i;
	gets(str);
	scanf("%d",&n); getchar();
	gets(aim);
	for (i=0;i<n;i++)
		fin[i]=str[i];
	for (i=0;i<strlen(aim);i++)
		fin[i+n]=aim[i];
	fin[i+n+1]='\0';
	printf("%s",fin);
	return 0;
}
