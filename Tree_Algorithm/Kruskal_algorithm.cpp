#include<bits/stdc++.h>
using namespace std;
int parent[1001];

int find(int a){ 
	if(parent[a]<0)return a;
	int k = find(parent[a]);
	parent[a] = k;
	return k;
}

void merge(int a,int b){ 
	a = find(a);
	b = find(b);
	
	if(a==b)return ;
	if(parent[a]>parent[b]){ 
		parent[a]+=parent[b];
		parent[b] = a;
	}else{
		parent[b]+=parent[a];
		parent[a] = b;	
	}
}

struct edge{
	int a,b,w;
};

vector<edge> v;

bool comp(edge e1,edge e2){
	return e1.w<e2.w;
}
vector<int> ar[100001];
int main(){
	
	int n,m;
	cin>>n>>m;
	
	for(int i = 1;i<=n;i++){
		parent[i] = -1;
		
	}
	
	for(int i = 0;i<m;i++){
		edge e;
		cin>>e.a>>e.b>>e.w;
		v.push_back(e);
	}
	
	sort(v.begin(),v.end(),comp);
	
	
	int ans = 0;
	for(int i = 0;i<v.size();i++){
		if(find(v[i].a)==find(v[i].b))continue;
		ans+=(v[i].w);
		merge(v[i].a,v[i].b);
		ar[v[i].a].push_back(v[i].b);
		ar[v[i].b].push_back(v[i].a);
	}
	
	cout<<ans<<endl;
	
}
