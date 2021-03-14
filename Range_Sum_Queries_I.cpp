#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define V vector
#define mod 1000000007
#define map map<long long,long long>
int n,q;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	cin>>n>>q;
	V<ll>A(n+1,0);
	for(int i=1;i<=n;i++){
		ll a; 
		cin>>a;
		A[i]=A[i-1]+a;
	}
	while(q--){
		int a,b;
		cin>>a>>b;
		cout<<A[b]-A[a-1]<<"\n";
	}
	
}