#include <bits/stdc++.h>
using namespace std ;

const int N=1e5;
vector<int> g[N];
bool vis[N]={0};
int in[N]={0};
vector<int> vec;



int main()
{
    int n,m;
    cin>>n>>m;
    for (int i =1; i<=m; i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);

    }
    queue<int> q;
    for (int i = 1; i <=n; i++)
    {
        if (in[i]==0)
        {
            q.push(i);
        }
        
    }
    while (!q.empty())
    {
        int node=q.front();
        vec.push_back(node);
        q.pop();
        for(auto elm : g[node])
        {
            in[elm]--;
            if (in[elm]==0)
            {
                q.push(elm);
            }
            
        }
    }
    
    for (auto i = vec.begin(); i != vec.end(); ++i) 
        cout << *i << " ";
    



    return 0;
}
