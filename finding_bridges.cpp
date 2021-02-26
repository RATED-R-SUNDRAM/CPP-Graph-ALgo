#include <bits/stdc++.h>
using namespace std ;

const int N=1e5;
vector<int> g[N];
bool vis[N]={0};
int in[N]={0};
int low[N]={0};
int timer =0;
pair<int,int>p;

void dfs(int node,int par){
    vis[node]=1;
    in[node]=low[node]=++timer;
    for (auto elm: g[node])
    {
        // if parent do nothing
        if (elm==par)
        {
            continue;
        }
        
        // check for back edges
        if (vis[elm]==1 and elm!=par)
        {
            low[node]= min(in[elm],low[node]);
        }
        
        else
        {
            dfs(elm,node);
            low[node]=min(low[node],low[elm]);
            if (low[elm]>in[node])
            {
                
                cout<<node<<"--"<<elm<<" is a bridge"<<"\n";
            }
           
            
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
    
    dfs(3,-1);
    for (int i = 1; i <=7; i++)
    {
        cout<<"in["<<i<<"]"<<in[i]<<"\n";
    }
    for (int i = 1; i <=7; i++)
    {
        cout<<"low["<<i<<"]"<<low[i]<<"\n";
    }

    
    
    
    return 0;
}