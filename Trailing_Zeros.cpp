#include<bits/stdc++.h>
using namespace std; 
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	long n;
	cin>>n;
	long long ans=0;
	for(long i=5;n/i>=1;i*=5){
		ans+=(n/i);
	}
	cout<<ans<<"\n";

	
}