#include<bits/stdc++.h>
using namespace std;

#define inf   1e9
const int N = 100001;
vector<pair<int,int> > ar[N];
int vis[N];
int dist[N];

int main(){
	
	int n,m;
	cin>>n>>m;
	
	for(int i = 0;i<m;i++){
		int a,b,w;
		cin>>a>>b>>w;
		ar[a].push_back({b,w});
		ar[b].push_back({a,w});
		
		dist[i] = inf;
	}
	
	priority_queue<pair<int,int>, vector<pair<int,int> > , greater<pair<int,int> > > p;
	
	/* 
	In this priority queue we are keep pairs in which first represent distance of node from source node
	and second of pair represent value of the node.
	*/
	
	
	p.push({0,1});  // source vertex ( from where we are measuring distance)
	dist[1] = 0;
	
	// this is very similar to BFS ... 
	while(!p.empty()){
		pair<int,int> curr = p.top();
		p.pop();
		
		if(dist[curr.second]<curr.first)continue;
		
		for(int i = 0;i<ar[curr.second].size();i++){
			
			int child = ar[curr.second][i].first;
			
			if(dist[child] > dist[curr.second] + ar[curr.second][i].second){
				dist[child] = dist[curr.second] + ar[curr.second][i].second;
				p.push({dist[child],child});
			}
		}
	}
	
	for(int i = 1;i<=n;i++){
		cout<<dist[i]<<" ";
	}
	cout<<endl;
	
}
