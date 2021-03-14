#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define V vector
#define mod 1000000007
#define map map<long long,long long>
int n,q;
V<V<char>>forest;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	cin>>n>>q;
	forest.resize(n,V<char>(n));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)cin>>forest[i][j];
	}
	V<V<ll>>ans(n+1,V<ll>(n+1,0));
	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<n;j++)cout<<forest[i][j];
	// 	cout<<"\n";
	// }
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			ans[i][j]=ans[i-1][j]+ans[i][j-1]-ans[i-1][j-1]+(forest[i-1][j-1]=='*');
			// cout<<ans[i][j]<<" ";
		}
		// cout<<"\n";
	}

	while(q--){
		int x1,x2,y1,y2;
		cin>>x1>>y1>>x2>>y2;
		cout<<ans[x2][y2]-ans[x2][y1-1]-ans[x1-1][y2]+ans[x1-1][y1-1]<<"\n";

	}
	
}