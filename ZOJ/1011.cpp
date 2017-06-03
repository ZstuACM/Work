#include<iostream>
#include<set>
using namespace std;
int main()
{
	int gamblers;
	while(cin>>gamblers && gamblers)
	{
		if(gamblers < 4)
		{
			cout<<"no solution"<<endl;
			continue;
		}
		int *wagers = new int[gamblers];
		set<int> se;
		int wager;
		while(gamblers-- && cin>>wager)
		{
			se.insert(wager);
		}
		int arrIndex = 0;
		for(set<int>::reverse_iterator it = se.rbegin(); it != se.rend(); it++)
		{
			*(wagers + arrIndex) = *it;
			arrIndex++;
		}
		int winWager;
		for(int winner = 0; winner < arrIndex; winner++)
		{
			winWager = *(wagers + winner);
			for(int i = 0; i < arrIndex; i++)
			{
				for(int j = 0;j < arrIndex; j++)
				{
		  			if( winner != i && winner != j && i != j)
		  			{
		    			int last = winWager - (*(wagers + i) + *(wagers + j));
		    			if(last != winWager 
		      					&& last != *(wagers+i) 
		      					&& last != *(wagers+j) 
		      					&& se.find(last) != se.end())
		    			{
		      				cout<<winWager<<endl;
		      				goto breakAll;
		    			}
		  			}
				}	
			}
		}
	delete []wagers;
	cout<<"no solution"<<endl;
	breakAll:;
	}
	return 0;
}
