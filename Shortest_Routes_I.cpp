#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define V vector
int n,m;
V<V<pair<ll,ll>>>flights;
V<int>vis;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	cin>>n>>m;
	flights.resize(n+1);
	for(int i=0;i<m;i++){
		ll x,y,z;
		cin>>x>>y>>z;
		flights[x].push_back({y,z});
	}
	V<ll>ans(n+1,LLONG_MAX);
	vis.resize(n+1,0);
	ans[1]=0;
	priority_queue<pair<ll,ll>>q;
	q.push({0,1});
	while(!q.empty()){
		ll a=q.top().second;
		q.pop();
		
		if(vis[a])continue;
		vis[a]=1;
		for(auto it:flights[a]){
			int b=it.first;
			int w=it.second;
			if(ans[b]>ans[a]+w){
				ans[b]=ans[a]+w;
				q.push({-ans[b],b});
			}
		}

	}
	for(int i=1;i<=n;i++)cout<<ans[i]<<" ";

	
}