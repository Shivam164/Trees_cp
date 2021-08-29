#include<bits/stdc++.h>
using namespace std;
const int N = 1000001;
int vis[N];
int low[N],in[N];
bool onStack[N];
stack<int> st;
vector<int> ar[N];
int timer,scc;
void dfs(int v){
	vis[v] = 1;
	in[v] = low[v] = timer++;
	onStack[v] = 1;
	st.push(v);
	for(int i = 0;i<ar[v].size();i++){
		int child = ar[v][i];
		if(vis[child]==1 && onStack[child]){
			low[v] = min(low[v],in[child]);
		}else if(vis[child]==0){
			dfs(child);
			if(onStack[child]){
				low[v] = min(low[v],low[child]);
			}
		}
	}
	
	if(in[v]==low[v]){
		scc++;
		cout<<"SCC #"<<scc<<endl;
		int u;
		while(1)
		{
			u = st.top();
			st.pop() , onStack[u] = false;
			cout<<u<<" ";
 
			if(u == v) break;
		}
		cout<<endl;
	}
}
int main(){
		
	int n,m;
	cin>>n>>m;
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		ar[a].push_back(b);
	}
	for(int i = 0;i<=n;i++)vis[i] = 0;
	
	for(int i = 1;i<=n;i++){
		if(vis[i]==0){
			dfs(i);
		}
	}
}
