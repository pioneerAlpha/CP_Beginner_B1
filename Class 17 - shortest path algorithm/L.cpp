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


using namespace std;


ll dis[N];

vector < pair < int , int > > vec[N];

bool vis[N];

void dijkstra(int src, int n)
{
    for(int i = 1 ; i<=n ; i++){
        dis[i] = MAXL;
        vis[i] = 0;
    }
    dis[src] = 0;
    priority_queue < pair < ll , int > > prq; /// { dis , node }

    prq.push({0,src});


    while(!prq.empty()){
        pair < ll , int > p = prq.top();
        prq.pop();
        int a = p.second;

        if(vis[a] == 1) continue;

        vis[a] = 1;

        for(int i = 0 ; i<vec[a].size() ; i++){
            int b = vec[a][i].first, c = vec[a][i].second;
            ll val = dis[a] + c;
            if(dis[b] > val){
                dis[b] = val;
                prq.push({-dis[b],b});
            }
        }
    }
}

bool mark[N];


int main()
{
    fastio;
    int n , m ,  k , p;
    ll tot;

    cin>>n>>m>>tot>>k>>p;
    tot *= 60;
    while(p--){
        int a;
        cin>>a;
        mark[a] = 1;
    }
    while(m--){
        int a, b , c;
        cin>>a>>b>>c;
        c = c*60;
        if(mark[b] == 1) c += k;
        vec[a].push_back({b,c});
    }
    dijkstra(1,n);
    if(dis[n] > tot) cout<<"-1\n";
    else cout<<dis[n]<<endl;
    return 0;
}
