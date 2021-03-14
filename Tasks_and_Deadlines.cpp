#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define V vector

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ll n;
	cin>>n;
	vector<vector<ll>>A;
	for(int i=0;i<n;i++){
		ll x,y;
		cin>>x>>y;
		A.push_back({x,y});
	}
	sort(A.begin(),A.end());
	ll f=0,ans=0;
	for(int i=0;i<A.size();i++){
		f+=(A[i][0]);
		ans+=A[i][1]-f;
	}
	cout<<ans<<"\n";
	
}