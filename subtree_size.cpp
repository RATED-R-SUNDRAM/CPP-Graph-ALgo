#include <bits/stdc++.h>

using namespace std ;

const int N = 1e5;
vector<int> g[N];

bool vis[N]={0};
int subtree[N]={0};

int dfs(int a){
   vis[a]=1;
   int cur_size=1;
   for(auto var : g[a])
   {
       if (!vis[var])
       {   
           cur_size+= dfs(var);
       }
   }
   subtree[a]=cur_size;
   return cur_size;
       

       
   
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

    for (int i = 1; i <=n; i++)
    {
       cout<<i<<"--->"<<subtree[i]<<"\n";        
    }

    return 0;
}