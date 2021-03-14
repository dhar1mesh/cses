#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define V vector
ll ans=0;
int cnt=0;
V<V<ll>>dp;
ll sol(ll tar,ll i,int n){
	if(tar==0)return 1;
	cnt++;
	if(i>n||tar<0)return 0;
	if(dp[tar][i]!=-1)return dp[tar][i];
	ll x=sol(tar-i,i+1,n)%(2*1000000007);
	ll y=sol(tar,i+1,n)%(2*1000000007);
	dp[tar][i]=x+y;
	// dp[tar][i];
	return dp[tar][i]%(2*1000000007);
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int n;
	cin>>n;
	ll sum=(n*(n+1))/2;
	if(sum&1){
		cout<<0<<"\n";
		return 0;
	}

	else{
		dp.resize(sum/2+1,V<ll>(n+1,-1));
		cout<<((sol(sum/2,1,n))%(2*1000000007))/2;
	}
}