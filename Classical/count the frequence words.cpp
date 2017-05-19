#include <stdio.h>
#include <string.h>
const int MAX=100050;		//total string length;
const int LEN=200;			//single string max length;
char str[MAX];				//all words;
char s[MAX/LEN][LEN];		//string table;
char strnow[LEN];
char strmax[LEN];			//record the max frequence words; 
int i,j;
int n=0,line=0,k=0;
int max=0,now=0;			//count the (words number) && (max);  

int is_del(char ch)
{
	//  if (!letter) return 1; 
	if ('A'<ch && ch<'Z') return 0;
	if ('a'<ch && ch<'z') return 0;
	return 1;
}

void str_sort(char s[][LEN],int line)
{
	//Two-dimensional array String sorting; 
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
	
	//stdin-----------------------
	while (scanf("%c",&str[n++])!=EOF)
	{
		if (is_del(str[n-1]))
			str[n-1]=' ';
	}
	str[n]=' ';						//add end space to string;

	//initialization array--------
	memset(s,'\0',sizeof(s));
	
	//separate string-------------
	for (i=0; i<n; i++)
	{
		if (str[i]==' ')
		{
			line++; k=0; 			//add new line;
			//printf("%6d\n",line);
		}
		else
		{
			s[line][k++]=str[i]; 	//add new char;
			//printf("%c",str[i]);
		}
	}
	
	//cheak string table----------
	for (i=0;i<line;i++)
	{
		//printf("%s  %6d\n",s[i],i);
	}
	
	//string sorting--------------
	str_sort(s,line);
	
	//printf("init line:%d\n",line);
	for (i=0;i<line;i++)
	{
		if (strcmp(s[i],"")==0)		//delete space;
		{
			line=i;
			break;
		}
	}
	//printf("final line:%d\n",line);
	
	//cheak sorting----------------
	/*
	for (i=0;i<line;i++)
	{
		printf("%d ",i);
		printf("%s\n",s[i]);
	}
	*/
	 
	//count max words length-------
	strcpy(strnow,s[0]);
	for (i=0;i<line;i++)
	{
		//printf("%s",s[i]);
		if (strcmp(strnow,s[i])==0)
		{
			now++;
			//printf("%s %d\n",s[i],now);
			if (now>max)
			{
				max=now;
				//printf("%d %d",max,now);
				strcpy(strmax,s[i]);	//updated the most frequently words;
			}
		}
		else
		{
			now=0;
			strcpy(strnow,s[i]);		//updated the new words;
		}
	}
	
	printf("The most frequently occurring word %d times \"%s\"\n",max,strmax);
	
	fclose(stdin); fclose(stdout);
	return 0;
}

