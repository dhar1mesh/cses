#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define V vector
#define mod 1000000007
#define map map<long long,long long>
int n,q;
V<ll>A;
ll sumq(ll k){
	ll sm=0;
	ll j=k-(k&-k)+1;
	for(;j<=k;j++)sm+=A[j];
	return sm;
}
ll query(int b,V<ll>&sum){
	ll sm=0;
	while(b>=1){
		sm+=sum[b];
		b-=(b&-b);
	}
	return sm;
}
void update(V<ll>&sum,int k,int u){
	int y=u-A[k];
	A[k]=u;
	u=y;
	while(k<=n){
		sum[k]+=u;
		k+=(k&-k);
	}
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	cin>>n>>q;
	
	V<ll>sum(n+1,0);
	A.push_back(0);
	for(int i=1,x;i<=n;i++){
		cin>>x;
		A.push_back(x);
	}
	for(int i=1;i<=n;i++){
		sum[i]=sumq(i);
	}
	while(q--){
		int a,b,c;
		cin>>a>>b>>c;
		if(a==1){
			update(sum,b,c);
		}
		else{
			ll x=query(b-1,sum);
			ll y=query(c,sum);
			cout<<y-x<<"\n";
		}

	}

	
}