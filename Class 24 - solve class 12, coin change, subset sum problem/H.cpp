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


string str;

int dpp[N];

int call(int idx)
{
    if(idx >= str.length()) return 1;
    if(dpp[idx] != -1) return dpp[idx];
    int ans = call(idx+1);
    if((str[idx] == 'u' || str[idx] == 'n') && str[idx] == str[idx+1]) ans = (ans + call(idx+2)) % MOD;
    if(str[idx] == 'w' || str[idx] == 'm') ans = 0;
    return dpp[idx] = ans;
}

int main()
{
    cin>>str;
    memset(dpp,-1,sizeof dpp);
    cout<<call(0)<<endl;
    return 0;
}
