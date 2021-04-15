#include <bits/stdc++.h>

using namespace std;

const int N=3;
bool vis[3][3];
// up , right , down , left 

int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

bool valid(int a,int b){
	if (a<0 || a>=N || b<0 || b>=N){
		return false;
	}
	else if(vis[a][b]){

	    return false;
	}

	else
	{
		
		return true;
    }
	
}

void dfs(int a,int b){
	
	vis[a][b]=1;
    cout<<a+1<<" "<<b+1<<"\n";

	for (int i = 0; i <4; i++)
	{
	    if (valid(a+dx[i],b+dy[i]))
		{
			
			dfs(a+dx[i],b+dy[i]);

		}
		
	}

}

int main(int argc, char const *argv[])
{
	dfs(0,0);
	
    return 0;
}	