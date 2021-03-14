#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define V vector

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ll n,x;
	cin>>n>>x;
	vector<ll>A(n);
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	map<ll,ll>mp;
	mp[0]=1;
	ll sum=0;
	ll cnt=0;
	for(int i=0;i<n;i++){
		sum+=A[i];
		
		cnt+=mp[sum-x];
		mp[sum]++;
	}
	cout<<cnt;
	
}