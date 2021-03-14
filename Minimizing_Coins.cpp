#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define V vector
V<V<ll>>dp;
ll ans=INT_MAX;
ll sol(int n,V<ll>&coins){
	vector<ll>value(n+1,0);
	value[0] = 0;
	for (int x = 1; x <= n; x++) {
	value[x] = INT_MAX;
	for (auto c : coins) {
			if (x-c >= 0) {
				value[x] = min(value[x],value[x-c]+1);
			}
		}
	}
	return value[n];
}
 main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int n;
	cin>>n;
	int x;
	cin>>x;
	vector<ll>C(n);
	sort(C.rbegin(),C.rend());
	for(int i=0;i<n;i++){
		cin>>C[i];
	}
	ll y=sol(x,C);
	if(y==INT_MAX)cout<<-1;
	else cout<<y;
	
}