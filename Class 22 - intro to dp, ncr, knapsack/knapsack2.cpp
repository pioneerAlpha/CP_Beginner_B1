#include<bits/stdc++.h>
#define ll long long
#define N ((int)3e4 + 5)
#define MOD ((int)1e9 + 7)
#define MAX ((int)1e9 + 7)
#define MAXL ((ll)1e18 + 7)
#define MAXP ((int)1e3 + 7)
#define thr 1e-8
#define pi acos(-1)  /// pi = acos ( -1 )
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"

using namespace std;


int vol[105] , val[105] , n;

ll dpp[105][100005];

/// n <= 100 , cap <= 10^9 , val[i] <= 1000 , vol[i] <= 10^9
/// so , max profit <= 10^5

ll call(int cur , int pro)  /// returns minimum volume needed
/// to make a profit equals to pro from cur to n
{

    if(pro < 0) return MAXL;
    if(cur > n){
        if(pro == 0) return 0;
        else return MAXL;
    }

    if(dpp[cur][pro] != -1) return dpp[cur][pro];

    ll ans = MAXL;  /// assuming there is no valid answer

    ans = min( ans , call(cur+1,pro-val[cur]) + vol[cur] );
    ll tmp = call(cur+1,pro);

    ans = min(ans , tmp);

    return dpp[cur][pro] = ans;
}



/// state/memory : O ( n*profit )

/// time: O( n*profit )

int main()
{
    int cap;
    cin>>n>>cap;
    for(int i = 1 ; i<=n ; i++) cin>>val[i]>>vol[i];
    for(int pro = 1e5 ; pro >= 0 ; pro--){
        ll ans = call(1,pro);
        if(ans <= cap){
            cout<<pro<<endl;
            break;
        }
    }
    return 0;
}
