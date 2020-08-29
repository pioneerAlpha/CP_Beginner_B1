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

ll dpp[105][105];

string str;

ll call(int pos , int rem)
{
    if(rem == 0) return 1;
    if(pos >= str.length()){
        return 0;
    }

    if(dpp[pos][rem] != -1) return dpp[pos][rem];
    ll ans = 0;

    for(char c = 'a' ; c <= 'z' ; c++){
        for(int i = pos ; i<str.length(); i++){
            if(str[i] == c){
                ans += call(i+1,rem-1);
                break;
            }
        }
    }
    return dpp[pos][rem] = ans;
}

int main()
{
    memset(dpp,-1,sizeof dpp);
    fastio;
    int n;
    ll k , ans = 0;

    cin>>n>>k>>str;
    for(int i = n ; i>=0 ; i--){
        ll tmp = call(0,i);
        if(tmp >= k){
            ans += k*(n-i);
            k = 0;
            break;
        }
        k -= tmp;
        ans += tmp*(n-i);
    }
    if(k > 0) ans = -1;
    cout<<ans<<endl;
    return 0;
}
