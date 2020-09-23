#include<bits/stdc++.h>
#define ll long long
#define N ((int)3e5 + 5)
#define MOD ((int)1e8 + 7)
#define MAX ((int)1e9 + 7)
#define MAXL ((ll)1e18 + 7)
#define MAXP ((int)1e6 + 7)
#define thr 1e-8
#define pi acos(-1)  /// pi = acos ( -1 )
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"

using namespace std;


ll  arr[N];
pair < ll, int >  tab[22][N];
int range[N];


void rmq_max(int n)
{
    for(int i = 1; i<=n; i++)
        tab[0][i] = {arr[i],i};
    for(int j = 1; j<=20; j++)
    {
        for(int i = 1; i<=n; i++)
        {
            tab[j][i] = tab[j-1][i];
            int iii = i + (1<<(j-1));
            if(iii<=n)
                tab[j][i] = max(tab[j][i],tab[j-1][iii]);
        }
    }
    memset(range,-1,sizeof range);
    for(int j = 20 ; j>=0 ; j--)
    {
        int from = 1<<j;
        for(int i = from ; i<=n ; i++)
        {
            if(range[i] != -1)
                break;
            range[i] = j;
        }
    }
}


pair < ll, int > query_max(int l, int r)
{
    int b = range[r-l+1];
    pair < ll, int > ans = tab[b][l];
    int last = l + (1<<b) - 1;
    int rem = r - last;
    l = l+rem;
    return max(ans, tab[b][l]);
}

void rmq_min(int n)
{
    for(int i = 1; i<=n; i++)
        tab[0][i] = {arr[i],i};
    for(int j = 1; j<=20; j++)
    {
        for(int i = 1; i<=n; i++)
        {
            tab[j][i] = tab[j-1][i];
            int iii = i + (1<<(j-1));
            if(iii<=n)
                tab[j][i] = min(tab[j][i],tab[j-1][iii]);
        }
    }
    memset(range,-1,sizeof range);
    for(int j = 20 ; j>=0 ; j--)
    {
        int from = 1<<j;
        for(int i = from ; i<=n ; i++)
        {
            if(range[i] != -1)
                break;
            range[i] = j;
        }
    }
}


pair < ll, int > query_min(int l, int r)
{
    int b = range[r-l+1];
    pair < ll, int > ans = tab[b][l];
    int last = l + (1<<b) - 1;
    int rem = r - last;
    l = l+rem;
    return min(ans, tab[b][l]);
}

ll fun_max(int lef , int rig)
{
    if(lef > rig) return 0;
    pair < ll , int > p = query_max(lef,rig);
    ll ans = p.first;  /// ans = maximum element
    int idx = p.second;  /// idx = the index of that element
    ans = ans*(idx-lef+1)*(rig-idx+1) + fun_max(lef,idx-1) + fun_max(idx+1,rig);
    return ans;
}

ll fun_min(int lef , int rig)
{
    if(lef > rig) return 0;
    pair < ll , int > p = query_min(lef,rig);
    ll ans = p.first;  /// ans = maximum element
    int idx = p.second;  /// idx = the index of that element
    ans = ans*(idx-lef+1)*(rig-idx+1) + fun_min(lef,idx-1) + fun_min(idx+1,rig);
    return ans;
}

int main()
{
    fastio;

    int n;
    cin>>n;
    for(int i = 1 ; i<=n ; i++)
        cin>>arr[i];

    rmq_max(n);

    ll ans = fun_max(1,n);

    rmq_min(n);

    ans -= fun_min(1,n);

    cout<<ans<<endl;

    return 0;
}
