/*
	Name: 任务3 找出现次数最多的单词
	Copyright: 
	Author: lizhimin 
	Date: 2017/5/22 14:23:04 
	Description: TrieTree
*/

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#define Debug_Switch 1
using namespace std;
const int MAXLEN=256;		//single string max length;
int maxnum=0;
char str2low(char ch)
{
	if ('A'<=ch && ch<='Z') return (ch+32);
	if ('a'<=ch && ch<='z') return ch;
	return (' ');
}

typedef struct TrieNode
{
	int count;
	struct TrieNode *next[MAXLEN];
}TrieNode;

void Insert(char *word,TrieNode *root)
{
	int i;
	TrieNode *cur;
	if (word[0]=='\0') return;
	cur=root;
    for(i=0;word[i]!='\0';i++)
    {
    	if(cur->next[word[i]]==NULL)
    	{
        	TrieNode *newNode = (TrieNode *)malloc(sizeof(TrieNode));
            memset(newNode,0,sizeof(TrieNode));
            cur->next[word[i]]=newNode;
        }
        cur=cur->next[word[i]];
    }
	cur->count++;
	return;
}

void Construct(TrieNode *&root)
{
	char inStr[MAXLEN];
	int size=0;
	root = (TrieNode *)malloc(sizeof(TrieNode));
	memset(root,0,sizeof(TrieNode));
	return;
}

void Traverse(TrieNode *curP)
{
    static char theWord[MAXLEN];
    static int pos=0; 
    int i;
    if(curP==NULL) return;
    if(curP->count)
    {
		theWord[pos]='\0';
		if (Debug_Switch)
			printf("%3d: %s\n",curP->count,theWord);
    	if (maxnum < curP->count)
    		maxnum = curP->count;
	}
	for(i=0;i<MAXLEN;i++)
	{
		theWord[pos++]=i;
		Traverse(curP->next[i]);
        pos--;
	}
	return;
}

void PrintAns(TrieNode *curP)
{
	static char theWord[MAXLEN];
    static int pos=0; 
    int i;
    if(curP==NULL) return;
    if(curP->count)
    {
		theWord[pos]='\0';
    	if (maxnum == curP->count)
    		printf("%3d: %s\n",curP->count,theWord);
	}
	for(i=0;i<MAXLEN;i++)
	{
		theWord[pos++]=i;
		PrintAns(curP->next[i]);
        pos--;
	}
	return;
}

bool Find(TrieNode *root,char *word)
{
	int i;
	TrieNode *cur;
	cur=root;
	for(i=0;word[i]!='\0';i++)
	{
		if(cur->next[word[i]]==NULL)
		{
			return false;
		}
		cur=cur->next[word[i]];
	}
	if(cur->count)
		return true;
	else
		return false;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w+",stdout);
	int i=0,count=0;
	char s[MAXLEN],maxstr[MAXLEN],ch;
	
	TrieNode *root;
	Construct(root);
	
	while (scanf("%c",&ch)!=EOF)
	{
		ch=str2low(ch);		//Convert all characters to lowercase;
		if (ch!=' ')
		{
			s[i++]=ch;
		}
		else
		{
			s[i]='\0'; i=0;
			Insert(s,root);
			strcpy(s,"");
		}
	}
	Traverse(root); 		//To find max;
	if (Debug_Switch) printf("\n");
	printf("The most frequently occurring word:\n");
	PrintAns(root);
	fclose(stdin); fclose(stdout);
	return 0;
}
