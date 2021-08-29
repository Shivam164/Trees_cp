#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/* In this algorithm what we basically do is that : 
  
  first we will make a dfs call to the graph with which we will store set of
  nodes in a order in which they would get called in recursion and after that we will
  call one more dfs in whcih we will be traversing on the transverse of the initial graph
  - > Starting by calling the last element from the stored vertices in the vector 
  that way we will be getting strongly connected components...

*/
vector<int> arr[10001];
vector<int> tran[10001];
int vis[10001];
vector<int> out;
vector<int> check;
void dfs(int v){
	vis[v] = 1;
	for(int i = 0;i<arr[v].size();i++){
		if(vis[arr[v][i]]==0){
			dfs(arr[v][i]);
		}
	}
	out.push_back(v);
}
void dfs2(int v){
	vis[v] = 1;
	for(int i = 0;i<tran[v].size();i++){
		if(vis[tran[v][i]]==0){
			dfs2(tran[v][i]);
		}
	}
	check.push_back(v);
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		arr[a].push_back(b);
		tran[b].push_back(a);
	}
	
	for(int i = 1;i<n;i++){
		if(vis[i]==0){
			dfs(i);
		}
	}
	
	for(int i = 0;i<=n;i++)vis[i] = 0;
	
	for(int i = out.size()-1;i>=0;i--){
		check.clear();
		if(vis[out[i]]==0){
			dfs2(out[i]);
		}
		for(int j = 0;j<check.size();j++){
			cout<<check[j]<<" ";
		}
		cout<<endl;
	}
	
	
}
