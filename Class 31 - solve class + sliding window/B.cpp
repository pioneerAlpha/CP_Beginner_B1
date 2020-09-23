#include<bits/stdc++.h>
#define ll long long
#define N ((int)1e5 + 5)
#define MOD ((int)1e8 + 7)
#define MAX ((int)1e9 + 7)
#define MAXL ((ll)1e18 + 7)
#define MAXP ((int)1e6 + 7)
#define thr 1e-8
#define pi acos(-1)  /// pi = acos ( -1 )
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"

using namespace std;


ll tab[22][N],  arr[N];
int range[N];
void rmq_min(int n)
{
    for(int i = 1; i<=n; i++)
        tab[0][i] = arr[i];
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

void rmq_max(int n)
{
    for(int i = 1; i<=n; i++)
        tab[0][i] = arr[i];
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

ll query_min(int l, int r)
{
    int b = range[r-l+1];
    ll ans = tab[b][l];
    int last = l + (1<<b) - 1;
    int rem = r - last;
    l = l+rem;
    return min(ans, tab[b][l]);
}

ll query_max(int l, int r)
{
    int b = range[r-l+1];
    ll ans = tab[b][l];
    int last = l + (1<<b) - 1;
    int rem = r - last;
    l = l+rem;
    return max(ans, tab[b][l]);
}

int main()
{
    fastio;
    int t, caseno = 1;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        for(int i = 1 ; i<=n ; i++)
            cin>>arr[i];
        rmq_min(n);
        for(int i = 1 ; i<=n ; i++){
            if(i + k - 1 > n) arr[i] = MAXL;
            else arr[i] = query_min(i,i+k-1);
        }
        rmq_max(n);
        cout<<"Case "<<caseno++<<":\n";
        int q;
        cin>>q;
        while(q--)
        {
            int l, r;
            cin>>l>>r;
            r = r - k + 1;
            if(r < l) cout<<"Impossible\n";
            else cout<<query_max(l,r)<<endl;
        }
    }
    return 0;
}
