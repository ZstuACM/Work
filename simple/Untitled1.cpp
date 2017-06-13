#include <cstdio>
#include <iostream>
#include <cstdlib>
typedef struct Node{
	int num;
	struct Node *next=NULL;
}*LinkList,*pNode;

LinkList GetEmptyList()
{
    LinkList head = (pNode)malloc(sizeof(struct Node)); 
    head->next = NULL; 
    return head; 
}

void AddNode(LinkList head, pNode newnode)
{ 
    newnode->next = head->next; 
    head->next = newnode;
}

void ShowList(LinkList head)
{
	pNode p = head->next; 
    while(p)
	{
        printf("%d ",p->num ); 
        p = p->next;
    }
}

int main()
{
	int num;
	int n=50,i;
	LinkList head = GetEmptyList();
	pNode newnode;
	for (i=1;i<=n;i++)
	{
		newnode = (pNode)malloc(sizeof(struct Node));
		newnode->num =i;
		AddNode(head,newnode);	
	}
	ShowList(head);
	return 0;
}
