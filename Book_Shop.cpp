#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define V vector
ll sol(ll W, V<ll>wt,V<ll>val, int n) 
{ 
    vector<ll>ans(W+1,0);
    for(int i=0;i<n;i++){
    	for(ll j=W;j>=wt[i];j--){
    		ans[j]=max(ans[j],val[i]+ans[j-wt[i]]);
    	}
    }
    return ans[W];
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int n,x;
	cin>>n>>x;
	
	V<ll>h(n),s(n);
	for(int i=0;i<n;i++){
		cin>>h[i];
	}
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	
	cout<<sol(x,h,s, n);
 
}