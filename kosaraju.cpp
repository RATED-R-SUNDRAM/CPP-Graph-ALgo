#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
bool vis[N] = {0};
bool dis[N] = {0};
vector<int> g[N];
vector<int> t[N];
vector<int> vi;
stack<int> s;
int scc = 1;

void dfs(int a)
{
    vis[a] = 1;
    for (auto var : g[a])
    {
        if (!vis[var])
        {
            dfs(var);
        }
    }
    vi.push_back(a);
    s.push(a);
}
void df(int a)
{
    dis[a] = 1;
    cout<<a<<" ";
    for (auto var : t[a])
    {
        if (!dis[var])
        {

            df(var);
        }
    }
}

int main()
{
    int n, m;
    cout << "Enter N :";
    cin >> n;
    cout << "Enter M :";
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        t[b].push_back(a);
    };
    for (int i = 1; i <=n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
        
        
    }
    
    cout << "elm in stack are :"
         << "\n";
   
    for(auto var : vi)
    {
        cout<<var<<" ";
    }
    cout<<"\n";
    
    while (!s.empty())
    {
        int node = s.top();
        s.pop();
        if (!dis[node])
        {
            cout<<"SCC NO#"<<scc++<<" : ";
            
            df(node);
            cout<<"\n";
           
        }
        
    
        
    }

    cout<<"\n"<<"no. of scc"<<scc-1;

    return 0;
}