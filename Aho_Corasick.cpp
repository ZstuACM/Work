#include<iostream>
#include<string.h>
#include<malloc.h>
#include <queue>
using namespace std;

typedef struct node{
    struct node *next[26];  //���յ�̬
    struct node *par;   //���׽ڵ�
    struct node *fail;  //ʧ�ܽڵ�
    char inputchar;
    int patterTag;    //�Ƿ�Ϊ�ɽ���̬
    int patterNo;   //����̬��Ӧ�Ŀɽ���ģʽ
}*Tree,TreeNode;
char pattern[4][30]={"nihao","hao","hs","hsr"};

/**
�����µĽڵ㣬�����г�ʼ��
*/
TreeNode *getNewNode()
{
    int i;
    TreeNode* tnode=(TreeNode*)malloc(sizeof(TreeNode));
    tnode->fail=NULL;
    tnode->par=NULL;
    tnode->patterTag=0;
    for(i=0;i<26;i++)
        tnode->next[i]=NULL;
    return tnode;
}

/**
��Trie���У�root�ڵ�ķ�֧�ڵ㣬�������
*/
int  nodeToQueue(Tree root,queue<Tree> &myqueue)
{
    int i;
    for (i = 0; i < 26; i++)
    {
        if (root->next[i]!=NULL)
            myqueue.push(root->next[i]);
    }
    return 0;
}

/**
����trie��
*/
Tree buildingTree()
{
    int i,j;
    Tree root=getNewNode();
    Tree tmp1=NULL,tmp2=NULL;
    for(i=0;i<4;i++)
    {
        tmp1=root;
        for(j=0;j<strlen(pattern[i]);j++)   ///��ÿ��ģʽ���д���
        {
            if(tmp1->next[pattern[i][j]-'a']==NULL) ///�Ƿ��Ѿ��з�֧��Trie���ýڵ�
            {
                tmp2=getNewNode();
                tmp2->inputchar=pattern[i][j];
                tmp2->par=tmp1;
                tmp1->next[pattern[i][j]-'a']=tmp2;
                tmp1=tmp2;
            }
            else
                tmp1=tmp1->next[pattern[i][j]-'a'];
        }
        tmp1->patterTag=1;
        tmp1->patterNo=i;
    }
    return root;
}

/**
����ʧ��ָ��
*/
int buildingFailPath(Tree root)
{
    int i;
    char inputchar;
    queue<Tree> myqueue;
    root->fail=root;
    for(i=0;i<26;i++)   ///��root����ĵڶ���������⴦��
    {
        if (root->next[i]!=NULL)
        {
            nodeToQueue(root->next[i],myqueue);
            root->next[i]->fail=root;
        }
    }

    Tree tmp=NULL,par=NULL;
    while(!myqueue.empty())
    {
        tmp=myqueue.front();
        myqueue.pop();
        nodeToQueue(tmp,myqueue);

        inputchar=tmp->inputchar;
        par=tmp->par;

        while(true)
        {
            if(par->fail->next[inputchar-'a']!=NULL)
            {
                tmp->fail=par->fail->next[inputchar-'a'];
                break;
            }
            else
            {
                if(par->fail==root)
                {
                    tmp->fail=root;
                    break;
                }
                else
                    par=par->fail->par;
            }
        }
    }
    return 0;
}

/**
���ж�ģʽ����������ѰAC�Զ���
*/
int searchAC(Tree root,char* str,int len)
{
    TreeNode *tmp=root;
    int i=0;
    while(i < len)
    {
        int pos=str[i]-'a';
        if (tmp->next[pos]!=NULL)
        {
            tmp=tmp->next[pos];
            if(tmp->patterTag==1)    ///���Ϊ����̬
            {
                cout<<i-strlen(pattern[tmp->patterNo])+1<<'\t'<<tmp->patterNo<<'\t'<<pattern[tmp->patterNo]<<endl;
            }
            i++;
        }
        else
        {
            if(tmp==root)
                i++;
            else
            {
                tmp=tmp->fail;
                if(tmp->patterTag==1)    //���Ϊ����̬
                    cout<<i-strlen(pattern[tmp->patterNo])+1<<'\t'<<tmp->patterNo<<'\t'<<pattern[tmp->patterNo]<<endl;
            }
        }
    }
    while(tmp!=root)
    {
        tmp=tmp->fail;
        if(tmp->patterTag==1)
            cout<<i-strlen(pattern[tmp->patterNo])+1<<'\t'<<tmp->patterNo<<'\t'<<pattern[tmp->patterNo]<<endl;
    }
    return 0;
}

/**
�ͷ��ڴ棬DFS
*/
int destory(Tree tree)
{
    if(tree==NULL)
        return 0;
    queue<Tree> myqueue;
    TreeNode *tmp=NULL;

    myqueue.push(tree);
    tree=NULL;
    while(!myqueue.empty())
    {
        tmp=myqueue.front();
        myqueue.pop();

        for (int i = 0; i < 26; i++)
        {
            if(tmp->next[i]!=NULL)
                myqueue.push(tmp->next[i]);
        }
        free(tmp);
    }
    return 0;
}

int main()
{
    char a[]="sdmfhsgnshejfgnihaofhsrnihao";
    Tree root=buildingTree();   ///����Trie��
    buildingFailPath(root); ///���ʧ��ת��
    cout<<"��ƥ���ַ�����"<<a<<endl;
    cout<<"ģʽ"<<pattern[0]<<" "<<pattern[1]<<" "<<pattern[2]<<" "<<pattern[3]<<" "<<endl<<endl;
    cout<<"ƥ�������£�"<<endl<<"λ��\t"<<"���\t"<<"ģʽ"<<endl;
    searchAC(root,a,strlen(a)); ///����
    destory(root);  ///�ͷŶ�̬�����ڴ�
    return 0;
}
