#include<bits/stdc++.h>
#define ll long long
#define N ((int)2e5 + 5)
#define MOD ((int)1e9 + 7)
#define MAX ((int)1e9 + 7)
#define MAXL ((ll)1e18 + 7)
#define MAXP ((int)1e3 + 7)
#define thr 1e-8
#define pi acos(-1)  /// pi = acos ( -1 )
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"

using namespace std;


/// 0 for red , 1 for green , 2 for blue

int arr[4][205];

int dpp[205][205][205] , siz[4];

int call(int red , int grn , int blu)
{
    if(red < 0 || grn < 0 || blu < 0) return -MAX;
    if(dpp[red][grn][blu] != -1) return dpp[red][grn][blu];
    int ans = 0;
    ans = max(ans , call(red,grn-1,blu-1) + arr[1][grn]*arr[2][blu]);
    ans = max(ans , call(red-1,grn-1,blu) + arr[0][red]*arr[1][grn]);
    ans = max(ans , call(red-1,grn,blu-1) + arr[0][red]*arr[2][blu]);
    return dpp[red][grn][blu] = ans;
}

int main()
{
    fastio;
    for(int i = 0 ; i<3 ; i++) cin>>siz[i];
    for(int i = 0 ; i<3 ; i++){
        for(int j = 1 ; j<=siz[i] ; j++) cin>>arr[i][j];
        sort(arr[i]+1,arr[i]+siz[i]+1);
    }
    memset(dpp,-1,sizeof dpp);
    cout<<call(siz[0],siz[1],siz[2]);
    return 0;
}
