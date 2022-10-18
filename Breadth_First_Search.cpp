#include<iostream>
#include<bits/stdc++.h>
// breadth first search ... here code is used to calculate distance of nodes wrt some other particular node
using namespace std;
vector<int> arr[10001];


int vis[10001],dis[10001];
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
			}
		}
	}
}	
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		for(int i = 1;i<=n;i++){
			arr[i].clear();
			vis[i] = 0;
		}
			
		for(int i = 0;i<m;i++){
			int a,b;
			cin>>a>>b;
			arr[a].push_back(b);
			arr[b].push_back(a);
		}
		
		bfs(1);
		cout<<dis[n]<<endl;
	}
}

