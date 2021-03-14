#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define V vector
#define mod 1000000007
#define map map<long long,long long>
int n,m;
V<V<ll>>road;
ll cmp,mxsize=1;
V<ll>sze,link;
int find(ll a){
	while(link[a]!=a)a=link[a];
	return a;
}
void unite(ll x,ll y){
	if(sze[x]<sze[y]){
		swap(x,y);
	}
	sze[x]+=sze[y];
	link[y]=x;
	mxsize=max(mxsize,sze[x]);
}
void sol(ll a,ll b){
	ll x=find(a);
	ll y=find(b);
	if(x==y)return ;
	unite(x,y);
	cmp--;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	cin>>n>>m;
	// road.resize(n+1);
	cmp=n;
	sze.resize(n+1);
	link.resize(n+1);
	for(int i=1;i<=n;i++)sze[i]=1;
	for(int i=1;i<=n;i++)link[i]=i;
	for(int i=1;i<=m;i++){
		ll a,b;
		cin>>a>>b;
		sol(a,b);
		cout<<cmp<<" "<<mxsize<<"\n";
		road.push_back({a,b});
	}

	
}