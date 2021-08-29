#include<iostream>
#include<bits/std c++.h>
using namespace std;

int time = 0;
vector<int> arr[2001];
int vis[2001];
int intime[2001];
int outtime[2001];
void dfs(int v){
	intime[v] = time++;
	vis[v] = 1;
	for(int i = 0;i<arr[v].size();i++){
		if(vis[arr[v][i]]==0)
			dfs(arr[v][i]);
	}
	outtime[v] = time++;
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
	
}
