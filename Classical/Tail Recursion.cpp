/*
*	Name: Tail Recursion
*	Copyright: 
*	Author:  
*	Date: 2017-5-14 12:14:45 
*	Description: OK
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int fac(int n)
{
	if (n==1) return 1;
	else return (n*fac(n-1));
}
int facnew(int n,int acc)
{
	if (n==1) return acc;
	return facnew(n-1, acc * n);
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int i; int acc=1;
	for (i=1;i<=10;i++)
		cout<<fac(i)<<" "<<facnew(i,acc)<<endl;
	fclose(stdin); fclose(stdout);
	return 0;
}
