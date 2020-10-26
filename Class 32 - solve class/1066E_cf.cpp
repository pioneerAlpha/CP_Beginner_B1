#include<bits/stdc++.h>
#define N ((int)2e5 + 5)
#define MOD ((int)998244353 + 0)
#define ll long long
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define MAX ((int)1e6 + 5)
#define endl "\n"

using namespace std;

int sum[N];


int main()
{
    fastio;
    int n , m;
    string stra,  strb;
    cin>>n>>m>>stra>>strb;
    reverse(stra.begin(),stra.end());
    reverse(strb.begin(),strb.end());
    for(int i = m - 1 ; i>=0 ; i--) sum[i] = sum[i+1] + (strb[i] == '1');
    int mul = 1 , ans = 0;
    for(int i = 0 ; i<n ; i++){
        if(stra[i] == '1'){
            ans = (ans + 1LL*mul*sum[i]) % MOD;
        }
        mul = mul+mul;
        if(mul >= MOD) mul -= MOD;
    }
    cout<<ans<<endl;
    return 0;
}
