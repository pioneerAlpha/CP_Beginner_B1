/// problem link: https://leetcode.com/problems/partition-to-k-equal-sum-subsets/
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

int sum , n , arr[17];

int pre[2+(1<<16)], dpp[2+(1<<16)];
/// comp : 3^16
bool call(int mask)
{
    if(dpp[mask] != -1) return dpp[mask];

    if(mask == 0) return dpp[mask] = 1;
    bool ans = 0;
    for(int sub = mask ; sub>0 ; sub = (sub-1)&mask){
        int tmp = pre[sub];
        if(tmp == sum){
            ans = ans | call(mask^sub);
        }
    }
    return dpp[mask] = ans;
}

int main()
{

    int  k ;
    sum = 0;
    cin>>n>>k;
    for(int i = 0 ; i<n ; i++){
        cin>>arr[i];
        sum += arr[i];
    }

    for(int mask = 0 ; mask < (1<<n) ; mask++){
        int tmp = 0;
        for(int i = 0 ; i<n ; i++){
            if((mask&(1<<i)) != 0) tmp += arr[i];
        }
        pre[mask] = tmp;
    }
    /// comp : (2^n)*n

    memset(dpp,-1,sizeof dpp);

    if(sum % k != 0){
        cout<<"False\n";
        return 0;
    }
    sum = sum / k;
    if(call((1<<n)-1) == 1) cout<<"True\n";
    else cout<<"False\n";
    return 0;
}
