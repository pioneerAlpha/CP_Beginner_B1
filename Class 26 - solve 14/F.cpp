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


map < ll , bool > ppwr;

int dpp[2005];

vector < ll > pwr[42];

int src(int idx , ll val)
{
    int l = -1 , r = (int)pwr[idx].size()-1;
    while(l<r){
        int m = (l+r+1)/2;
        if(pwr[idx][m] > val) r = m-1;
        else l = m;
    }
    return l+1;
}

int call(int n)
{
    if(dpp[n] != -1) return dpp[n];
    if(n < 2) return dpp[n] = 1;
    int ans = 0;
    for(int i = 1 ; i<=n ; i++){
        ans = (ans + 1LL*call(i-1)*call(n-i))%MOD;
    }
    return dpp[n] = ans;
}

int main()
{
//    fastio;
    for(int i = 2 ; i<=(int)1e5 ; i++){
        if(ppwr[i]) continue;
        ll val = i;
        for(int j = 2 ; j<=40 ; j++){
            val = val*i;
            if(val >= MAXL) break;
            pwr[j].push_back(val);
            ppwr[val] = 1;
        }
    }
    for(int i = 2 ; i<=40 ; i++) sort(pwr[i].begin(),pwr[i].end());
    int t , caseno = 1;
    cin>>t;
    memset(dpp,-1,sizeof dpp);
    while(t--){
        ll a , b;
        cin>>a>>b;
        a--;
        int cnt = 0;
        for(int i = 2 ; i<=40 ; i++){
            cnt += src(i,b) - src(i,a);
        }
        int ans;
        if(cnt == 0) ans = 0;
        else ans = call(cnt);
        cout<<"Case "<<caseno++<<": "<<ans<<endl;
    }
    return 0;
}
