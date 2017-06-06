#include <stdio.h>#include <stdlib.h>#include <string.h>
struct Node{ int num;    struct Node *next;}*head,*p,*q;
void CreatList(int n,struct Node *head){ q=head; p=head; for(int i=2;i<=n;i++) {  q=(struct Node*)malloc(sizeof(struct Node)); //继续创建节点   q->num=i; //分配id   p->next=q;  //链接新的节点   p=q;  //更新节点  } p->next=head; //构造循环链表;}
void Josephus(struct Node *head,int m){ struct Node *del,*p=head,*q=head; int time=1; while(p->next!=p)  //剩下两个以上节点的时候  {  if(time==m) //q为当前节点 p为下一个节点   {   //printf("%d ",p->num);   q->next=p->next; //链接下一个节点    del=p; //将这个节点删除    p=p->next;   free(del);   time=1;  }  else  {   q=p;   p=p->next;   time++;  } } printf("%d\n",p->num);  printf("%d\n",p->num); }
int main(){ int n,m,i; while (scanf("%d",&n)!=EOF && n!=0) {  m=3;  head = (struct Node*)malloc(sizeof(struct Node));  head->num=1;  CreatList(n,head);  Josephus(head,m); } return 0;}
