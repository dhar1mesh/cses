#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define V vector
V<V<ll>>dp;
 
ll sol(int m, int n) {
	if(m==n)return 1;
	ll hr =INT_MAX;
	ll vr=INT_MAX;
	ll &res=dp[n][m];
	if(res!=-1)return res;
	for(int i=1;i<=m/2;i++){
		hr=min(hr,sol(m-i,n)+sol(i,n));
	}
	for(int i=1;i<=n/2;i++){
		vr=min(vr,sol(m,n-i)+sol(m,i));
	}
	res=min(hr,vr);
	return res;
}

 
int main() 
{ 
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int m , n ;
	cin>>n>>m; 
	dp.resize(n+1,V<ll>(m+1,-1));
	cout << sol(m, n)-1; 
	return 0; 
} 

// This code is contributed by Utkarsh Gupta 
