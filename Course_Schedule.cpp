#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define V vector
int n,m;
V<V<ll>>courses;
queue<ll>q;
V<ll>vis,ans;
int cycle=0;
void dfs(ll i){
	vis[i]=-1;
	for(auto it:courses[i]){
		if(!vis[it]){
			dfs(it);
			if(cycle)return ;
		}
		else if(vis[it]==-1){
			cycle=1;
			return ;
		}
	}
	if(cycle)return ;
	vis[i]=1;
	ans.push_back(i);
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	cin>>n>>m;
	courses.resize(n+1);
	for(int i=0;i<m;i++){
		ll x,y;
		cin>>x>>y;
		courses[y].push_back(x);
	}
	vis.resize(n+1,0);
	for(int i=1;i<=n;i++){
		if(courses[i].size()==0){
			vis[i]=1;
			ans.push_back(i);
		}
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			dfs(i);
			if(cycle){
				cout<<"IMPOSSIBLE\n";
				return 0;
			}
		}
	}
	for(auto it:ans)cout<<it<<" ";

	
}