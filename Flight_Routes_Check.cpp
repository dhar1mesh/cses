#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define V vector
#define mod 1000000007
#define map map<long long,long long>
int n,m;
V<V<ll>>flights,rflights;
V<ll>vis,st;
int cnt=0;
void dfs(ll i){
	vis[i]=1;
	for(auto it:flights[i]){
		if(!vis[it])dfs(it);
	}
	st.push_back(i);
}
void dfs2(ll i){
	vis[i]=0;
	for(auto it:rflights[i]){
		if(vis[it])dfs2(it);
	}
	cnt++;

}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	cin>>n>>m;
	flights.resize(n+1);
	rflights.resize(n+1);
	for(ll i=0,a,b;i<m;i++){
		cin>>a>>b;
		flights[a].push_back(b);
		rflights[b].push_back(a);
	}
	vis.resize(n+1,0);
	// cout<<"a\n";
	for(int i=1;i<=n;i++){
		if(!vis[i])dfs(i);
	}
	vector<ll>ans;
	// for(int i=1;i<=n;i++)cout<<st[i]<<" ";
	for(int i=n-1;i>=0;i--){
		if(vis[st[i]]){
			dfs2(st[i]);
			if(cnt==n){
				cout<<"YES\n";
				return 0;
			}
			else
			ans.push_back(st[i]);
			cnt=0;
		}
		
	}
	// cout<<ans.size()<<" ";
	cout<<"NO\n"<<ans[1]<<" "<<ans[0];
	
}