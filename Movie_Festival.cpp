#include<bits/stdc++.h>
using namespace std; 
bool cmp(vector<long long>a,vector<long long>b){

	return a[1]<b[1];
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("test_input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	long long n;
	cin>>n;
	// cout<<n<<"\n";
	vector<vector<long long>>A(n,vector<long long>(2));
	for(int i=0;i<n;i++){
		cin>>A[i][0]>>A[i][1];
	}
	sort(A.begin(),A.end(),cmp);
	int mxx=1;
	long cnt=1;

	long long et=A[0][1],st=A[0][0];
	// cout<<et<<" "<<st<<"\n";
	for(int i=1;i<n;i++){
		if(et<=A[i][0]){
			cnt++;
			et=A[i][1];
		}
		// if(i==666)cout<<i<<"\n";
	}
	cout<<cnt<<"\n";
	
}