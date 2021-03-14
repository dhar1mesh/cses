#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define V vector
#define mod 1000000007
#define map map<long long,long long>
int n,q;
V<ll>A,ans;
// void buildtree(int si,int start,int end){
// 	if(start==end){
// 		ans[si]=A[start]^A[start-1];
// 		return ;
// 	}
// 	int mid=start+(end-start)/2;
// 	buildtree(2*si+1,start,mid);
// 	buildtree(2*si+2,mid+1,end);
// 	ans[si]=A[end]^A[start-1];

// }
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	cin>>n>>q;
	A.resize(n+1,0);
	ans.resize(4*n);
	for(int i=1,x;i<=n;i++){
		cin>>x;
		A[i]=A[i-1]^x;
	}
	// buildtree(0,0,n);
	// for(auto it:ans)cout<<it<<" ";
	while(q--){
		int a,b;
		cin>>a>>b;
		cout<<(A[b]^A[a-1])<<"\n";
	}
	
	
}