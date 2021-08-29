#include<iostream>
#include<bits/stdc++.h>
// code to know the diameter of a tree by applying dfs 2 times
// in one dfs call we can make sure that we have found one of the end 
// point of the diameter of the tree
using namespace std;
int vis[2001] = {0};
vector<int> arr[2001];
int maxdis = 0;
int farnode = 0;
void dfs(int v,int dis){
	vis[v] = 1;
	if(dis>maxdis){
		maxdis = dis;
		farnode = v;
	}
	for(int i = 0;i<arr[v].size();i++){
		if(vis[arr[v][i]]==0){
			dfs(arr[v][i],dis+1);
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
	dfs(1,0);
	for(int i = 1;i<=n;i++)
		vis[i] = 0;
	
	maxdis = 0;
	cout<<farnode<<endl;
	dfs(farnode,0);
	cout<<maxdis<<endl;
	
}
