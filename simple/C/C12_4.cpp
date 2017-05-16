#include <cstdio>
#include <iostream>
#include <cstring>
#define max 1000
using namespace std;

int main()
{
	char str1[max+20];
	char str2[max+20];
	int i;
	int len1=0,len2=0;
	printf("请输入第一个字符串:");
	while (scanf("%c",&str1[len1++]) && str1[len1-1]!='\n');
	printf("\n"); 
	printf("请输入第二个字符串:");
	while (scanf("%c",&str2[len2++]) && str2[len2-1]!='\n');
	printf("\n"); 
	
	printf("连接后的字符串为:");
	for (i=0;i<len1-1;i++)
		printf("%c",str1[i]);
	for (i=0;i<len2-1;i++)
		printf("%c",str2[i]);
	return 0;
} 
