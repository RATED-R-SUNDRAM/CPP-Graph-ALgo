#include <bits/stdc++.h>
using namespace std ;

const int N=1e5;
vector<int> g[N];
bool vis[N]={0};
int count_conn_comp=0;

void dfs(int a){
    for(auto var :g[a])
    {
        if(!vis[var]){
            vis[var]=1;
            dfs(var);
        }
    }
}

int main() {
    
    int m,n;
    cout<<"enter the value of n: ";
    cin>>n;
    cout<<"enter the value of m: ";
    cin>>m;

    for (int i = 0; i <m; i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i =1; i <=n; i++)
    {
        if(!vis[i]){
            count_conn_comp++;
            dfs(i);
        }
    }

    cout<<"count ofconnected_components = "<<count_conn_comp<<"\n";
    
    
    return 0;
}