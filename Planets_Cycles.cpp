#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define V vector
#define mod 1000000007
#define map map<long long,long long>
int n,m;
vector<ll>planets;
ll sol(ll i){
	ll cnt=1;
	vector<ll>vis(n+1,0);
	while(!vis[i]){
		cnt++;
		// if(vis[i])return cnt;
		// cout<<i<<" "<<planets[i]<<"\n";
		vis[planets[i]]=1;
		i=planets[i];
	}
	return cnt;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	cin>>n;
	planets.resize(n+1);
	for(int i=1;i<=n;i++){
		cin>>planets[i];
	}
	vector<ll>ans;
	for(int i=1;i<=n;i++){
		ll x=sol(i);
		cout<<"\n";
		ans.push_back(x);
	}
	for(auto it:ans){
		cout<<it<<" ";
		getchar();
	}
	
}