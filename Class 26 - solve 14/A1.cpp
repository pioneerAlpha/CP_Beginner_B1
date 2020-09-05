#include<bits/stdc++.h>
#define ll long long
#define N ((int)1e4 + 5)
#define MOD ((int)1e8 + 7)
#define MAX ((int)1e9 + 7)
#define MAXL ((ll)1e18 + 7)
#define MAXP ((int)1e6 + 7)
#define thr 1e-8
#define pi acos(-1)  /// pi = acos ( -1 )
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"

using namespace std;

///sieve of eratosthenes
int status[(MAXP/32)+2];  /// MAXP = maximum prime
vector < int > prime;
bool Check(int n,int pos){
    return (bool)(n & (1<<pos));
}
int Set(int n,int pos){
    return (n | (1<<pos));
}
void sieve(int n){
     for(int i = 3; i*i <= n; i += 2){
		 if( Check(status[i>>5],i&31)==0){
	 		 for(int j = i*i; j <= n; j += (i<<1) ){
				 status[j>>5]=Set(status[j>>5],j & 31);
	 		 }
		 }
	 }
	 prime.push_back(2);
	 for(int i=3;i<=n;i+=2) if( Check(status[i>>5],i&31)==0) prime.push_back(i);
}

vector < pair < int , int > > vec[N];

ll dis[105][N];
bool vis[105][N];

vector < int > DIV[MAXP];

int opp(int w)
{
    if(DIV[w].size() == 2 && w == DIV[w][0]*DIV[w][1]) return w/DIV[w][0] + 2*DIV[w][0];
    return w/DIV[w].back() + 2*DIV[w].back();
}

void dijkstra(int src , int k , int n)
{
    for(int i = 0 ; i<=k ; i++){
        for(int j = 1 ; j<=n ; j++){
            dis[i][j] = MAXL;
            vis[i][j] = 0;
        }
    }
    dis[k][src] = 0;
    priority_queue < pair < int , pair < int , int > > > pqq;
    pqq.push({0,{k,src}});
    while(!pqq.empty()){
        pair < int , pair < int , int > > p = pqq.top();
        pqq.pop();
        int rem = p.second.first, cur = p.second.second;
        if(vis[rem][cur]) continue;
        for(auto p:vec[cur]){
            int a = p.first, w = p.second;
            ll val = dis[rem][cur] + w;
            if(val < dis[rem][a]){
                dis[rem][a] = val;
                pqq.push({-val,{rem,a}});
            }
            if(rem > 0){
                w = opp(w);
                val = dis[rem][cur] + w;
                if(val < dis[rem-1][a]){
                    dis[rem-1][a] = val;
                    pqq.push({-val,{rem-1,a}});
                }
            }
        }
    }
}

int main()
{
    sieve(1e6);
    for(int p:prime){
        for(int i = p ; i <= (int)1e6 ; i += p) DIV[i].push_back(p);
    }
    fastio;
    int t;
    cin>>t;
    while(t--){
        int n , m , k;
        cin>>n>>m>>k;
        for(int i = 1 ; i<=n ; i++) vec[i].clear();
        while(m--){
            int a , b , w;
            cin>>a>>b>>w;
            vec[b].push_back({a,w});
            vec[a].push_back({b,w});
        }
        int src , des;
        cin>>src>>des;
        dijkstra(src,k,n);
        ll ans = MAXL;
        for(int i = 0 ; i<=k ; i++) ans = min(ans , dis[i][des]);
        if(ans == MAXL) ans = -1;
        cout<<ans<<endl;
    }
    return 0;
}
