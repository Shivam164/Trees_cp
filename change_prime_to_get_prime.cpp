#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> arr[100001];
int vis[100001];
int dis[100001];
vector<int> prime;
bool isPrime(int n){
	for(int i = 2;i*i<=n;i++){
		if(n%i==0){
			return false;
		}
	}
	return true;
}
bool valid(int a,int b){
	int count = 0;
	while(a!=0){
		if(a%10!=b%10){
			count++;
		}
		a/=10;
		b/=10;
	}
	if(count==1)
		return true;
	else
		return false;
}
void build_graph(){
	for(int i = 1000;i<=9999;i++){
		if(isPrime(i)){
			prime.push_back(i);
		}
	}
	for(int i = 0;i<prime.size();i++){
		for(int j = i+1;j<prime.size();j++){
			bool check = valid(prime[i],prime[j]);
			if(check){
				arr[prime[i]].push_back(prime[j]);
				arr[prime[j]].push_back(prime[i]);
			}
		}
	}
}
void bfs(int v){
	vis[v] = 1;
	queue<int> q;
	q.push(v);
	dis[v] = 0;
	while(!q.empty()){
		int p = q.front();
		q.pop();
		for(int i = 0;i<arr[p].size();i++){
			if(vis[arr[p][i]]==0){
				dis[arr[p][i]] = dis[p]+1;
				q.push(arr[p][i]);
				vis[arr[p][i]] = 1;
			}
		}
	}
}
int main(){
	int n,m,k,g;
	cin>>n>>m>>k>>g;
	for(int i = 1;i<=n;i++){
		arr[i].clear();
		vis[i] = 0;
		dis[i] = -1;
	}
	build_graph();
	bfs(k);
	cout<<dis[g]<<endl;
}
