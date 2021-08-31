#include<bits/stdc++.h>
using namespace std;

int maxN = 10,n;
vector<int> ar[10001];
int LCA[10001][10001]; // here second dimension will be the log2 of number of nodes present in the tree...
int level[10001];

void dfs(int v,int p,int d){
	level[v] = d;
	LCA[v][0] = p;
	for(int i = 0;i<ar[v].size();i++){
		int child = ar[v][i];
		if(p!=child){
			dfs(child,v,d+1);
		}
	}
}

// here filling up the LCA 2D array ....
void init(){
	dfs(1,-1,0);
	for(int j = 1;j<maxN;j++){
		for(int i = 1;i<=n;i++){
			if(LCA[i][j-1]!=-1){
				int par = LCA[i][j-1];
				LCA[i][j] = LCA[par][j-1];
			}
		}
	}
}

int getlca(int a,int b){
	
	if(level[a]>level[b])swap(a,b);
	
	int d = level[b] - level[a];
	
	while(d>0){
		int i = log2(d);
		b = LCA[b][i];
		d -= (1<<i);
	}
	if(a==b)return a;
	
	for(int i = maxN;i>=0;i--){
		if(LCA[a][i]!=-1 && (LCA[a][i]!=LCA[b][i])){
			a = LCA[a][i];
			b = LCA[b][i];
		}
	}
	return LCA[a][0];
}
int main(){
	int a,b,q;
	cin>>n>>q;
	maxN = log2(n);
	
	for(int i = 1;i<n;i++){
		for(int j = 0;j<=maxN;j++){
			LCA[i][j] = -1;
		}
	}
	
	for(int i = 0;i<n-1;i++){
		int c,d;
		cin>>c>>d;
		ar[c].push_back(d);
		ar[d].push_back(c);
	}
	init();
	
	while(q--){
		cin>>a>>b;
		int ans = level[a] + level[b] - 2*level[getlca(a,b)];
		cout<<ans<<endl;
	}
}
