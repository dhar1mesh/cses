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
	V<ll>A(n);
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	int i=0,j=0;
	ll sum=0;
	ll cnt=0;
	while(i<n){
		sum+=A[i];
		if(sum==x){
			cnt++;
		}
		while(j<=i&&sum>x){
			sum-=A[j];
			j++;
			if(sum==x){
				cnt++;
				break;
			}
		}
		i++;
	}
	cout<<cnt<<"\n";
	
}