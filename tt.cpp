#include <bits/stdc++.h>
using namespace std ;

const int N=1e7;
bool vis[N]={0};
vector<vector<int>> g ;

int dfs(int a){
    vis[a]=1;
    int ans=1;
    for (auto elm : g[a]){
        if(!vis[elm]){
            vis[elm]=1;
            ans+=dfs(elm);
        }
    }
    return ans;
}

int main() {

    int t;
    cin>>t;
    for (int i = 1; i <=t; i++){
        
        int n,m;
        
        cin>>n>>m;
        for (int i = 1; i <=m; i++){
            int a,b;
            cin>>a>>b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        
        int conn_comp=0;
        int no_ways=1;

        for (int i = 1; i <=n; i++){
            if (!vis[i]){
               conn_comp++;
               no_ways=no_ways*dfs(i);
            }
        }
        cout<<conn_comp<<" "<<no_ways<<"\n";
        g.clear();
        fill(begin(vis),end(vis), false );
    }
    
    

    return 0;
}