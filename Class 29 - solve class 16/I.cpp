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

int dpp[2+(1<<16)] , too[17];

bool okk[2+(1<<16)];

int call(int mask)
{
    if(mask == 0) return 0;
    if(dpp[mask] != -1) return dpp[mask];
    int ans = 0;
    for(int sub = mask ; sub>0 ; sub = (sub-1)&mask)
    {
        if(okk[sub] == 1) ans = max(ans , call(mask^sub) + 1);
    }
    return dpp[mask] = ans;
}

bool vis[17];

int main()
{
    fastio;

    int caseno = 1;
    while(1){
        int n;
        cin>>n;
        if(n == 0) break;
        memset(too,0,sizeof too);
        for(int i = 0 ; i<n ; i++){
            int m;
            cin>>m;
            while(m--){
                int a;
                cin>>a;  /// the edges are not necessarily bi-directional :p
                too[i] |= 1<<a;  /// consider the node a as a-th bit. too[i] = stores the mask of its neighboring nodes
            }
        }
        for(int mask = 0 ; mask<(1<<n); mask++){
            int tmp = 0;  /// it will store all the nodes in the mask and their neighboring nodes
            for(int i = 0 ; i<n ; i++){
                if((mask&(1<<i)) != 0){
                    tmp |= 1<<i;
                    tmp |= too[i];  /// if node i is in the mask then we will take the node i and all its neighboring nodes
                }
            }
            if(tmp == (1<<n)-1){
                okk[mask] = 1;  /// that means the nodes in the mask cover all the nodes
                /// if we put a particular virus in the nodes of this mask all the nodes will be infected
            }
            else okk[mask] = 0;
        }
        memset(dpp,-1,sizeof dpp);
        cout<<"Case "<<caseno++<<": "<<call((1<<n)-1)<<endl;
    }
    return 0;
}
