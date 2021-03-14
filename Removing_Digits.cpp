#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define V vector
int getmax(int x){
	int mxx=-1;
	while(x){
		mxx=max(mxx,x%10);
		x/=10;
	}
	return mxx;
}
ll sol(int n){
	ll ans=0;
	while(n){
		ans++;
		n-=getmax(n);
		// cout<<ans<<" ";
	}
	return ans;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int n;
	cin>>n;
	cout<<sol(n);
	
}