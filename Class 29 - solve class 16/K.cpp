#include<bits/stdc++.h>
#define ll long long
#define N ((int)2e5 + 5)
#define MOD ((int)1e8 + 7)
#define MAX ((int)1e9 + 7)
#define MAXL ((ll)1e10 + 7)
#define MAXP ((int)1e6 + 7)
#define thr 1e-8
#define pi acos(-1)  /// pi = acos ( -1 )
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"

using namespace std;

vector < int > seq[N];

int arr[N] , tmp[N];

int main()
{
    fastio;
    int n;
    cin>>n;
    for(int i = 1 ; i<=n ; i++) cin>>arr[i];
    memset(tmp,-1,sizeof tmp); /// tmp[i] = stores the last element of i-th increasing sequence
    /// initially we will assume every increasing sequence has the last element equals to -1
    /// it will make the implementation easier
    for(int i = 1 ; i<=n ; i++){
        int lef = 1 , rig = n;
        while(lef<rig){
            int mid = (lef + rig)/2;
            if(tmp[mid] < arr[i]) rig = mid;
            else lef = mid+1;
        }
        tmp[lef] = arr[i];
        seq[lef].push_back(arr[i]);
    }
    for(int i = 1 ; i<=n ; i++){
        if(seq[i].size() == 0) break;
        for(int a:seq[i]) cout<<a<<" ";
        cout<<endl;
    }
    return 0;
}
