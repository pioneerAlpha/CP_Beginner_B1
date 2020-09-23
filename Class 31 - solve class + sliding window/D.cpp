#include<bits/stdc++.h>
#define ll long long
#define N ((int)1e6 + 5)
#define MOD ((int)1e9 + 7)
#define MAX ((int)1e9 + 7)
#define MAXL ((ll)1e18 + 7)
#define MAXP ((int)1e3 + 7)
#define thr 1e-8
#define pi acos(-1)  /// pi = acos ( -1 )
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"

using namespace std;


int  arr[N], range[N];
pair < int , int > tab[22][N];
void rmq(int n){
    for(int i = 1; i<=n; i++) tab[0][i] = {arr[i],i};
    for(int j = 1; j<=20; j++){
        for(int i = 1; i<=n; i++){
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
pair < int , int > query(int l, int r){
    int b = range[r-l+1];
    pair < int , int > ans = tab[b][l];
    int last = l + (1<<b) - 1;
    int rem = r - last;
    l = l+rem;
    return max(ans, tab[b][l]);
}

int col[N];

void fun(int lef , int rig , int l , int r) /// l = left index of the sub array , r = right index  /// lef = the color of tower l-1 , rig = color of r+1
{
    if(l>r) return;
    int idx = query(l,r).second;
    for(int i = 1 ; i<=3 ; i++){
        if(i != lef && i != rig){
            col[idx] = i;
            fun(lef,i,l,idx-1);
            fun(i,rig,idx+1,r);
            return;
        }
    }
}



int main()
{
    freopen("tour.in","r",stdin);
    fastio;
    int t;
    cin>>t;
    while(t--){
        int n ;
        cin>>n;
        for(int i = 1 ; i<=n ; i++) cin>>arr[i];
        rmq(n);
        fun(-1,-1,1,n);
        int ans = 0;

        bool vis[4];
        memset(vis,0,sizeof vis);
        for(int i = 1 ; i<=n ; i++){
            if(vis[col[i]] == 0){
                vis[col[i]] = 1;
                ans++;
            }
        }
        cout<<ans<<endl;
        for(int i = 1 ; i<=n ; i++) cout<<col[i]<<" ";
        cout<<endl;
    }
    return 0;
}
