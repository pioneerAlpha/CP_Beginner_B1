#include<bits/stdc++.h>
#define ll long long
#define N ((int)1e5 + 5)
#define MOD ((int)1e9 + 7)
#define MAX ((int)1e9 + 7)
#define MAXL ((ll)1e18 + 7)
#define MAXP ((int)1e3 + 7)
#define thr 1e-8
#define pi acos(-1)  /// pi = acos ( -1 )
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"

using namespace std;


int  arr[7][N], range[N], tab[7][22][N];
void rmq(int n, int m)
{
    for(int idx = 1 ; idx<=m ; idx++)
    {
        for(int i = 1; i<=n; i++)
            tab[idx][0][i] = arr[idx][i];
        for(int j = 1; j<=20; j++)
        {
            for(int i = 1; i<=n; i++)
            {
                tab[idx][j][i] = tab[idx][j-1][i];
                int iii = i + (1<<(j-1));
                if(iii<=n)
                    tab[idx][j][i] = max(tab[idx][j][i],tab[idx][j-1][iii]);
            }
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
int query(int idx , int l, int r)
{
    int b = range[r-l+1];
    int ans = tab[idx][b][l];
    int last = l + (1<<b) - 1;
    int rem = r - last;
    l = l+rem;
    return max(ans, tab[idx][b][l]);
}

int shot[7];

int okk(int len, int n , int m) /// this function returns the minimum shots needed to destroy a sequence of length 'len'
{
    int ans = MAX;
    for(int i = 1 ; i<=n ; i++)
    {
        if(i + len - 1 <= n){   /// i is the left index ans i + len - 1 is the right index of the sequence
            int sum = 0;
            for(int j = 1 ; j<=m ; j++){
                sum += query(j,i,i+len-1);
            }
            if(sum < ans){
                ans = sum;
                for(int j = 1 ; j<=m ; j++) shot[j] = query(j,i,i+len-1);
            }
        }
    }
    return ans;
}


int main()
{
    fastio;
    int n, m , k;
    cin>>n>>m>>k;
    for(int i = 1 ; i<=n ; i++){
        for(int idx = 1 ; idx<=m ; idx++) cin>>arr[idx][i];
    }
    rmq(n,m);
    int lef = 0 , rig = n;
    while(lef < rig){
        int mid = (lef + rig + 1)>>1;
        if(okk(mid,n,m) <= k) lef = mid;
        else rig = mid-1;
    }
    okk(lef,n,m);
    for(int i = 1 ; i<=m ; i++) cout<<shot[i]<<" ";
    return 0;
}
