#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define V vector
V<V<ll>>dp;
int cnt=0;
ll sol(V<ll>&A,int i,int j,int st,ll sum){
	if(i>j)return 0;
	if(dp[i][j]!=-1)return dp[i][j];
	dp[i][j]=max(sum-sol(A,i+1,j,st,sum-A[i]),sum-sol(A,i,j-1,st,sum-A[j]));
	return dp[i][j];
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int n;
	cin>>n;
	V<ll>A(n);
	ll sum=0;
	for(int i=0;i<n;i++){
		cin>>A[i];
		sum+=A[i];
	}
	dp.resize(n+1,V<ll>(n+1,-1));
	cout<<sol(A,0,n-1,1,sum);
}