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
	vector<ll>A(n);
	ll sum=0;
	for(int i=0;i<n;i++){
		cin>>A[i];
		sum+=A[i];
	}
	sort(A.begin(),A.end());
	cout<<max(2ll *A[n-1],sum);


}