#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> arr[10001];
set<int> articulation_points;  // set where we will store all articulation points
int timer;
int in[10001],low[10001],vis[10001];
void dfs(int v, int p){
	in[v] = low[v] = timer++;
	vis[v] = 1;
	int children = 0;
	for(int i = 0;i<arr[v].size();i++){
		int child = arr[v][i];
		if(child==p)continue;
		if(vis[child]){
			low[v] = min(low[v],in[child]);
		}else{
			dfs(child,v);
			low[v] = min(low[v],low[child]);
			if(low[child]>=in[v] && p!=-1){
				articulation_points.insert(v);
			}
			++children;
		}
	}
	if(p==-1 && children>1){
		articulation_points.insert(v);
	}
}
int main(){
	
}
