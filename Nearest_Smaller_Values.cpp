#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define V vector

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ll n;
	cin>>n;
	stack<ll>st;
	vector<ll>A(n);
	for(int i=0;i<n;i++){
		
		cin>>A[i];
		while(!st.empty()&&A[i]<=A[st.top()]){
			st.pop();
		}
		if(st.empty())cout<<"0 ";
		else cout<<st.top()+1<< " ";
		st.push(i);
	}
	
}