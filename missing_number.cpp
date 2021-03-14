#include<bits/stdc++.h>
using namespace std; 
int main(){
	#ifndef ONLINE_JUDGE
	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	long long  n;
	cin>>n;
	long long sum=0;
	for(int i=0;i<n-1;i++){
		int x;
		cin>>x;
		sum+=x;
	}
	cout<<(n*(n+1))/2-sum<<"\n";
}