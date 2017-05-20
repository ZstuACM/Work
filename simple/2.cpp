#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXN 256
#define MAXLEN 256
using namespace std;
const int MAX=100050;		//total string length;
const int LEN=200;			//single string max length;
char s[MAX];
int st=1;
int i=0,j;
int n=0,line=0,k=0;
int max=0,now=0;			//count the (words number) && (max);  
char str[MAX];				//all words;
char strnow[LEN];
char strmax[LEN];			//record the max frequence words;
char strs[MAXLEN];

typedef struct TrieNode
{
	int count;
	struct TrieNode *next[MAXN];
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
	/*for (i=0;i<line;i++)
	{
		Insert(s[i],root);
	}*/
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
		printf("%s:%d\n",theWord,curP->count);
		
		if ( max<= curP->count )
		{
			max=curP->count;
			strcpy(strmax,theWord);	
		}
    }
	for(i=0;i<MAXN;i++)
	{
		theWord[pos++]=i; 
		Traverse(curP->next[i]); 
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
	//freopen("output.txt","w+",stdout);

	TrieNode *root;

	while (scanf("%c",&s[i])!=EOF)
	{
		if(s[i]>='A'&&s[i]<='Z'||s[i]>='a'&&s[i]<='z')
		{
			st=1;
			printf("%c",s[i]);
			strnow[k++]=s[i];
		}
		else
		{
			if(st==1)
			{
				printf("\n");
				strnow[k++]='\0';
				printf("%s\n",strnow);
				//Insert(strnow,root);
				n++; k=0;
			}
			st=0;
		}
		i++;
	}
	printf("Total has %d words.\n",n);

	//initialization array--------
	memset(s,'\0',sizeof(s));
	memset(strmax,'\0',sizeof(strmax));
	
	//Construct(root);
	//printf("\n");
	//Traverse(root);
	printf("frequently words is:\"%s\":%d\n",strmax,max);
	fclose(stdin); fclose(stdout);
	return 0;
}

