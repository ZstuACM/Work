/*
	Name: 任务3 找出现次数最多的单词
	Copyright: 
	Author: lizhimin 
	Date: 24/05/17 20:25
	Description: String Hash
*/

#include <iostream>  
#include <cstdio>
#include <cstring>  
#include <vector> 
#include <cstdlib>
#define Debug_Switch 0
using namespace std;
int maxnum=0;
char str2low(char ch)
{
	if ('A'<=ch && ch<='Z') return (ch+32);
	if ('a'<=ch && ch<='z') return ch;
	return (' ');
} 
int getPrimeNumber(int num)  
{  
    if(num <= 0)  
    {  
        return -1;  
    }  
    int* primeArr = new int[num + 1]; 
    int* visitArr = new int[num + 1];
    memset(primeArr , 0 , sizeof(primeArr) * (num + 1));  
    memset(visitArr , 0 , sizeof(visitArr) * (num + 1));  
    int k;  
    for(int i = 2 ; i <= num ; i++ )  
    {
       k = i; 
       while(k * i <= num)  
       {
            if(0 == visitArr[i])  
            {  
                visitArr[k * i] = 1;
                primeArr[k * i] = 1;
            }
            k++;  
        }  
    }  
    int i;  
    for(i = num - 1; i >= 2 ; i--)  
    {  
        if(0 == primeArr[i])  
        {  
            break;  
        }  
    }  
    delete[] primeArr;  
    delete[] visitArr;  
    return i;  
	}  
	  
const int MULT = 31;  
typedef struct Node  
{  
	Node():_next(NULL),_word(""),_count(0),_isNULL(true){}  
	void setNULL(bool flag)  
	{  
		_isNULL = flag;  
	}  
	Node* _next;
	string _word;  
	int _count;
	bool _isNULL; 
	}Node;
	int getHash(char* str , int primeNum)  
	{  
		unsigned int hashValue = 0;  
		if(NULL == str || primeNum < 2)  
		{  
			return hashValue;  
	    }  
	    for( ; *str ; str++)  
	    {  
	        char ch = *str;  
	        hashValue = MULT * hashValue + ch;  
	    }  
	    return (hashValue % primeNum);  
	}  
	  
void countWords(Node* hashTable, int primeNum , vector<string> words)  
{  
    if(NULL == hashTable || primeNum < 2 || words.empty())  
    {  
        return;  
    }  
    //对每个单词生成链表  
    int size = words.size();  
    string sWord;  
    char* word;  
    int hashIndex;  
    Node* node;  
    for(int i = 0 ; i < size ; i++)  
    {  
		sWord = words.at(i);  
		word = (char*)sWord.c_str();  
        hashIndex = getHash(word , primeNum);
        if(hashTable[hashIndex]._isNULL)  
        {  
            Node* newNode = new Node();  
            newNode->_word = sWord;  
            newNode->_isNULL = false;  
            newNode->_count = 1;
            hashTable[hashIndex] = *newNode;  
        }  
		else  
        {
            bool isFind = false;  
            Node* previouNode = NULL;  
            for(node = &hashTable[hashIndex] ; node != NULL ; )  
            {  
                //如果找到该单词  
                if( node->_word == sWord)  
                {  
                    node->_count++;  
                    isFind = true;  
                    break;  
                }  
                previouNode = node;  
                node = node->_next;  
            }  
            if(!isFind)  
            {  
                Node* newNode = new Node();  
                newNode->_word = sWord;  
                newNode->_isNULL = false;  
                newNode->_count = 1;
                previouNode->_next = newNode;  
            }  
        }  
    }  
}

void releaseHashTable(Node* hashTable , int size)  
{  
	if(NULL == hashTable || size <= 0)  
    {  
		return;  
	}  
	for(int i = 0 ; i < size ; i++)  
	{  
	    Node* node = &hashTable[i];  
	    while(node)  
	    {  
	        Node* nextNode = node->_next;  
	        delete node;  
	        node = nextNode;  
	    }  
	}  
	delete[] hashTable;       
}  
	  
void print(Node* hashTable , int size) 
{
    for(int i = 0 ; i < size ; i++)  
    {  
        Node* node = &hashTable[i];  
        if(NULL == node || node->_isNULL )  
        {  
            continue;  
        } 
        while(node)  
        {
        	if (maxnum< node->_count)
        		maxnum=node->_count;
			if (Debug_Switch)
				cout << node->_word << ":" << node->_count <<endl;  
            node = node->_next;  
        }  
    }
    return;
}

void travel(Node* hashTable , int size) 
{
	/*
    if(NULL == hashTable || size <= 0)  
    {  
        cout << "NO result" << endl;  
        return;  
    }
	*/ 
    for(int i = 0 ; i < size ; i++)  
    {  
        Node* node = &hashTable[i];  
        if(NULL == node || node->_isNULL )  
        {  
            continue;  
        } 
        while(node)  
        {  
            if (maxnum== node->_count)
            	cout << node->_word << ":" << node->_count <<endl; 
            node = node->_next;  
        }
    }
    cout << endl;  
}
void process()  
{  
    int wordNum;
    int max=0;
    vector<string> words;  
    string word;  
    while(cin >> wordNum)  
    {  
        for(int i = 0 ; i < wordNum ; i++)  
        {
            cin >> word;
            for (int j=0;j<word.size();j++)
            	if (str2low(word[j])==' ')
            		word[j]='\0';
            if (word[0]!='\0')
            {
            	if (Debug_Switch)
					cout<<word<<endl;
            	words.push_back(word);
            }
        }  
        int primeNum = getPrimeNumber(wordNum);
          
        Node* hashTable = new Node[primeNum];  
        countWords(hashTable , primeNum , words);  
        print(hashTable , primeNum);
        travel(hashTable , primeNum);
        releaseHashTable(hashTable , primeNum);  
    }  
}  

int main(int argc , char* argv[])  
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w+",stdout); 
	process();  
    fclose(stdin); fclose(stdout);  
    return 0;  
}  

