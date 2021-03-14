#include<bits/stdc++.h>
using namespace std; 
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int n;
	cin>>n;
	vector<long long>A(n);
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	long long ans=INT_MIN,sum=0;
	for(int i=0;i<n;i++){
		sum+=A[i];
		
		ans=max(sum,ans);
		if(sum<0)sum=0;
	}
	cout<<ans<<"\n";

	
}