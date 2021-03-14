#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define V vector

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ll n,x;
	cin>>n>>x;
	V<V<ll>>A(n,V<ll>(2));
	multimap<ll,int>mp;
	for(int i=0;i<n;i++){
		cin>>A[i][0];A[i][1]=i+1;
		
	}
	sort(A.begin(),A.end());
	for(int i=0;i<n;i++){
		int j=i+1;
		int k=n-1;
		while(j<k){
			if(A[i][0]+A[j][0]+A[k][0]==x){
				cout<<A[i][1]<<" "<<A[j][1]<<" "<<A[k][1]<<"\n";
				return 0;
			}
			if(A[i][0]+A[j][0]+A[k][0]>x)k--;
			else j++;
		}
	}
	cout<<"IMPOSSIBLE\n";
}