#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define V vector
int n,m,q;
V<V<ll>>road;
V<int>vis;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	cin>>n>>m>>q;
	road.resize(n+1,V<ll>(n+1,INT_MAX));
	vis.resize(n+1,0);
	for(int i=0;i<m;i++){
		ll a,b,w;
		cin>>a>>b>>w;
		road[a][b]=min(w,road[a][b]);
		road[b][a]=min(w,road[b][a]);
	}
	V<V<ll>>ans(n+1,V<ll>(n+1,LLONG_MAX/2));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j){
				ans[i][j]=0;
			}
			else if(road[i][j]!=INT_MAX)ans[i][j]=road[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				ans[j][k]=min(ans[j][k],ans[j][i]+ans[i][k]);
			}
		}
	}
	while(q--){
		int a,b;
		cin>>a>>b;
		if(ans[a][b]==LLONG_MAX/2)cout<<-1<<"\n";
		else
		cout<<ans[a][b]<<endl;
	}
	
}