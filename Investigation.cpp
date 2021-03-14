#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define V vector
#define mod 1000000007
int n,m;
V<V<pair<ll,ll>>>flights,paths;
V<ll>vis,minm,mxm,ans,route;
void dij(){
	priority_queue<pair<ll,ll>>q;
	q.push({0,1});
	ans.resize(n+1,LLONG_MAX/2);
	ans[1]=0;
	mxm.resize(n+1,0);
	minm.resize(n+1,0);
	route.resize(n+1,0);
	route[1]=1;
	while(!q.empty()){
		ll x=-q.top().first;
		ll y=q.top().second;
		q.pop();
		for(auto it:paths[y]){
			ll a=it.first;
			ll b=it.second;
			if(ans[a]==x+b){
				route[a]+=route[y];
				route[a]%=mod;
				minm[a]=min(minm[a],minm[y]+1);
				mxm[a]=max(mxm[a],mxm[y]+1);

			}
			else if(ans[a]>x+b){
				ans[a]=x+b;
				q.push({-ans[a],a});
				route[a]=route[y];
				minm[a]=minm[y]+1;
				mxm[a]=mxm[y]+1;
				
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
	// cout<<n<<m<<"\n";
	paths.resize(n+1);
	// cout<<flights.size()<<" size ";
	for(int i=0;i<m;i++){
		ll x,y,z;
		cin>>x>>y>>z;

		paths[x].push_back({y,z});
		// cout<<x<< " "<<y<<"\n";
	}
	dij();
	cout<<ans[n]<<" "<<route[n]<<" "<<minm[n]<<" "<<mxm[n]<<"\n";
	
}