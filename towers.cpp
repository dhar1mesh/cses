#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define V vector
bool cmp(pair<ll,int>a,pair<ll,int>b){
	if(a.first==b.first)return a.second>b.second;
	return a.first>b.first;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ll n;
	cin>>n;
	V<pair<ll,int>>P(n);
	for(int i=0;i<n;i++){
		ll x;
		cin>>x;
		P.push_back({x,i});
	}

	sort(P.begin(),P.end(),cmp);
	// reverse(P.begin(),P.end(),cmp);
	int ind=-1;
	ll ans=0;
	ll pre=-1,same=1;
	for(int i=0;i<n;i++){
		if(P[i].second<ind&&P[i].first!=pre){
			ans++;
			ind =P[i].second;
			same=1;
			pre=P[i].first;
			cout<<ans<<" ";
		}
		else {
			same++;
			ans=max(ans,same);
			// ind=min(P[i].second,ind);
		}
	}
	cout<<ans<<"\n";
	
}