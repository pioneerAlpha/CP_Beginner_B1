#include<bits/stdc++.h>
#define ll long long
#define N ((int)1e4 + 5)
#define MOD ((int)1e8 + 7)
#define MAX ((int)1e9 + 7)
#define MAXL ((ll)1e10 + 7)
#define MAXP ((int)1e6 + 7)
#define thr 1e-8
#define pi acos(-1)  /// pi = acos ( -1 )
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"

using namespace std;

int arr[1005] , dpp[1005] , nxt[1005];

int main()
{

    int n;
    cin>>n;
    for(int i = 1 ; i<=n ; i++) cin>>arr[i];
    memset(nxt,-1,sizeof nxt);
    for(int i = 1 ; i<=n ; i++){
        int ans = 0;
        for(int j = 1 ; j<i ; j++){
            if(arr[i] > arr[j] && ans < dpp[j]){
                ans = dpp[j];
                nxt[i] = j;
            }
        }
        dpp[i] = ans+1;
    }
    int lis = 0 , last;
    for(int i = 1 ; i<=n ; i++){
        if(lis < dpp[i]){
            lis = dpp[i];
            last = i;
        }
    }
    vector < int > vec;
    while(last != -1){
        vec.push_back(last);
        last = nxt[last];
    }
    reverse(vec.begin(),vec.end());
    cout<<lis<<endl;
    for(int a:vec) cout<<arr[a]<<" ";
    cout<<endl;
    return 0;
}
