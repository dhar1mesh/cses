#include<bits/stdc++.h>
using namespace std; 
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	string s;
	cin>>s;
	int cnt=1;
	int mxx=1;
	for(int i=1;i<s.size();i++){
		if(s[i]==s[i-1]){
			cnt++;
			mxx=max(mxx,cnt);
		}
		else cnt=1;
		// cout<<mxx<<" ";
	}
	cout<<mxx<<"\n";
	
}