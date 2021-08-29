#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n,m;
int arr[101][101];
int vis[101][101];
int move[101][101];
int dx[8] = {2,2,-2,-2,1,1,-1,-1};
int dy[8] = {1,-1,1,-1,2,-2,2,-2};
bool isValid(int x,int y){
	if(x<0 || x>=m || y<0 || y>=n)return false;
	if(vis[x][y]==1)return false;
	return true;
}
void bfs(int x,int y){
	vis[x][y] = 1;
	move[x][y] = 0;
	queue<pair<int,int> > q;
	q.push({x,y});
	while(!q.empty()){
		int currx = q.front().first;
		int curry = q.front().second;
		q.pop();
		int m = move[currx][curry];
		for(int i = 0;i<8;i++){
			if(isValid(currx + dx[i],curry + dy[i])){
				vis[currx + dx[i]][curry + dy[i]] = 1;
				move[currx + dx[i]][curry + dy[i]] = m + 1;
				q.push({currx + dx[i],curry + dy[i]});
			}
		}
	}
}
int main(){
	cout<<"enter number of rows and column : ";
	cin>>n>>m;
	cout<<"\n enter initial position of knight";
	int a,b;
	cin>>a>>b;
	bfs(a,b);
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			cout<<move[i][j]<<" ";
		}
		cout<<endl;
	}
}
