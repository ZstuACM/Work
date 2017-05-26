/*
	Name: 任务2 高精度计算 
	Copyright: 
	Author: lizhimin 
	Date: 20/05/17 17:08
	Description: 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10050
#define Debug_Switch 0
int a[MAX],b[MAX],c[MAX];
char s1[MAX],s2[MAX],s3[MAX];
char tmp,op1,op2;
int i,j,k,n,m,change=0;
int alen,blen,clen;

int min(int x,int y)
{
	return (x<y?x:y);
}

int max(int x,int y)
{
	return (x>y?x:y);
}

void add(int a[],int b[])
{
	for(i=1;i<=clen;i++)
		c[i]=a[i]+b[i];
	for(i=1;i<clen;i++)
		if(c[i]>=10)
		{
			//处理进位; 
			c[i+1]++;
			c[i]-=10;
		}
	for(i=clen;i>=1;i--)
		printf("%d",c[i]);
	printf("\n");
}

void sub(int a[],int b[])
{
	for(i=1;i<=alen;i++)    
		c[i]=a[i]-b[i];
	for(i=1;i<alen;i++)
		if(c[i]<0)
		{
			c[i+1]--;
			c[i]+=10;
		}    
	while(c[alen]==0 && alen!=1)
		alen--;
	for(i=alen;i>=1;i--)
		printf("%d",c[i]);
	printf("\n");
}

void mult(int a[],int b[])
{
	for(i=1;i<=alen;i++)
		for(j=1;j<=blen;j++)
			c[i+j-1]+=a[i]*b[j];
	for(i=1;i<alen+blen-1;i++)
		if(c[i]>=10)
		{
			c[i+1]+=c[i]/10;
			c[i]%=10;
		}
	for(i=alen+blen-1;i>=1;i--)
		printf("%d",c[i]);
	printf("\n");
}

void divi(int b[],int m)
{
	int blen=strlen(s2);
    for(i=0;i<blen;i++)
       b[i+1]=s2[i]-'0';
	k=b[1];i=1;
	while(k<m) 
	{
		i++;
		k=k*10+b[i];
	}
	clen=0;
	c[++clen]=k/m;
	k%=m; i++;
	for(;i<=blen;i++)
	{
		k=k*10+b[i];
		c[++clen]=k/m;
		k%=m;
	}
	for(i=1;i<=clen;i++)
		printf("%d",c[i]);
	if(k>0) printf(" mod:%d\n",k);
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	scanf("%c",&op1); gets(s1);
	scanf("%c",&op2); gets(s2);
	alen=strlen(s1);
	blen=strlen(s2);
	
	if (alen<blen) change=1;
	if (alen==blen && strcmp(s1,s2)==-1) change=1;
	if (change)
	{
		tmp=op1; op1=op2; op2=tmp;
		strcpy(s3,s1);
		strcpy(s1,s2);
		strcpy(s2,s3);
	}
	
	alen=strlen(s1); blen=strlen(s2);
	if (Debug_Switch) printf("%c",op1); 
	if (Debug_Switch) printf("%c",op2);
	
	for(i=alen-1;i>=0;i--)    
		a[alen-i]=s1[i]-'0';
	for(i=blen-1;i>=0;i--)    
		b[blen-i]=s2[i]-'0';

	if (Debug_Switch) puts(s1);  
	if (Debug_Switch) puts(s2);   
	

	clen=max(alen,blen);
	if (Debug_Switch)
		printf("%c %c alen=%d blen=%d clen=%d\n",op1,op2,alen,blen,clen);
	
	//TestArray
	if (Debug_Switch)
	{
		printf("%c",op1);
		for (i=1;i<=alen;i++)
			printf("%d",a[i]);
		printf("\n");
		printf("%c",op2);
		for (i=1;i<=blen;i++)
			printf("%d",b[i]);
		printf("\n");
	}
	
	while (scanf("%d",&n)!=EOF && n!=0)
	{
		memset(c,0,sizeof(c));
		switch (n)
		{
			case 1:
				{
					printf("和 ");
					if (op1=='+' && op2=='+')
					{ 
						add(a,b);
						break;
					}
					if (op1=='+' && op2=='-')
					{
						sub(a,b);
						break;
					}
					if (op1=='-' && op2=='+')
					{
						printf("-");
						sub(a,b);
						break;
					}
					if (op1=='-' && op2=='-')
					{
						printf("-");
						add(a,b);
						break;
					}
					break;
				}
			case 2:
				{
					printf("差 ");
					if (op1=='+' && op2=='+')
					{
						sub(a,b);
						break;
					}
					if (op1=='+' && op2=='-')
					{
						add(a,b);
						break;
					}
					if (op1=='-' && op2=='+')
					{
						printf("-");
						add(a,b);
						break;
					}
					if (op1=='-' && op2=='-')
					{
						printf("-");
						sub(a,b);
						break;
					}
					break;
				}
			case 3:
				{
					printf("积 ");
					if ((op1=='+' && op2=='-') || (op1=='-' && op2=='+'))
						printf("-");
					mult(a,b);
					break;
				}
			case 4:
				{
					printf("商 ");
					scanf("%d",&m);
					if (op2=='-')
						printf("-"); 
					divi(b,m);
					break;
				}
			default: break;
		}
	}
	
	fclose(stdin);fclose(stdout);
	return 0;
}

