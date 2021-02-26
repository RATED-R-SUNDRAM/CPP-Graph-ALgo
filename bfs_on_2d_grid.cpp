#include <bits/stdc++.h>
using namespace std ;

int N,M;
int vis[1000][1000]={0};
int dis[1000][1000]={0};

bool isvalid(int a ,int b){

    if (a<1 || b<1 || a>N || b>M)
    {
        return false;
    }
    else if (vis[a][b]==1)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int x_increment[4]={-1,0,1,0};
// up, right , down , left

int y_increment[4]={0,1,0,-1};



int main()
{
    cout<<"enter N: " ;
    cin>>N;
    cout<<"enter M: " ;
    cin>>M;
    
    queue<pair<int,int>> q;
    q.push({1,1});
    dis[1][1]=0;
    while (!q.empty())
    {
        pair<int,int> node = q.front();
        int x=  node.first;
        int y = node.second;
        vis[x][y]=1;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            if (isvalid(x+x_increment[i],y+y_increment[i]))
            {
                
                dis[x+x_increment[i]][y+y_increment[i]]=dis[x][y]+1;
                
                q.push({x+x_increment[i],y+y_increment[i]});
            }
        }
    }
    
    for (int i = 1; i <=N; i++)
    {
        for (int j = 1; j <=M; j++)
        {
            cout<<i<<" , "<<j<<"-->"<<dis[i][j]<<"\n";
        }
    }


    
    return 0;
}


