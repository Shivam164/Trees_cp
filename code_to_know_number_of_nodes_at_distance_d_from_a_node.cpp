#include<iostream>
#include<bits/stdc++.h>
// code to know number of at distance d from a node
using namespace std;
vector<int> arr[10001];
int vis[10001];
int lvl[10001];
int dis[10001];
void bfs(int v){
	queue<int> q;
	q.push(v);
	vis[v] = 1;
	dis[v] = 0;
	while(!q.empty()){
		int curr = q.front();
		q.pop();
		for(int i = 0;i<arr[curr].size();i++){
			int value = arr[curr][i];
			if(vis[value]==0){
				vis[value] = 1;
				q.push(value);
				dis[value] = dis[curr] + 1;
				lvl[dis[value]]++;
			}
		}
	}
}	
int main(){
	
	int n,m;
	cin>>n>>m;
	for(int i = 0;i<n;i++){
		int a,b;
		cin>>a>>b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	int root,dis;
	cin>>root>>dis;
	bfs(root);
	
	
}
