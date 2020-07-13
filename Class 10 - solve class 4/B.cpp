#include<bits/stdc++.h>
#define MOD ((int)1e9 + 7)
#define N ((int)2e6 + 7)
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"
#define ll long long


using namespace std;



/*fast io
ios_base::sync_with_stdio(false);
cin.tie(NULL);
*/

ll len[55];

int recur(int cur , ll pos)
{
    ll mid = len[cur]/2 + 1;
    if(pos == mid) return cur;
    if(pos<mid) return recur(cur-1,pos);
    else return recur(cur-1,pos-mid);
}


int main()
{
    fastio;
    int n;
    ll k;
    cin>>n>>k;
    len[1] = 1;
    for(int i = 2 ; i<=n ; i++) len[i] = len[i-1]*2 + 1;
    cout<<recur(n,k)<<endl;
    return 0;
}
