#include <bits/stdc++.h>

using namespace std ;

const int N=1e5;
vector<int> g[N];
bool vis[N]={0};
bool color[N]={0};

bool dfs(int a,int b){
    vis[a]=1;
    color[a]=b;

    for(auto var : g[a])
    {
        if(!vis[var]){
            if(dfs(var,b^1)==false){
                return false;
            }
        }
        else
        {
            if(color[a]==color[var]){
                return false;
            }
        }

    
        
    }
    return true;
}

int main() {

    int n,m;
    cout<<"Enter the value of n: ";
    cin>>n;
    cout<<"Enter the value of m: ";
    cin>>m;
    for (int i = 1; i <=m; i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    bool ans=dfs(1,0);
    cout<<ans;
    return 0;
}
