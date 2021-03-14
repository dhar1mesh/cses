#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define V vector
#define mod 1000000007
#define map map<long long,long long>
int n,m;
V<V<int>>tree;
V<ll>down,diam;
void downpath(int child,int par){
	ll ans=0;
	int leaf=1;
	for(auto it:tree[child]){
		if(it!=par){
			leaf=0;
			downpath(it,child);
			ans=max(ans,down[it]);
		}
	}
	if(leaf)down[child]=0;
	else down[child]=1+ans;
	// cout<<ans<<"\n";
}
void diameter(int child,int par){
	ll ans=0;
	V<ll>childs;
	for(auto it:tree[child]){
		if(it!=par){
			diameter(it,child);
			ans=max(ans,diam[it]);
			childs.push_back(down[it]);
		}
	}
	sort(childs.begin(),childs.end());
	int size=childs.size();
	if(size==0){
		diam[child]=0;
	}
	else if(size==1){
		diam[child]=1+childs[0];
	}
	else {
		diam[child]=2+childs[size-1]+childs[size-2];
	}
	diam[child]=max(ans,diam[child]);
	cout<<diam[child]<<" "<<child<<"\n";
	// cout<<childs[0];

}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	cin>>n;
	tree.resize(n+1);
	for(int i=0;i<n-1;i++){
		int x,y;
		cin>>x>>y;
		tree[x].push_back(y);
		tree[y].push_back(x);
	}
	down.resize(n+1);
	diam.resize(n+1);
	downpath(1,0);
	diameter(1,0);
	// sort(diam.begin(),diam.end());
	for(int i=1;i<=n;i++)
	cout<<diam[i]<<" ";

	
}