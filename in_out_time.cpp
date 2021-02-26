#include <bits/stdc++.h>

using namespace std ;

const int N=1e5;
vector<int> g[N];
bool vis[N]={0};
int dis[N]={0};
int parent[N]={0};
int timer=1;
int in[N];
int out[N];


void dfs(int a){
      
    vis[a]=1;
    in[a]= timer++;
    for(auto var : g[a])
    {
        if (!vis[var])
        {
            dfs(var);
        }
        
    }
    out[a]=timer++;



}

int main() {

    int n,m;

    cout<<"enter the value of n: ";
    cin>>n;
    cout<<"enter the value of m: ";
    cin>>m;
    for (int i = 1; i <=m; i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    } 
    dfs(1);
    cout<<"in time"<<" ";
    for (int i = 1; i <=n; i++)
    {
       
        cout<<in[i]<<" ";
    }
    cout<<"\n";
    cout<<"out time"<<" ";
    for (int i = 1; i <=n; i++)
    {
        
        cout<<out[i]<<" ";
    }
    return 0;

}