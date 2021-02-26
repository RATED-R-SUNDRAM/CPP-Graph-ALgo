#include <bits/stdc++.h>

using namespace std;

const int N =1e5+5;

vector<int> G[N];


int main(){
    
    int n,m;
    cin>>n>>m;
    
    for (int i = 0; i <m; i++)
    {
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    for (int i = 1; i <=n ; i++)
    {
        cout<<i<<"------->";
        for(auto elm : G[i])
        {
            cout<<elm<<",";
        }
        cout<<"\n";
    }

   
    return 0;
}