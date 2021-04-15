#include <bits/stdc++.h>
using namespace std ;

const int N=1e5;
vector<int> g[N];
bool vis[N]={0};
int in[N]={0};
vector<int> vec;


int main(int argc, char const *argv[])
{
    int n,m;
    cin>>n>>m;
    for (int i =1; i<=m; i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        in[b]++;

    }
    queue<int> q;
    for (int i =1; i <=n; i++)
    {
        if (in[i]==0)
        {
            q.push(i);
        }
        
    }
    while (!q.empty())
    {
        int node = q.front();
        vec.push_back(node);
        vis[node]=1;
        q.pop();
        for(auto var : g[node])
        {
            in[var]--;
            if (in[var]==0)
            {
                q.push(var);
            }
            
        }
    }
    for (auto i = vec.begin(); i != vec.end(); ++i) 
        cout << *i << " ";
    

    return 0;
}
