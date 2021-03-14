#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define V vector
V<V<ll>>dp;
V<ll>d;
ll sol(ll n,vector<int>&dice,int i,ll tar){
	if(tar==n)return 1;
	if(i>=dice.size()||tar>n)return 0;
	if(dp[tar][i]!=-1)return dp[tar][i];
	ll res= sol(n,dice,0,tar+dice[i])+sol(n,dice,i+1,tar);
	dp[tar][i]=res%1000000007;
	return dp[tar][i]%1000000007;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ll n;
	cin>>n;
	d.resize(n+1,-1);
	dp.resize(n+1,V<ll>(7,-1));
	vector<int>dice={1,2,3,4,5,6};
	cout<<sol(n,dice,0,0);
}