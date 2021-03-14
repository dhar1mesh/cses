#include<bits/stdc++.h>
using namespace std;
long long sol(long long n,long long x){
	if(n==0)return 1;
	if(n&1){
		return (x*sol(n/2,x)*sol(n/2,x))%1000000007;
	}
	return (sol(n/2,x)*sol(n/2,x))%1000000007;

	
	
} 
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	long long n;
	cin>>n;
	cout<<sol(n,2)<<"\n";
	
}