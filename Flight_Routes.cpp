#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define V vector
int n,m,k;
V<V<pair<ll,ll>>>flights;
V<ll>ans,rans;
V<V<ll>>res;
void dijik(){
	res.resize(n+1,V<ll>(k,LLONG_MAX/2));
	// for(int i=0;i<k;i++)res[1][i]=0;
	priority_queue<pair<ll,ll>>q;
	q.push({0,1});
	V<ll>vis(n+1,0);
	while(!q.empty()){
		ll x=q.top().first;
		ll y=q.top().second;
		q.pop();
		if(vis[y])continue;
		// vis[y]=1;
		if(res[y][k-1]<-x)continue;
		for(auto it:flights[y]){
			ll a=it.first;
			ll b=it.second;

			if(res[a][k-1]>b-x){
				res[a][k-1]=b-x;
				q.push({-res[a][k-1],a});
				sort(res[a].begin(),res[a].end());
			}
		}
	}
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	cin>>n>>m>>k;
	flights.resize(n+1);
	
	for(int i=0;i<m;i++){
		ll a,b,c;
		cin>>a>>b>>c;
		flights[a].push_back({b,c});
	}	
	dijik();
	for(auto p:res[n]){
		cout<<p<<" ";
	}
}