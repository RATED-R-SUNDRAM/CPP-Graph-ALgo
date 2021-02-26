#include <bits/stdc++.h>

using namespace std;

const int N=1e5+5;


int main() {
    int t;
    cin>>t;
    for (int i = 1; i <=t; i++)
    {
        
    bool vis[N]={0};
    vector<int> g[N];
    int dis[N]={0};
    int n,m;
  
    cin>>n;
 
    cin>>m;
    for (int i = 1; i <=m; i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    
    queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        int node = q.front();
        vis[node]=1;
        q.pop();
        for(auto var :g[node])
        {
            
            if(!vis[var]){
                dis[var]=dis[node]+1; 
                vis[var]=1;
                q.push(var);
            }
            
            
        }
    

    }
    
    cout<<dis[n]<<"\n";
    

    
    }
    return 0;
}