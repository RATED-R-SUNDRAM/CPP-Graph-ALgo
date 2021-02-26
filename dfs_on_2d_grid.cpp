#include <bits/stdc++.h>
using namespace std ;

int N,M;
int vis[1000][1000];

bool isvalid(int a,int b){
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
void dfs(int x,int y){
    cout<<x<<" , "<<y<<"\n";
    vis[x][y]=1;
    for (int i = 0; i <=4; i++)
    {
        if (isvalid(x+x_increment[i],y+y_increment[i]))
        {
            dfs(x+x_increment[i],y+y_increment[i]);
        }
        
    }

}

int main()
{
    cout<<"enter N: " ;
    cin>>N;
    cout<<"enter M: " ;
    cin>>M;
    
    dfs(1,1);
    return 0;
}
