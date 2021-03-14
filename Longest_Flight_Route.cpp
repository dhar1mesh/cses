#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define V vector
int n,m;
V<V<pair<ll,ll>>>flights;
V<ll>par,vis,ans,res;
void dij(){
	ans.resize(n+1,INT_MAX/2);
	ans[1]=0;
	par.resize(n+1,0);
	priority_queue<pair<ll,ll>,
	vector<pair<ll,ll>>,
	greater<pair<ll,ll>>>q;
	q.push({0,1});
	par[1]=-1;
	while(!q.empty()){
		ll u=q.top().second;
		ll d=q.top().first;
		q.pop();
		for(auto it:flights[u]){
			ll v=it.first;
			ll c=it.second;
			if(ans[v]>c+d){
				ans[v]=c+d;
				q.push({ans[v],v});
				par[v]=u;
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
	for(int i=0;i<m;i++){
		ll a,b;
		cin>>a>>b;
		flights[a].push_back({b,-1});
	}
	// cout<<"a";
	
	dij();
	// cout<<"a";
	if(par[n]){
		V<ll>ans;
		while(n!=-1){
			ans.push_back(n);
			n=par[n];
			if(n==1){
				ans.push_back(1);
				break;
			}
		}
		reverse(ans.begin(),ans.end());
		cout<<ans.size()<<"\n";
		for(int i:ans)cout<<i<< " ";
		return 0; 
	}
	cout<<"IMPOSSIBLE";
	
}