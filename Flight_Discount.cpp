#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define V vector
int n,m;
V<V<pair<ll,ll>>>flights,rflights;
V<ll>vis,res,res1;
ll rdijikshtra(){
	priority_queue<pair<ll,ll>>q;
	q.push({0,n});
	vis.resize(n+1,0);
	res1[n]=0;
	for(int i=1;i<=n;i++)vis[i]=0;
	while(!q.empty()){
		pair<ll,ll>p=q.top();
		q.pop();
		ll x=p.second;
		if(vis[x])continue;
		vis[x]=1;
		for(auto it:rflights[x]){
			if(!vis[it.first]){

				if(res1[it.first]>res1[x]+it.second){
					res1[it.first]=res1[x]+it.second;
					q.push({-res1[it.first],it.first});
				}
			}
		}
	}
}
ll dijikshtra(){
	priority_queue<pair<ll,ll>>q;
	q.push({0,1});
	vis.resize(n+1,0);
	res[1]=0;
	while(!q.empty()){
		pair<ll,ll>p=q.top();
		q.pop();
		ll x=p.second;
		if(vis[x])continue;
		vis[x]=1;
		for(auto it:flights[x]){
			if(!vis[it.first]){
				if(res[it.first]>res[x]+it.second){
					res[it.first]=res[x]+it.second;
					q.push({-res[it.first],it.first});
				}
			}
		}
	}
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	cin>>n>>m;
	flights.resize(n+1);
	rflights.resize(n+1);
	for(int i=0;i<m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		flights[x].push_back({y,z});
		rflights[y].push_back({x,z});
	}
	res.resize(n+1,LLONG_MAX/2);
	res1.resize(n+1,LLONG_MAX/2);
	dijikshtra();
	rdijikshtra();
	ll ans=LLONG_MAX;
	for(int i=1;i<=n;i++){
		for(auto it:flights[i]){
			ll x=it.first;
			ll w=it.second;
			ans=min(ans,res[i]+w/2+res1[x]);
			// cout<<ans<<"\n";
		}
	}
	cout<<ans<<"\n";
}