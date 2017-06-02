/*
	Name: 任务3 找出现次数最多的单词 
	Copyright: 
	Author: lizhimin 
	Date: 02/06/17 18:54
	Description: 
*/

#include <stdio.h>
#include <string.h>
#define Debug_Switch 0
const int MAX=100050;		//total string length;
const int LEN=200;			//single string max length;
char s[MAX/LEN][LEN];		//string table;
char str[LEN],ch;
int i,j,now,max;
char Str2Low(char ch)
{
	if ('A'<=ch && ch<='Z') return (ch+32);
	if ('a'<=ch && ch<='z') return ch;
	return (' ');
}
void StrSort(char s[][LEN],int line)
{
	char tmp[LEN]={0};
    int i,j;
    for (i=0; i<line; ++i)
    {
        for (j=0; j<line; ++j)
        {
            if (strcmp(s[j],s[j+1])<0)
            {
				strcpy(tmp,s[j]);
				strcpy(s[j],s[j+1]);
				strcpy(s[j+1],tmp);
			}
        }
    }
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	strcpy(str,""); i=0; j=0;
	while (scanf("%c",&ch)!=EOF)
	{
		ch=Str2Low(ch);
		if (ch!=' ')
		{
			str[i++]=ch;
		}
		else
		{
			str[i]='\0'; i=0;
			if (strcmp(str,"")!=0)
				strcpy(s[j++],str);
		}
	}
	StrSort(s,j);
	strcpy(str,s[0]);
	for (i=0;i<j;i++)
	{
		if (strcmp(str,s[i])==0)
		{
			now++;
			if (Debug_Switch) printf("%s %d\n",s[i],now);
			if (now>max)
				max=now;
		}
		else
		{
			now=0;
			strcpy(str,s[i]);		//updated the new words;
		}
	}
	printf("The most frequently occurring word:\n");
	for (i=0;i<j;i++)
	{
		if (strcmp(str,s[i])==0)
		{
			now++;
			if (now==max)
				printf("%3d: %s\n",max,s[i]);
		}
		else
		{
			now=0;
			strcpy(str,s[i]);		//updated the new words;
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}

