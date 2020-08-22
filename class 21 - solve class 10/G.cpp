#include<bits/stdc++.h>
#define ll long long
#define N ((int)3e4 + 5)
#define MOD ((int)1e9 + 7)
#define MAX ((int)1e9 + 7)
#define MAXL ((ll)1e18 + 7)
#define MAXP ((int)1e3 + 7)
#define thr 1e-8
#define pi acos(-1)  /// pi = acos ( -1 )
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"

using namespace std;


vector < pair < int , int > > vec[N];

int dis[2][N];

pair < int , int > dfs(int n , int par , int idx)
{
    pair < int , int > ans = {dis[idx][n],n};
    for(auto p:vec[n]){
        int a = p.first;
        if(a != par){
            dis[idx][a] = dis[idx][n] + p.second;
            pair < int , int > tmp = dfs(a,n,idx);
            if(tmp.first > ans.first) ans = tmp;
        }
    }
    return ans;
}

int main()
{
    int t , caseno = 1;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i = 0 ; i<n ; i++) vec[i].clear();
        for(int i = 1 ; i<n ; i++){
            int a, b , c;
            cin>>a>>b>>c;
            vec[b].push_back({a,c});
            vec[a].push_back({b,c});
        }

        dis[0][0] = 0;
        pair < int , int > tmp = dfs(0,-1,0);
        int a = tmp.second;
        dis[0][a] = 0;
        tmp = dfs(a,-1,0);
        int b = tmp.second;
        dis[1][b] = 0;
        dfs(b,-1,1);
        cout<<"Case "<<caseno++<<":\n";
        for(int i = 0 ; i<n ; i++) cout<<max(dis[0][i],dis[1][i])<<endl;
    }
    return 0;
}
