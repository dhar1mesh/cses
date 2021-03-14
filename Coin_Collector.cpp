#include<bits/stdc++.h>
using namespace std; 
#define ll long long
// #define V vector
#define mod 1000000007
#define map map<long long,long long>
int n,m;
vector<vector<ll>>ans,road,rroad;;
vector<ll>vis,st,coins;
ll dist=0;
ll cnt=0,cntt=0;
void dfs(int i){
	vis[i]=1;
	for(auto it:road[i]){
		if(!vis[it])dfs(it);
	}
	st.push_back(i);
}
void dfs2(int i){
	vis[i]=0;
	for(auto it:rroad[i]){
		if(vis[it])dfs2(it);
	}
	cnt+=coins[i];
	cntt++;
	
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	cin>>n>>m;
	road.resize(n+1);
	rroad.resize(n+1);
	coins.resize(n+1);
	for(int i=1;i<=n;i++){
		cin>>coins[i];
	}
	for(int i=0,a,b;i<m;i++){
		cin>>a>>b;
		road[a].push_back(b);
		rroad[b].push_back(a);
	}
	vis.resize(n+1,0);
	for(int i=1;i<n;i++){
		if(!vis[i])dfs(i);
	}
	for(int i=n-1;i>=0;i--){
		if(vis[st[i]])dfs2(st[i]);
		dist=max(cnt,dist);
		cout<<cnt<<" "<<cntt<<"\n";
		cnt=0,cntt=0;
	}
	cout<<dist<<"\n";
	
}