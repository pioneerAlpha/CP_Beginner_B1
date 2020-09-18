#include<bits/stdc++.h>
#define ll long long
#define N ((int)1e5 + 5)
#define MOD ((int)1e8 + 7)
#define MAX ((int)1e9 + 7)
#define MAXL ((ll)1e10 + 7)
#define MAXP ((int)1e6 + 7)
#define thr 1e-8
#define pi acos(-1)  /// pi = acos ( -1 )
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"

using namespace std;


/// range minimum query
int tab[N][22],  arr[N], range[N];
void rmq(int n){
    for(int i = 1; i<=n; i++) tab[i][0] = arr[i];
    for(int j = 1; j<=20; j++){
        for(int i = 1; i<=n; i++){
            tab[i][j] = tab[i][j-1];
            int iii = i + (1<<(j-1));
            if(iii<=n) tab[i][j] = min(tab[i][j],tab[iii][j-1]);
        }
    }
    memset(range,-1,sizeof range);
    for(int j = 20 ; j>=0 ; j--){
        int from = 1<<j;
        for(int i = from ; i<=n ; i++){
            if(range[i] != -1) break;
            range[i] = j;
        }
    }
}
int query(int l, int r){
    int b = range[r-l+1];
    int ans = tab[l][b];
    int last = l + (1<<b) - 1;
    int rem = r - last;
    l = l+rem;
    return min(ans , tab[l][b]);  
}

int main()
{
    int n , q;
    cin>>n>>q;
    for(int i = 1 ; i<=n ; i++) cin>>arr[i];
    rmq(n);
    while(q--){
      int l , r;
      cin>>l>>r;
      cout<<query(l,r)<<endl;
    }
    return 0;
}
