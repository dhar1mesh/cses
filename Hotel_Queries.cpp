#include<bits/stdc++.h>
using namespace std; 
// #define ll long long
// #define V vector
// #define mod 1000000007
// #define map map<long long,long long>
// int n,m;
// V<ll>hotels;
// int main(){
// 	#ifndef ONLINE_JUDGE
// 	freopen("input.txt","r",stdin);
// 	freopen("output.txt","w",stdout);
// 	#endif
// 	cin>>n>>m;
// 	for(int i=0;i<n;i++){
// 		int x;
// 		cin>>x;
// 		hotels.push_back(x);
// 	}
// 	V<ll>ans;
// 	while(m--){
// 		int x;
// 		cin>>x;
// 		while()
// 	}
	
// }

const int MAXM = (int)1e5+100;
const int MAXN = (int)2e5+100;
const int MOD = (int)1e9+7;
 
multiset<int , greater<int>> seg[4*MAXN];
long long arr[MAXN];
void build(int current_node , int start , int end){
    if(start == end){
        seg[current_node].insert(arr[start]);
        return; 
    }
    for(int i=start;i<=end; ++i){
        seg[current_node].insert(arr[i]);
    }
    int mid = (start + end) /2;
    build(2*current_node , start , mid);
    build(2*current_node +1 , mid+1 , end);
}
 
pair<int,int> query(int current  , int start , int end , int member){
    int x = *(seg[current].begin());
    if(x < member){
        return {-1,-1};
    }
    if(start==end){
        pair<int,int>p;
        p.first = x;
        p.second = start;
        seg[current].erase(seg[current].begin());
        if(x-member >0){
            seg[current].insert(x-member);
        }
        return p;
    }
    int mid = (start + end) /2;
    pair<int, int > ans;
    int y = *(seg[2*current].begin());
    if(y >= member){
        ans = query(2*current , start , mid , member);
    }else{
        ans = query(2*current+1 , mid+1 , end , member);
    }
    if(ans.first!=-1 && ans.second!=-1){
        auto itr = seg[current].find(ans.first);
        seg[current].erase(itr);
        if(ans.first - member >=0){
            seg[current].insert(ans.first-member);
        }
    }
    return ans;
}
 
int main(void){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
 
    int n , m; cin >> n >> m; 
    for(int i=0; i < n; ++i){
        cin >> arr[i];
    }
    build(1 , 0, n-1);
    while(m--){
        int x; cin >> x;
        pair<int,int> a = query(1 , 0 , n-1 , x) ;
        cout << a.second + 1 << ' ';
    }
 
#ifdef HELL_JUDGE
    auto FINAL_TIME = high_resolution_clock::now();
    cout << "Time : "
        << duration_cast<milliseconds>(FINAL_TIME-INITIAL_TIME).count() 
        << " ms" << '\n'; 
#endif 
    return 0;
}
