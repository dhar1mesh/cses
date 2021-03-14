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
	for(int i=0;i<n;i++)cin>>A[i];
	map<ll,pair<int,int>>mp;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			mp[A[i]+A[j]]={i,j};
		}
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(mp.find(x-A[i]-A[j])!=mp.end()){
				auto it=mp[x-A[i]-A[j]];
				if(it.first!=i&&it.first!=j&&it.second!=i&&it.second!=j){
					cout<<i+1<<" "<<j+1<<" "<<it.first+1<<" "<<it.second+1;
					return 0;
				}
			}
		}
	}
	cout<<"IMPOSSIBLE";

	
}