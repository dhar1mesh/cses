#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define V vector
#define mod 1000000007
#define map map<long long,long long>
int n,q;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	cin>>n>>q;
	V<ll>A(n);
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	
	
	int k=log2(n+1);

	V<V<ll>>pre(n+1,V<ll>(k+1));
	for(int i=0;i<n;i++){
		pre[i][0]=A[i];
	}
	for(int j=1;j<=k;j++){
		for(int i=0;(i+(1<<(j)))<=n;i++){
			pre[i][j]=min(pre[i][j-1],pre[i+(1<<(j-1))][j-1]);
		}
	}
	while(q--){
		int a,b;
		cin>>a>>b;

		int j=log2(b-a+1);
		a--;b--;
		cout<<min(pre[a][j],pre[b-(1<<(j))+1][j])<<"\n";
	}
	
	
}