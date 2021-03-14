#include<bits/stdc++.h>
using namespace std; 
long long K;
bool cmp(long long a,long long b){
	return abs(a-K)<=abs(b-K);
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	long long n,m,k;
	cin>>n>>m>>k;
	vector<long long>A(n);
	vector<long long>B(m);
	for(int i=0;i<n;i++)cin>>A[i];
	for(int i=0;i<m;i++)cin>>B[i];
	sort(A.begin(),A.end());
	sort(B.begin(),B.end());
	int cnt=0;
	int i=0,j=0;
	while(i<A.size()&&j<B.size()){
		if(A[i]+k>=B[j]&&B[j]>=A[i]-k){
			// cout<<B[j]<<" "<<i<<" "<<j<<" \n";
			i++;
			j++;
			cnt++;
			
		}
		else if(A[i]+k>B[j]){
			j++;
		}
		else i++;
	}
	cout<<cnt<<"\n";
	
}