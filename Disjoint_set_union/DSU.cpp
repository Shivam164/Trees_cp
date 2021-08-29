#include<bits/std/c++.h>
using namespace std;
int parent[1001];
int find(int a){ // iterative way to find parent
	while(parent[a]>0)
		a = parent[a];
	return a;
}


int find_recursive(int a){ // recursive way to find parent 
	if(parent[a]<0)return a;
	return find_recursive(parent[a]);
}

// For using path compression technique we uses an array that will keep a parent
// of the set and in parent, we will keep a negative number that will tell the size of the set

int find_with_pathCompression(int a){ // returning parent with compression of path 
	vector<int> v;
	while(parent[a]>0){
		v.push_back(a);
		a = parent[a];
	}
	for(int i = 0;i<v.size();i++){
		parent[v[i]] = a;
	}
	return a;
}


int find_recursion(int a){ // find parent using recursion
	if(parent[a]<0)return a;
	int k = find_recursion(parent[a]);
	parent[a] = k;
	return k;
}


void union(int a,int b){ // to get the union of two different sets
	int a = find(a);
	int b = find(b);
	
	if(a==b)return ;
	if(parent[a]>parent[b]){ // this if condition is to merge set with smaller size into set with larger size
		parent[a]+=parent[b];
		parent[b] = a;
	}else{
		parent[b]+=parent[a];
		parent[a] = b;	
	}

}
int main(){
	fill(parent,parent+1001,-1);
}
