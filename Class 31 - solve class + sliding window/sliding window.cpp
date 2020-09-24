#include<bits/stdc++.h>
#define ll long long
#define N ((int)1e5 + 5)
#define MOD ((int)1e9 + 7)
#define MAX ((int)1e9 + 7)
#define MAXL ((ll)1e18 + 7)
#define MAXP ((int)1e3 + 7)
#define thr 1e-8
#define pi acos(-1)  /// pi = acos ( -1 )
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"

using namespace std;


int main()
{
    int n , k;
    cin>>n>>k;
    for(int i = 1 ; i<=n ; i++) cin>>arr[i];
    vector < pair < pair < int , int > , int > > vec;
    int q;
    cin>>q;
    for(int i = 1 ; i<=q ; i++){
        int l , r;
        cin>>l>>r;
        vec.push_back({{l,r},i}); /// storing the queries. answer them later.
    }

    sort(vec.begin(),vec.end());  /// sorting the queries according to their left index.

    deque < pair < int , int > > deq;  /// first element is the value and second element is the index
    int rig = 0;  /// rig = index of the last element that is pushed in the deq;
    for(auto p:vec){
        int l = p.first.first, r = p.first.second , idx = p.second;
        while(!deq.empty()){
            pair < int , int > p = deq.front();
            if(p.second < l) deq.pop_front();
            else break;
        }

        for(int i = rig+1 ; i<=r; i++){
            while(!deq.empty()){
                pair < int , int > p = deq.back();
                if(arr[i] <= p.first) deq.pop_back();
                else break;
            }
            deq.push_back({arr[i],i});
        }

        ans[idx] = deq.front().first;
    }

    for(int i = 1 ; i<=q ; i++) cout<<ans[i]<<endl;
    return 0;
}
