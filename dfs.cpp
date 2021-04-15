#include <bits/stdc++.h>
using namespace std;

const int N=1e5+5;
vector<int> g[N];
bool vis[N];

void dfs(int a){
    for(auto elm : g[a])
    {
        if (!vis[elm])
        {
            vis[elm]=1;
            dfs(elm);
        }
        
    }
}

int main() {
    int n,m;
    cin>>n>>m;
    for (int i=0; i <n; i++)
    {
       int a,b;
       cin>>a>>b;
       g[a].push_back(b);
       g[b].push_back(a);        
    }

    for(int i=1;i<=5;i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
        
    }
    for (int i = 0; i < 6; i++)
    {
        cout<<vis[i]<<"\n";
    }

    return 0;
}
