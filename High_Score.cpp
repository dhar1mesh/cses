#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define V vector
int n,m;
V<V<ll>>flights,g;
V<ll>vis,res1;
V<ll>ans,res;;
bool dfs(ll x){
	if(vis[x]==1)return 0;
	vis[x]=1;
	res1.push_back(x);
	for(auto it:g[x]){
		if(!vis[it])dfs(it);
	}
	return 0;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	cin>>n>>m;
	g.resize(n+2);
	for(int i=0;i<m;i++){
		ll x,y,z;
		cin>>x>>y>>z;
		g[y].push_back(x);
		flights.push_back({x,y,-z});
	}
	V<ll>ans(n+1,LLONG_MAX/2);
	ans[1]=0;
	V<ll>change;
	for(int i=1;i<n;i++){
		for(auto it:flights){
			ll a=it[0];
			ll b=it[1];
			ll c=it[2];
			ans[b]=min(ans[a]+c,ans[b]);
		}
	}
	res=ans;
	for(int i=1;i<n;i++){
		for(auto it:flights){
			ll a=it[0];
			ll b=it[1];
			ll c=it[2];
			ans[b]=min(ans[a]+c,ans[b]);

		}
	}
	
	for(int i=1;i<=n;i++){
		if(ans[i]!=res[i]){
			change.push_back(i);
			
		}
	}
	vis.resize(n+1,0);
	if(change.size()==0)cout<<-ans[n];
	else {
		dfs(n);
		cout<<"\n";
		for(auto it:res1){
			if(res[it]!=ans[it]){
				cout<<-1;
				// cout<<res[it]<<" "<<ans[it];
				return 0;
			}
		}
		cout<<-ans[n];
	}
	

	
}