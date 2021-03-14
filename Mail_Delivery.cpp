#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define V vector
#define mod 1000000007
#define map map<long long,long long>
int n,m;
V<V<pair<ll,ll>>>root;
V<ll>v,u;
vector<ll>vis,st,cntt;
ll cnt=-1;
void dfs(ll &i){
	// for(int j=cntt[i]-1;j>=0;j--){
	
		// cout<<j<<" "<<i<<" "<<cntt[i]<<"\n";
		while(cntt[i]>0){
		int j=--cntt[i];
		// cout<<j<<" ";
		// cntt[i]--;
		// exit(0);
		if(!vis[root[i][j].second]){
			vis[root[i][j].second]=1;
			dfs(root[i][j].first);
		}
	}
	cnt++;
	st[cnt]=(i);
	
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	cin>>n>>m;

	root.resize(n+1);
	u.resize(m+1),v.resize(m+1);
	vis.resize(m+1,0);
	cntt.resize(n+1,0);
	for(ll i=1,a,b;i<=m;i++){
		cin>>a>>b;
		cntt[a]++;
		cntt[b]++;
		root[a].push_back({b,i});
		root[b].push_back({a,i});
	}
	for(int i=0;i<n;i++){
		if(root[i].size()&1){
			cout<<"IMPOSSIBLE";
			return 0;
		}
	}
	ll i=1;
	st.resize(m+1);
	dfs(i);
	// cout<<cnt<<"\n";
	if(m!=cnt){
		cout<<"IMPOSSIBLE";
		return 0;
	}
	st[0]=1;
	st[cnt]=1;
	// for(int i:cntt)cout<<i<<" ";
	for(auto &it:st)
		cout<<it<<" ";
	
}