#include<bits/stdc++.h>
using namespace std; 
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int n;
	cin>>n;
	if(n==1){
		cout<<1;
		return 0;
	}
	if(n<=3){
		cout<<"NO SOLUTION\n";
		return 0;
	}
	if(n==4){
		cout<<"2 4 1 3\n";
		return 0;

	}
	for(int i=1;i<=n;i+=2)cout<<i<<" ";
		for(int i=2;i<=n;i+=2)cout<<i<<" ";
	
	
}