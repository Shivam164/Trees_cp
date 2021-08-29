#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// this code is mainly for checking whether connected pairs are different or not
vector<int> arr[2001];
int vis[2001];
int col[2001];
bool dfs(int v,int color){	
	vis[v] = 1;
	col[v] = color;
	for(int i = 0;i<arr[v].size();i++){
		if(vis[arr[v][i]]==0){
			bool check = dfs(arr[v][i],color^1);
			if(!check){
				return false;
			}
		}else{
			if(col[arr[v][i]]==color)
				return false;
		}
	}
	return true;
}
int main(){
	int t;
	cin>>t;
	int g = t;
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
		bool right = true;
		for(int i = 1;i<=n;i++){
			if(vis[i]==0){
				bool see = dfs(i,1);
				if(!see){
					right = false;
					break;
				}
			}
		}
		cout<<"Scenario#"<<g-t<<" "<<endl;
		if(right){
			cout<<"No suspicious bugs found!\n";
		}else{
			cout<<"Suspicious bugs found!\n";
		}
	}
}
