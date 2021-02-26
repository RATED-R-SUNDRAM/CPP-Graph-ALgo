#include <bits/stdc++.h>

using namespace std ;

const int N = 1e5;
vector<int> g[N];

bool vis[N]={0};

bool dfs(int a,int par){
    vis[a]=1;
    for(auto elm : g[a])
    {
        if (!vis[elm])
        {
           if(dfs(elm,a)==true)
           return true;
        }
        else
        {
            if(elm!=par)
            return true;
        }
        
    }
    return false;
    
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

    bool ans=dfs(1,0);
    cout<<"the ans is "<<ans;
    
    return 0;
}




