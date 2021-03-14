#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define V vector
#define mod 1000000007
#define map map<long long,long long>
int n,m;
V<V<ll>>planets;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	cin>>n>>m;
	planets.resize(31,V<ll>(n+1));
	for(int i=0;i<n;i++)cin>>planets[0][i],planets[0][i]--;
	for(int i=1;i<30;i++){
		for(int j=0;j<n;j++){
			planets[i][j]=planets[i-1][planets[i-1][j]];
		}
	}
	while(m--){
		ll x,k;
		cin>>x>>k;
		x--;
		for(int i=0;i<30;i++){
			if(k>>i&1){
				x=planets[i][x];
			}
		}
		cout<<x+1<<"\n";;
	}

}