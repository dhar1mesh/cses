#include<bits/stdc++.h>
using namespace std; 
int main(){
	#ifndef ONLINE_JUDGE

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	long long n,x;
	cin>>n>>x;
	long long res=0;
	vector<long long>A(n);
	for(int i=0;i<n;i++){
		cin>>A[i];
		res+=A[i];
	}
	// cout<<res<<"\n";
	// exit(0);
	sort(A.begin(),A.end());
	int ans=0;
	int i=0;
	int j=n-1;
	while(i<=j){
		long long sum=0;
		int cnt=0;
		while(sum<=x){
			if(j>=i&&sum+A[j]<=x){
				sum+=A[j];
				cnt++;
				j--;
				if(cnt>=2)break;
			}
			else break;
		}
		while(sum<=x&&cnt<2){
			if(i<=j&&sum+A[i]<=x){
				sum+=A[i];
				i++;
				cnt++;
				if(cnt>=2)break;
			}
			else break;
		}
		
		
		ans++;
	}
	cout<<ans<<"\n";
	
}