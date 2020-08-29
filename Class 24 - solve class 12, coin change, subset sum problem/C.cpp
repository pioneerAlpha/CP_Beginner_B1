#include<bits/stdc++.h>
#define ll long long
#define N ((int)1e4 + 5)
#define MOD ((int)1e9 + 7)
#define MAX ((int)1e9 + 7)
#define MAXL ((ll)1e18 + 7)
#define MAXP ((int)1e3 + 7)
#define thr 1e-8
#define pi acos(-1)  /// pi = acos ( -1 )
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"

using namespace std;

vector < pair < int , int > > vec[2][N];

int dis[12][N];

bool vis[12][N];

void dijkstra(int src , int n , int d)
{
    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<=d ; j++){
            vis[j][i] = 0;
            dis[j][i] = MAX;
        }
    }
    priority_queue < pair < int , pair < int , int > > > pqq;
    dis[d][src] = 0;
    pqq.push({0,{src,d}});
    while(!pqq.empty()){
        pair < int , pair < int , int > > p = pqq.top();
        pqq.pop();
        int nod = p.second.first , k = p.second.second;
        if(vis[k][nod] == 1) continue;
        vis[k][nod] = 1;
        for(auto p:vec[0][nod]){
            int a = p.first , c = p.second;
            int val = dis[k][nod] + c;
            if(val < dis[k][a]){
                dis[k][a] = val;
                pqq.push({-val,{a,k}});
            }
        }
        if(k == 0) continue;
        for(auto p:vec[1][nod]){
            int a = p.first , c = p.second;
            int val = dis[k][nod] + c;
            if(val < dis[k-1][a]){
                dis[k-1][a] = val;
                pqq.push({-val,{a,k-1}});
            }
        }
    }
}

int main()
{
    fastio;
    int t , caseno = 1;
    cin>>t;
    while(t--){
        int n , m , k , d;
        cin>>n>>m>>k>>d;
        for(int i = 0 ; i<n ; i++){
            vec[0][i].clear();
            vec[1][i].clear();
        }
        while(m--){
            int a , b , c;
            cin>>a>>b>>c;
            vec[0][a].push_back({b,c});
        }
        while(k--){
            int a , b , c;
            cin>>a>>b>>c;
            vec[1][a].push_back({b,c});
        }
        dijkstra(0,n,d);
        int ans = MAX;
        for(int i = 0 ; i<=d ; i++) ans = min(ans , dis[i][n-1]);
        cout<<"Case "<<caseno++<<": ";
        if(ans != MAX) cout<<ans<<endl;
        else cout<<"Impossible\n";
    }
    return 0;
}
