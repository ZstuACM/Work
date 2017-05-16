#include <cstdio>
#include <iostream>
#include <cstring>
#define max 1000
using namespace std;

int main()
{
	char str[max+20];
	int count=max;
	int i;
	while (scanf("%c",&str[--count])!=EOF && str[count]!='\n');
	printf("·´ĞòÊä³öÎª");
	for (i=count+1;i<max;i++)
		printf("%c",str[i]);
	return 0;
} 
