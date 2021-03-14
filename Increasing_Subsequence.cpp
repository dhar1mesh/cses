#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define V vector
ll sol(V<ll>A,int i){
    vector<ll>mp;
    for(int i=0;i<A.size();i++){
        auto it=lower_bound(mp.begin(),mp.end(),A[i]);
        if(it==mp.end())mp.push_back(A[i]);
        else *it=A[i];
    }
    int x=mp.size();
    return x;

}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    cin>>n;
    V<ll>A(n);
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    cout<<sol(A,0);
    // cout<<st.size();
    
}