#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define V vector
bool cmp(pair<ll,bool>a,pair<ll,bool>b){
	if(a.first==b.first){
		return a.second>b.second;
	}
	return a.first<b.first;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ll n;
	cin>>n;
	V<pair<ll,bool>>A;
	for(int i=0;i<n;i++){
		ll x,y;
		cin>>x>>y;
		A.push_back({x,1});
		A.push_back({y,0});
	}
	sort(A.begin(),A.end(),cmp);
	ll mxx=0, ans=0;
	vector<ll>res;
	for(int i=0;i<A.size();i++){
		if(A[i].second){
			ans++;
			mxx=max(ans,mxx);
			res.push_back(ans);
		}
		else{
			ans--;
		}
	}
	cout<<mxx<<"\n";
	for(auto it:res)cout<<it<< " ";
	
}