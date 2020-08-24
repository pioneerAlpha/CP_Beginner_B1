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

int dpp[N]; /// dpp[i] = i-th fibo

int fib(int n)
{
    if(dpp[n] != -1) return dpp[n];
    int ans;
    if( n < 2 ) ans = n;
    else{
        ans = fib(n-1) + fib(n-2);
    }

    return dpp[n] = ans % MOD;
}

/// complexity : O ( n )

int main()
{
    memset(dpp,-1,sizeof dpp);

    int q;
    cin>>q;
    while(q--){
        int n;
        cin>>n;
        cout<<fib(n)<<endl;
    }
    return 0;
}
