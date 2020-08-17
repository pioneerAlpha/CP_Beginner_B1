#include<bits/stdc++.h>
#define ll long long
#define N ((int)5e5 + 5)
#define MOD ((int)1e9 + 7)
#define MAX ((int)1e9 + 7)
#define MAXL ((ll)1e18 + 7)
#define MAXP ((int)1e3 + 7)
#define thr 1e-8
#define pi acos(-1)  /// pi = acos ( -1 )
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"


using namespace std;

int dis[N];

bool vis[N];

vector < pair < int,int > > vec[N];

void dijkstra(int src, int n)
{
    for(int i = 0 ; i<n ; i++){
        dis[i] = MAX;
        vis[i] = 0;
    }
    dis[src] = 0;
    priority_queue < pair < int , int > > pqq;
    pqq.push({0,src});
    while(!pqq.empty()){
        pair < int , int > p = pqq.top();
        pqq.pop();
        int cur = p.second;
        if(vis[cur] == 1) continue;
        vis[cur] = 1;
        for(auto p:vec[cur])
        {
            int b = p.first;
            int val = dis[cur] + p.second;
            if(dis[b] > val){
                dis[b] = val;
                pqq.push({-val,b});
            }
        }
    }
}

int main()
{
    fastio;
    int n , m , q;
    cin>>n>>m>>q;
    while(m--){
        int u , v , w;
        cin>>u>>v>>w;
        vec[u].push_back({v,w});
        vec[v].push_back({u,w});
    }

    while(q--){
        int src;
        cin>>src;
        dijkstra(src,n);
        int ans = 0 , cnt = 0;
        for(int i = 0 ; i<n ; i++){
            if(dis[i] == MAX) continue; /// i is not reachable from src
            if(ans < dis[i]){
                ans = dis[i];
                cnt = 1;
            }
            else if(ans == dis[i]) cnt++;
        }
        cout<<ans<<" "<<cnt<<endl;
    }

    return 0;
}
