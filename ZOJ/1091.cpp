#include <iostream>  
#include <cstdio>  
#include <cstring>  
using namespace std;  
int temp[20][20];  
int xx[]={2,1,-1,-2,-2,-1,1,2};             //方向坐标，马能8个方向  
int yy[]={-1,-2,-2,-1,1,2,2,1};  
int endx,endy,stx,sty;  
void dfs(int x,int y,int move){  
    int tempx,tempy,i,j;  
    if(x<1||x>8||y<1||y>8||temp[x][y]<=move)//判断不搜索的情况  
    return ;  
    temp[x][y]=move;                        //用一个数组记录每一位置走的最少步数  
    for(i=0;i<8;i++){  
        tempx=x+xx[i];  
        tempy=y+yy[i];  
        dfs(tempx,tempy,move+1);            //dfs每一个可走的点  
    }  
}  
int main(){  
    char c1,c2;  
    int a,b,i,j;  
    while(scanf(" %c%d %c%d",&c1,&a,&c2,&b)!=EOF){  
        sty=c1-'a'+1;  
        stx=a;  
        endy=c2-'a'+1;  
        endx=b;  
        for(i=0;i<20;i++)  
        for(j=0;j<20;j++)  
        temp[i][j]=99999999;  
        dfs(stx,sty,0);  
        printf("To get from %c%d to %c%d takes %d knight moves.\n",c1,a,c2,b,temp[endx][endy]);  
    }  
    return 0;  
}  
