#include<bits/stdc++.h>
using namespace std; 
#define ll long long
// #define V vector
#define mod 1000000007
#define map map<long long,long long>
int n,m;
vector<vector<ll>>ans,road,roads;;
vector<ll>link,siize;
ll dist=0;
bool bfs(){
	queue<int>q;
	vector<int>vis(n+1,0);
	q.push(1);
	ll cnt=1;
	// vis[1]=1;
	while(!q.empty()){
		ll x=q.front();
		q.pop();
		if(vis[x])continue;
		cnt++;
		vis[x]=1;
		
		for(auto it:roads[x]){
			if(!vis[it])q.push(it);
		}
	}
	return (cnt-1)!=n;
}
ll find(ll a){
	while(a!=link[a])a=link[a];
	return a;
}
void kruskals(){
	siize.resize(n+1);
	link.resize(n+1);
	ans.resize(n+1);
	for(int i=1;i<=n;i++)siize[i]=1;
	for(int i=1;i<=n;i++)link[i]=i;
	for(int i=0;i<m;i++){
		ll a=road[i][1];
		ll b=road[i][2];
		ll x=find(a);
		ll y=find(b);
		if(x!=y){
			ans[x].push_back(y);
			dist+=road[i][0];
			if(siize[x]<siize[y]){
				swap(x,y);
			}
			siize[x]+=siize[y];
			link[y]=x;
		}
	}
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	cin>>n>>m;
	roads.resize(n+1);
	for(int i=0;i<m;i++){
		ll x,y,z;
		cin>>x>>y>>z;
		road.push_back({z,x,y});
		roads[x].push_back(y);
		roads[y].push_back(x);
	}
	if(bfs()){
		cout<<"IMPOSSIBLE";
		return 0;
	}
	
	sort(road.begin(),road.end());
	kruskals();
	cout<<dist<<"\n";
	
}