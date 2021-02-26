#include <bits/stdc++.h>

using namespace std;

const int N=1e5+5;
bool vis[N]={0};
vector<int> g[N];
int dis[N]={0};

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
    
    for (int i = 1; i <=n; i++)
    {
        cout<<i<<"--->"<<dis[i]<<"\n";
    }
    return 0;
}