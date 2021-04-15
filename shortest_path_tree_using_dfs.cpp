#include <bits/stdc++.h>

using namespace std ;

const int N=1e5;
vector<int> g[N];
bool vis[N]={0};
int dis[N]={0};
int parent[N]={0};

void dfs(int a,int b){
    vis[a]=1;
    for(auto var : g[a])
    {
        
        parent[var]=a;
        if (!vis[var])
        {
            dis[var]=b+1;
            vis[var]=1;
            dfs(var,b+1);
        }
        
    }
}

int main() {
    int n,s;
    cout<<"Enter N: ";
    cin>>n;
    cout<<"Enter the source node: ";
    cin>>s;
    for (int i = 1; i <n; i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(s,0);
  
    for (int i = 1; i <=n; i++)
    {
        cout<<dis[i]<<"  ";
    }
    

    return 0;
}