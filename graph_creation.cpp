#include <bits/stdc++.h> 
using namespace std; 

const int N=1e5;
vector<int> g[N];
bool vis[N]={0};



void dfs(int a){
    for (auto elm : g[a])
    {
        if(vis[elm]==0){
            vis[elm]=1;
            dfs(elm);
        }
    }
}
int main() {
    int n,m;
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
    for (int i = 1; i <=n; i++)
    {
        

        cout<<i<<"-->";
        for(auto var :g[i])
        {
            cout<<var<<",";
            
        }
        cout<<"\n";
    }
    for (int i = 1; i <=n; i++)
    {
        if(!vis[i]){
            dfs(i);
        }
    }
    for (int i = 1; i <=10; i++)
    {
        cout<<vis[i]<<" ";
    }
    
    
    
    


    return 0;
}