#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int in[100];
vector<int> arr[100];
vector<int> res;
void kahn(int n){
	queue<int> q;
	for(int i = 1;i<=n;i++){
		if(in[i]==0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int curr = q.front();
		res.push_back(curr);
		q.pop();
		for(int i = 0;i<arr[curr].size();i++){
			int child = arr[curr][i];
			in[child]--;
			if(in[child]==0){
				q.push(child);
			}
		}
	}
	for(int i = 0;i<res.size();i++){
		cout<<res[i]<<" ";
	}
	cout<<endl;
}
int main(){
	
	int n,m;
	cin>>n>>m;
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		arr[a].push_back(b);
		in[b]++;
	} 
	
	kahn(n);
	
}
