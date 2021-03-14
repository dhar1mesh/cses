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
	cin>>x>>n;
	vector<ll>ans;
	set<ll>st={0,x};
	multiset<ll>res={x};
	for(int i=0;i<n;i++){
		ll x;
		cin>>x;
		auto it=st.upper_bound(x);
		auto it1=it;
		ll right=*it;
		*it--;
		ll left=*it;
		res.erase(res.find(right-left));
		res.insert(x-left);
		res.insert(right-x);
		st.insert(x);
		cout<<*res.rbegin()<<" ";
	}
}