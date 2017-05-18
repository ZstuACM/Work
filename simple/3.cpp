#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int MAX=100050;
const int LEN=200;
char str[MAX];//all words
char s[MAX/LEN][LEN];//string table
 
int is_del(char ch)
{
	if (ch=='.' || ch==',' || ch=='\n' || ch=='\0')
		return 1;
	return 0;
}

void str_sort(char s[][LEN],int line)
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
	
	int n=0,i,j;
	//stdin;
	while (scanf("%c",&str[n++])!=EOF)
	{
		if (is_del(str[n-1]))
			str[n-1]=' ';
	}
	str[n]=' '; //add end space to string;
	
	//cheak stdin;
	for (i=0;i<n;i++)
	{
		printf("%c",str[i]);
	}
	printf("\n");
	
	//initialization
	int line=0;
	for (i=0; i<MAX/LEN; i++)
		for (j=0; j<LEN; j++)
			s[i][j]='\0';

	//separate string
	int k=0;
	for (i=0;i<n;i++)
	{
		if (str[i]==' ')
		{
			k=0; //init k,add new line;
			printf("%6d\n",line);
			line++;
		}
		else
		{
			printf("%c",str[i]);
			s[line][k++]=str[i];
		}
	}
	
	//cheak string table
	for (i=0;i<line;i++)
	{
		printf("%s  ",s[i]);
		printf("%6d\n",i);
	}
	
	//string sorting
	str_sort(s,line);
	
	//cheak sorting
	for (i=0;i<line;i++)
	{
		printf("%s  ",s[i]);
		printf("%6d\n",i);
	}
	//count max words length
	int max=0;
	char strnow[LEN];
	strcpy(strnow,s[0]);
	for (i=0;i<line;i++)
	{
		if (strcmp(strnow,s[i])==0)
			max++;
		else break;
	}
	
	printf("%d %s\n",max,str);
	
	fclose(stdin); fclose(stdout);
	return 0;
}
