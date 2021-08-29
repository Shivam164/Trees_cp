#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> arr[100];
int vis[101];
int timer;
int low[101],in[101];
void dfs(int node,int parent){
	vis[node] = 1;
	in[node] = timer;
	low[node] = timer;
	timer++;
	for(int i = 0;i<arr[node].size();i++){
		int child = arr[node][i];
		if(child==parent)continue; // continuing if a node is already traversed and is parent of node
		if(vis[child]==1){
			low[node] = min(low[node],in[child]); // taking minimum of low value of node and child if child is already visited
		}else{
			dfs(child,node);
			if(in[node]<low[child]){
				cout<<node<<" - "<<child<<" is a bridge \n";
			}
			low[node] = min(low[node],low[child]);
		}
	}
}
int main(){
	
	int n,m;
	cin>>n>>m;
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	dfs(1,-1);
}
