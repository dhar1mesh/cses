#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define V vector
#define mod 1000000007
#define map map<long long,long long>
int n,m;
V<V<int>>tree;
V<int>ans;
int cnt=0;
// ll dfs(int child ,int par){
// 	ll sum=0;
// 	cnt++;
// 	if(cnt>1000){
// 		cout<<"exit";
// 		exit(0);
// 	}
// 	for(int it: tree[child]){
// 		if(child!=par){
// 			dfs(it,child);
// 			sum+=(ans[it]+1);
// 		}
// 	}

// 	ans[child]=sum;
// }

void dfs(int s, int e) {
	ans[s] = 1;
	for (auto u : tree[s]) {
		if (u == e) continue;
		dfs(u, s);
		ans[s]+=ans[u];
	}
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	cin>>n;
	tree.resize(n+1);
	for(int i=2;i<=n;i++){
		int x;
		cin>>x;
		tree[x].push_back(i);
		tree[i].push_back(x);
	}
	ans.resize(n+1);
	dfs(1,0);
	// cout<<"s";
	for(int i=1;i<=n;i++)cout<<ans[i]-1<<" ";
	
}