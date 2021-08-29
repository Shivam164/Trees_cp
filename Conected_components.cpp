#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// this code is to check number of connected components 
void dfs(int v,int vis[],vector<int> arr[]){
	vis[v] = 1;
	cout<<v<<" ";
	for(int i = 0;i<arr[v].size();i++){
		if(vis[arr[v][i]]==0)
			dfs(arr[v][i],vis,arr);
	}
}
int main(){
	int n;
	cin>>n;
	vector<int> arr[n+1];
	int vis[n+1] = {0};
	
	
	for(int i = 0;i<n;i++){
		int a,b;
		cin>>a>>b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	int count = 0;
	for(int i = 1;i<=n;i++){
		if(!vis[i]){
			count++;
			dfs(1,vis,arr);
		}
	}
	cout<<count<<endl;
}
